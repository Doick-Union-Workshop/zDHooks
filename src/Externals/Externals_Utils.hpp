namespace GOTHIC_NAMESPACE
{
    /*
     *
     * Created by Boguś (bogu9821), 2025
     * Original source: https://gist.github.com/bogu9821/08b938ef9a5a38fab467d5eac3aa3b0d
     *
     */
    template<typename T>
    int _cdecl GetArrayValue()
    {
        const auto par = zCParser::GetParser();

        int index;
        par->GetParameter(index);

        const auto statArray = reinterpret_cast<T*>(par->PopVarAddress());

        par->SetReturn(statArray[index]);

        return {};
    }

    /*
     *
     * Created by Boguś (bogu9821), 2025
     * Original source: https://gist.github.com/bogu9821/08b938ef9a5a38fab467d5eac3aa3b0d
     *
     */
    template<typename T>
    int _cdecl SetArrayValue()
    {
        const auto par = zCParser::GetParser();

        T value;
        par->GetParameter(value);

        int index;
        par->GetParameter(index);

        const auto statArray = reinterpret_cast<T*>(par->PopVarAddress());

        statArray[index] = static_cast<T&&>(value);

        return {};
    }

    /*
     *
     * Created by Boguś (bogu9821), 2025
     * Original source: https://github.com/bogu9821/BetterDaedalusExternals/blob/main/README.md
     *
     */
    static int Ext_RGBA(const int r, const int g, const int b, const int a)
    {
        const zCOLOR color
        {
            static_cast<unsigned char>(r),
            static_cast<unsigned char>(g),
            static_cast<unsigned char>(b),
            static_cast<unsigned char>(a)
        };

        return static_cast<int>(color.dword);
    }
}