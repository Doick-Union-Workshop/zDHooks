namespace GOTHIC_NAMESPACE
{
	static int Log_GetMissionStatus(const zSTRING& t_topicName)
	{
		auto list = oCLogManager::GetLogManager().m_lstTopics.GetNextInList();

		while (list)
		{
			auto const log = list->GetData();

			if (log->m_strDescription == t_topicName) {
				return static_cast<int>(log->m_enuStatus);
			}

			list = list->GetNextInList();
		}

		return static_cast<int>(oCLogTopic::zELogTopicStatus_Free);
	}
}