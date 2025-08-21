namespace GOTHIC_NAMESPACE
{
#if ENGINE == Engine_G2A
    static const zSTRING C_PLAYER_CAN_SELL_ITEM = "C_PLAYERCANSELLITEM";

    // G2A: 0x0068B840 protected: int __fastcall oCViewDialogTrade::OnTransferLeft(short)
    auto Hook_oCViewDialogTrade_OnTransferLeft = Union::CreateHook(reinterpret_cast<int*>(zSwitch(0, 0x0068B840)), &oCViewDialogTrade::Hook_OnTransferLeft);
    int __fastcall oCViewDialogTrade::Hook_OnTransferLeft(short t_amount)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDHooks::oCViewDialogTrade::OnTransferLeft");
        oCItem* pItemChosen = NULL;

        if (this->SectionTrade != TRADE_SECTION_RIGHT_INVENTORY)
            return 1;

        IncTransferCount(t_amount);
        oCItem* item = this->DlgInventoryPlayer->GetSelectedItem();

        if (!item)
        {
            log->Error("No item selected in the player's inventory.");
            return 1;
        }

        if (item->amount <= t_amount)
        {
            t_amount = item->amount;
            SetTransferCount(0);
        }

        if (item->GetInstanceName() == oCItemContainer::GetCurrencyInstanceName())
        {
            log->Info("Cannot sell item '{0}', because it's currency item.", item->GetInstanceName().ToChar());
            return 1;
        }

        int conditionFunc = parser->GetIndex(C_PLAYER_CAN_SELL_ITEM);
        int canSellItem = 1;

        if (conditionFunc <= 0) {
            LogDaedalusCallError(log, C_PLAYER_CAN_SELL_ITEM, eCallFuncError::WRONG_SYMBOL, Utils::LoggerLevel::Warn);
        }
        else
        {
            parser->SetInstance("ITEM", item);
            parser->SetInstance("SELF", this->NpcRight); // Player
            parser->SetInstance("OTHER", this->NpcLeft); // Trader
            const auto result = DaedalusCall<int>(parser, DCFunction(C_PLAYER_CAN_SELL_ITEM), {});

            if (result.has_value())
                canSellItem = *result;
            else
                LogDaedalusCallError(log, C_PLAYER_CAN_SELL_ITEM, result.error(), Utils::LoggerLevel::Warn);
        }

        if (!canSellItem)
        {
            log->Info("Cannot sell item: {0}", item->GetInstanceName().ToChar());
            return 1;
        }

        short i;
        for (i = 0; i < t_amount; i++)
        {
            pItemChosen = this->DlgInventoryPlayer->RemoveSelectedItem();

            if (pItemChosen)
            {
                int value = pItemChosen->GetValue();

                if (value > 0)
                {
                    value = zINT(zREAL(value) * this->DlgInventoryNpc->ValueMultiplier);

                    if (value <= 0) value = 1;
                }

                if (value <= 0)
                {
                    this->DlgInventoryNpc->InsertItem(pItemChosen);
                }
                else
                {
                    oCItem* coin = oCItemContainer::CreateCurrencyItem(value);

                    if (!coin)
                    {
                        this->DlgInventoryPlayer->InsertItem(pItemChosen);
                    }
                    else
                    {
                        this->DlgInventoryNpc->InsertItem(pItemChosen);
                        this->DlgInventoryPlayer->InsertItem(coin);
                        coin->Release();
                    }
                }
            }
        }

        return 1;
    }
#endif
}