namespace GOTHIC_NAMESPACE
{
	// G1:	0x00476A20 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G1A:	0x00480370 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G2:	0x0047C8F0 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G2A:	0x0047DDC0 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	auto Hook_oCMenu_Status_InitForDisplay = Union::CreateHook(reinterpret_cast<void*>(zSwitch(0x00476A20, 0x00480370, 0x0047C8F0, 0x0047DDC0)), &oCMenu_Status::Hook_InitForDisplay);
	void __thiscall oCMenu_Status::Hook_InitForDisplay(void)
	{
		static Utils::Logger* log = Utils::CreateLogger("zDHooks::oCMenu_Status::InitForDisplay");

		(this->*Hook_oCMenu_Status_InitForDisplay)();

		int index = parser->GetIndex("MENU_STATUS_API");

		if (index <= 0)
			log->Warning("Function 'Menu_Status_API' not found.");
		else
			parser->CallFunc(index);
	}
}