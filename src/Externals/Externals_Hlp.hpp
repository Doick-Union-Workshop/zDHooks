namespace GOTHIC_NAMESPACE
{
    static oCItem* Hlp_GetItem(const int t_instance)
    {
        oCItem* item = nullptr;
        const auto par = zCParser::GetParser();
        zCPar_Symbol* sym = par->GetSymbol(t_instance);

        if (!sym) return item;

        if (sym->type == zPAR_TYPE_INSTANCE)
            item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());

        if (!item)
            item = zDYNAMIC_CAST<oCItem>(ogame->GetGameWorld()->SearchVobByName(sym->name));

        return item;
    }

    static int Hlp_IsValidVob(zCVob* t_vob)
    {
        return static_cast<int>(t_vob != nullptr);
    }
    
    static int Hlp_StrCmp(const zSTRING& t_str1, const zSTRING& t_str2)
    {
        zSTRING str1 = zSTRING(t_str1).Upper();
        zSTRING str2 = zSTRING(t_str2).Upper();
        return static_cast<int>(str1 == str2);
    }

    static oCNpc* Hlp_GetNpcPlunderedByPlayer()
    {
        if (oCNpc::game_mode == NPC_GAME_PLUNDER)
            return stealnpc;
        return nullptr;
    }

    // For menu parser
    static int Hlp_StrCmp_Old()
    {
        zSTRING s1, s2;
        const auto par = zCParser::GetParser();
        par->GetParameter(s2);
        par->GetParameter(s1);
        s1.Upper();
        s2.Upper();
        BOOL result = s1 == s2;
        par->SetReturn(result);
        return 0;
    }
}