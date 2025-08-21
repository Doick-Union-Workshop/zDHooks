namespace GOTHIC_NAMESPACE
{
#if ENGINE == Engine_G2A
    static const zSTRING C_PLAYER_CAN_DROP_ITEM = "C_PLAYERCANDROPITEM";

    // G2A: 0x007538C0 protected: int __thiscall oCNpc::EV_DropVob(class oCMsgManipulate *)
    auto Hook_oCNpc_EV_DropVob = Union::CreateHook(reinterpret_cast<int*>(zSwitch(0, 0x007538C0)), &oCNpc::Hook_EV_DropVob);
    int __thiscall oCNpc::Hook_EV_DropVob(oCMsgManipulate* t_csg)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDHooks::oCNpc::EV_DropVob");
        zCModel* model = GetModel();
        SetBodyState(BS_INVENTORY);

        if (anictrl->IsStateAniActive(anictrl->_s_walk))
        {
            if (t_csg->IsInUse()) return 1;

            oCItem* itm = dynamic_cast<oCItem*>(t_csg->targetVob);

            int conditionFunc = parser->GetIndex(C_PLAYER_CAN_DROP_ITEM);
            int canDropItem = 1;

            if (conditionFunc <= 0) {
                LogDaedalusCallError(log, C_PLAYER_CAN_DROP_ITEM, eCallFuncError::WRONG_SYMBOL, Utils::LoggerLevel::Warn);
            }
            else
            {
                parser->SetInstance("ITEM", itm);
                parser->SetInstance("SELF", this);
                const auto result = DaedalusCall<int>(parser, DCFunction(C_PLAYER_CAN_DROP_ITEM), {});

                if (result.has_value())
                    canDropItem = *result;
                else
                    LogDaedalusCallError(log, C_PLAYER_CAN_DROP_ITEM, result.error(), Utils::LoggerLevel::Warn);
            }

            if (!canDropItem)
            {
                log->Info("Cannot drop item: {0}", itm->GetInstanceName().ToChar());
                return 1;
            }

            model->StartAni("T_STAND_2_IDROP", NULL);
        }
        else if (anictrl->IsStateAniActive(anictrl->s_idrop))
        {
            if (t_csg->targetVob) {
                DoDropVob(t_csg->targetVob);
            }
            else if (!slot.IsEmpty()) {
                RemoveFromSlot(t_csg->npcSlot, 1, 1);
            }
            else if (!t_csg->name.IsEmpty())
            {
                oCItem* item = RemoveFromInv(t_csg->name, 1);
                if (item) DoDropVob(item);
            }

            if (anictrl->t_idrop_2_stand)
            {
                anictrl->SetNextAni(anictrl->t_idrop_2_stand, anictrl->_s_walk);
                model->StartAni(anictrl->t_idrop_2_stand, NULL);
            }
            else {
                model->StartAni(anictrl->_s_walk, NULL);
            }

            t_csg->SetInUse(1);
        }

        return 0;
    }
#endif
}