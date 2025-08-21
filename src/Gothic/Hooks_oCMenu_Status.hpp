namespace GOTHIC_NAMESPACE
{
	static const zSTRING MENU_STATUS_API = "MENU_STATUS_API";

	// G1:	0x0042C420 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G1A:	0x00480370 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G2:	0x0047C8F0 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G2A:	0x0047DDC0 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	auto Hook_oCMenu_Status_InitForDisplay = Union::CreateHook(
		reinterpret_cast<void*>(zSwitch(0x00476A20, 0x00480370, 0x0047C8F0, 0x0047DDC0)),
		&oCMenu_Status::Hook_InitForDisplay
	);
	void __thiscall oCMenu_Status::Hook_InitForDisplay(void)
	{
		(this->*Hook_oCMenu_Status_InitForDisplay)();

		static Utils::Logger* log = Utils::CreateLogger("zDHooks::oCMenu_Status::InitForDisplay");

		const auto api = DaedalusCall(parser, DCFunction(MENU_STATUS_API), {});

		if (api.has_value())
			log->Info("Successfully called {0}", MENU_STATUS_API.ToChar());
		else
			LogDaedalusCallError(log, MENU_STATUS_API, api.error(), Utils::LoggerLevel::Warn);
	}
}