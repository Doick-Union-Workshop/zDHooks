namespace GOTHIC_NAMESPACE
{
    /*
     *
     * Created by Gratt-5r2, 2022
     * Original source: https://github.com/Gratt-5r2/zParserExtender/blob/master/zParserExtender/InfoMan.cpp
     * Reimplemented because for some reason the original hook does not work.
     *
     */
	// G1:  0x006658A0 public: void __thiscall oCInfo::Info(void)
    // G2A: 0x00703970 public: void __thiscall oCInfo::Info(void)
    auto Hook_oCInfo_Info = Union::CreateHook(reinterpret_cast<void*>(zSwitch(0x006658A0, 0x00703970)), &oCInfo::Hook_Info);
    void oCInfo::Hook_Info(void)
    {
        zCPar_Symbol* symbol1 = parser->GetSymbol("DIA_CURRENTNAME");

        if (symbol1 && symbol1->type == zPAR_TYPE_STRING)
        {
            static zSTRING currentName;
            currentName = name;
            symbol1->SetValue(name, 0);
        }

        zCPar_Symbol* symbol2 = parser->GetSymbol("DIA_CURRENTCOUNTER");

        if (symbol2 && symbol2->type == zPAR_TYPE_INT)
            symbol2->SetValue(0, 0);

        zCPar_Symbol* symbol3 = parser->GetSymbol("DIA_CURRENTINSTANCE");

        if (symbol3 && (symbol3->type == zPAR_TYPE_INT || symbol3->type == zPAR_TYPE_INSTANCE))
            symbol3->SetValue(instance, 0);

        (this->*Hook_oCInfo_Info)();
    }
}