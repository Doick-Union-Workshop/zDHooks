namespace GOTHIC_NAMESPACE
{
	static zSTRING Npc_GetRoutineFuncName(oCNpc* t_npc)
	{
		if (!t_npc) return zSTRING{};

		zSTRING routine = t_npc->state.GetRoutineName();

		if (routine.Search("RTN_", 0) != 0) // StartsWith with "RTN_"
			return zSTRING{};
		return routine;
	}

	static zSTRING Npc_GetRoutineName(oCNpc* t_npc)
	{
		if (!t_npc) return zSTRING{};

		zSTRING routine = Npc_GetRoutineFuncName(t_npc);
		zSTRING prefix = "RTN_";
		zSTRING suffix = "_" + zSTRING(t_npc->idx);

		if (routine.Search(prefix, 0) == 0) // StartsWith with specified prefix
			routine.Delete(0, prefix.Length());

		int rtnLen = routine.Length();
		int suffixPos = rtnLen - suffix.Length();

		if (routine.Search(suffix, suffixPos) == suffixPos) // EndsWith with specified suffix
			routine.Delete(suffixPos, rtnLen);

		return routine;
	}

	static void Npc_EquipItem(oCNpc* t_npc, const int t_instance)
	{
		if (!t_npc || !t_instance)
			return;

		auto par = zCParser::GetParser();
		zCPar_Symbol* sym = par->GetSymbol(t_instance);
		oCItem* item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());

		if (!item) return;

		t_npc->Equip(item);
	}

	static int Npc_GetWalkMode(oCNpc* t_npc)
	{
		if (!t_npc) return -1;

		oCAniCtrl_Human* aniCtrl = t_npc->anictrl;
		zSTRING walkmode = aniCtrl->GetWalkModeString();
		walkmode.Upper();

		if (walkmode == "RUN")
			return static_cast<int>(ANI_WALKMODE_RUN);
		else if (walkmode == "WALK")
			return static_cast<int>(ANI_WALKMODE_WALK);
		else if (walkmode == "SNEAK")
			return static_cast<int>(ANI_WALKMODE_SNEAK);
		else if (walkmode.IsEmpty())
			return static_cast<int>(ANI_WALKMODE_WATER);

		return -1;
	}

	static int Npc_IsStanding(oCNpc* t_npc)
	{
		if (!t_npc) return 0;
		return static_cast<int>(t_npc->anictrl->IsStanding());
	}

	static int Npc_IsWalking(oCNpc* t_npc)
	{
		if (!t_npc) return 0;
		return static_cast<int>(t_npc->anictrl->IsWalking());
	}

	static int Npc_HasOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc || t_overlay.IsEmpty())
			return 0;

		zSTRING overlay = zSTRING(t_overlay).Upper();
		return t_npc->activeOverlays.IsInList(overlay);
	}

	static int Npc_HasTimedOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc || t_overlay.IsEmpty())
			return 0;

		zSTRING overlay = zSTRING(t_overlay).Upper();
		auto list = t_npc->timedOverlays.GetNextInList();

		while (list)
		{
			if (list->GetData()->mdsOverlayName.Upper() == overlay)
				return 1;

			list = list->GetNextInList();
		}

		return 0;
	}

	static void Npc_Teleport(oCNpc* t_npc, const zSTRING& t_point)
	{
		if (!t_npc || t_point.IsEmpty()) return;

		zSTRING point = t_point;
		t_npc->BeamTo(point.Upper());
	}

	static void Npc_OpenDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc) return;
		t_npc->OpenDeadNpc();
	}

	static void Npc_CloseInventory(oCNpc* t_npc)
	{
		if (!t_npc) return;
		t_npc->CloseInventory();
	}

	static void Npc_CloseInventorySteal(oCNpc* t_npc)
	{
		if (!t_npc) return;
		t_npc->CloseSteal();
	}

	static void Npc_CloseDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc) return;
		t_npc->CloseDeadNpc();
	}
}