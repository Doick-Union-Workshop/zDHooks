namespace GOTHIC_NAMESPACE
{
    static void Menu_SetItemText(const zSTRING& t_name, const zSTRING& t_text, const int t_line, const int t_drawNow)
    {
        if (t_name.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Menu_SetItemText");

        zSTRING name = zSTRING(t_name).Upper();
        zCMenuItem* menuItem = zCMenuItem::GetByName(name);

        if (!menuItem)
        {
            log->Error("Invalid Menu Item: {0}", name.ToChar());
            return;
        }

        menuItem->SetText(t_text, t_line, t_drawNow);
#if ENGINE > Engine_G1A
        menuItem->Release();
#else
        delete menuItem;
#endif
    }

    static zSTRING Menu_GetItemText(const zSTRING& t_name, const int t_line)
    {
        if (t_name.IsEmpty())
            return zSTRING{};

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Menu_GetItemText");

        zSTRING name = zSTRING(t_name).Upper();
        zCMenuItem* menuItem = zCMenuItem::GetByName(name);

        if (!menuItem)
        {
            log->Error("Invalid Menu Item: {0}", name.ToChar());
            return zSTRING{};
        }

        zSTRING result = menuItem->GetText(t_line);

        if (result.IsEmpty())
        {
            log->Warning("Menu item '{0}' has no value at {1} text line.", name.ToChar(), t_line);
        }

#if ENGINE > Engine_G1A
        menuItem->Release();
#else
        delete menuItem;
#endif
        return result;
    }

    // For menu parser
    static int Menu_SetItemText_Old()
    {
        auto const par = zCParser::GetParser();
        zSTRING menuItemName, menuItemText;
		int line, drawNow;
        par->GetParameter(drawNow);
        par->GetParameter(line);
        par->GetParameter(menuItemText);
        par->GetParameter(menuItemName);

        menuItemName.Upper();
        zCMenuItem* menuItem = zCMenuItem::GetByName(menuItemName);

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Menu_SetItemText_Old");

        if (!menuItem)
        {
            log->Error("Invalid Menu Item: {0}", menuItemName.ToChar());
            return 0;
        }

        menuItem->SetText(menuItemText, line, drawNow);
#if ENGINE == Engine_G2A
        menuItem->Release();
#else
        menuItem = NULL;
#endif
        return 0;
    }

    static int Menu_GetItemText_Old()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();
        zSTRING menuItemName;
        int line;
        par->GetParameter(line);
        par->GetParameter(menuItemName);
        menuItemName = menuItemName.Upper();
        zCMenuItem* menuItem = zCMenuItem::GetByName(menuItemName);

        static Utils::Logger* log = Utils::CreateLogger("zDExternals::Menu_GetItemText_Old");

        if (!menuItem)
        {
            log->Error("Invalid Menu Item: {0}", menuItemName.ToChar());
            par->SetReturn((zSTRING&)result);
            return 0;
        }

        result = (zSTRING&)menuItem->GetText(line);

        if (result.IsEmpty())
        {
            log->Warning("Menu item '{0}' has no value at {1} text line.", menuItemName.ToChar(), line);
        }

#if ENGINE == Engine_G2A
        menuItem->Release();
#else
        menuItem = NULL;
#endif
        par->SetReturn(result);
        return 0;
    }
}