namespace GOTHIC_NAMESPACE
{
	inline constexpr const char* DAEDALUS_CALL_FAILED_MSG = "Failed to call {0}: {1}";

	inline const char* DaedalusCallErrorToString(eCallFuncError t_error)
	{
		switch (t_error)
		{
		case eCallFuncError::WRONG_SYMBOL:    return "Function not found";
		case eCallFuncError::WRONG_ARGS_SIZE: return "Invalid number of arguments";
		case eCallFuncError::WRONG_ARG_TYPE:  return "Invalid argument type";
		case eCallFuncError::WRONG_RET_VAL:   return "Invalid return type";
		default:                              return "Unknown error";
		}
	}

	inline void LogDaedalusCallError(
		Utils::Logger* t_logger,
		const zSTRING& t_funcName,
		eCallFuncError t_error,
		Utils::LoggerLevel t_logLevel = Utils::LoggerLevel::Error)
	{
		switch (t_logLevel)
		{
		case Utils::LoggerLevel::Warn:
			t_logger->Warning(DAEDALUS_CALL_FAILED_MSG, t_funcName.ToChar(), DaedalusCallErrorToString(t_error));
			break;
		case Utils::LoggerLevel::Error:
		default:
			t_logger->Error(DAEDALUS_CALL_FAILED_MSG, t_funcName.ToChar(), DaedalusCallErrorToString(t_error));
			break;
		}
	}
}
