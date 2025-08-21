namespace GOTHIC_NAMESPACE
{
	static const zSTRING MENU_SAVELOADGAME_API = "MENU_SAVELOADGAME_API";

	// G1:	0x0042C420 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G1A:	0x0042F500 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G2:	0x0042E620 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G2A:	0x0042E940 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	auto Hook_oCMenuSavegame_HandleSlotChange = Union::CreateHook(
		reinterpret_cast<void*>(zSwitch(0x0042C420, 0x0042F500, 0x0042E620, 0x0042E940)),
		&oCMenuSavegame::Hook_HandleSlotChange
	);
	void __thiscall oCMenuSavegame::Hook_HandleSlotChange(int t_key)
	{
		(this->*Hook_oCMenuSavegame_HandleSlotChange)(t_key);

		static Utils::Logger* log = Utils::CreateLogger("zDHooks::oCMenuSavegame::HandleSlotChange");

		const auto api = DaedalusCall(parserMenu, DCFunction(MENU_SAVELOADGAME_API), {});

		if (api.has_value())
			log->Info("Successfully called {0} for save slot nr {1}", MENU_SAVELOADGAME_API.ToChar(), t_key);
		else
			LogDaedalusCallError(log, MENU_SAVELOADGAME_API, api.error(), Utils::LoggerLevel::Warn);
	}
}