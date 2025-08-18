namespace GOTHIC_NAMESPACE
{
#if ENGINE == Engine_G2A
    // G2A: 0x0068B840 protected: int __fastcall oCViewDialogTrade::OnTransferLeft(short)
    auto Hook_oCViewDialogTrade_OnTransferLeft = Union::CreateHook(reinterpret_cast<int*>(zSwitch(0, 0x0068B840)), &oCViewDialogTrade::Hook_OnTransferLeft);
    int __fastcall oCViewDialogTrade::Hook_OnTransferLeft(short t_amount)
    {
        static Utils::Logger* log = Utils::CreateLogger("DSP::Hooks::oCViewDialogTrade_OnTransferLeft");
        oCItem* pItemChosen = NULL;

        switch (this->SectionTrade)
        {
            case TRADE_SECTION_RIGHT_INVENTORY:
            {
                IncTransferCount(t_amount);
                oCItem* item = this->DlgInventoryPlayer->GetSelectedItem();

                if (!item)
                {
                    log->Info("No item selected in the player's inventory.");
                    return 1;
                }

                if (item->amount <= t_amount)
                {
                    t_amount = item->amount;
                    SetTransferCount(0);
                }

                if (item->GetInstanceName() == oCItemContainer::GetCurrencyInstanceName())
                {
                    log->Info("Player cannot sell item `{0}`, because it's currency item.", item->GetInstanceName());
                    return 1;
                }

                int conditionFunc = parser->GetIndex("C_PLAYERCANSELLITEM");
                int canPlayerSellItem = 1;

                if (conditionFunc <= 0) {
                    log->Warning("`C_PlayerCanSellItem` function not found.");
                }
                else
                {
                    parser->SetInstance("ITEM", item);
                    parser->SetInstance("SELF", this);
                    canPlayerSellItem = *(int*)parser->CallFunc(conditionFunc);
                }

                if (!canPlayerSellItem)
                {
                    log->Info("Player cannot sell item: {0}", item->GetInstanceName());
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
            }

            break;
        }

        return 1;
    }
#endif
}