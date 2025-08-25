namespace GOTHIC_NAMESPACE
{
	static zSTRING Str_Upper(const zSTRING& t_str)
	{
		return zSTRING(t_str).Upper();
	}

	static zSTRING Str_Lower(const zSTRING& t_str)
	{
		return zSTRING(t_str).Lower();
	}

	static zSTRING Str_Capitel(const zSTRING& t_str)
	{
		return zSTRING(t_str).UpperFirstLowerRest();
	}
}