namespace GOTHIC_NAMESPACE
{
	// G1:	0x00476A20 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G2A:	0x0047DDC0 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	auto Hook_oCMenu_Status_InitForDisplay = Union::CreateHook(reinterpret_cast<void*>(zSwitch(0x00476A20, 0x0047DDC0)), &oCMenu_Status::Hook_InitForDisplay);
	void __thiscall oCMenu_Status::Hook_InitForDisplay(void)
	{
		static Utils::Logger* log = Utils::CreateLogger("DSP::Hooks::oCMenu_Status_InitForDisplay");

		(this->*Hook_oCMenu_Status_InitForDisplay)();

		int index = parser->GetIndex("MENU_STATUS_API");

		if (index <= 0)
			log->Warning("`Menu_Status_API` function not found.");
		else
			parser->CallFunc(index);
	}
}