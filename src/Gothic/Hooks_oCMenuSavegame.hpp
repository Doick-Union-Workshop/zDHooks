namespace GOTHIC_NAMESPACE
{
	// G1:	0x0042C420 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G2A:	0x0042E940 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	auto Hook_oCMenuSavegame_HandleSlotChange = Union::CreateHook(reinterpret_cast<void*>(zSwitch(0x0042C420, 0x0042E940)), &oCMenuSavegame::Hook_HandleSlotChange);
	void __thiscall oCMenuSavegame::Hook_HandleSlotChange(int t_key)
	{
		static Utils::Logger* log = Utils::CreateLogger("zDHooks::oCMenuSavegame_HandleSlotChange");

		(this->*Hook_oCMenuSavegame_HandleSlotChange)(t_key);

		int index = parserMenu->GetIndex("MENU_SAVEGAME_API");

		if (index <= 0)
			log->Warning("Function 'Menu_SaveGame_API' not found.");
		else
			parser->CallFunc(index);
	}
}