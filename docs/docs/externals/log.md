# Log functions

## Log_GetMissionStatus

Returns the status of diary topic. Works only for missions, not for notes.

- `0` - Free
- `1` - Running
- `2` - Success
- `3` - Failure
- `4` - Obsolete

```dae
func int Log_GetMissionStatus(var string topic) {};
```

- `topic` - name of the mission topic
- `return` - topic status

```dae title="Example usage"
if (Log_GetMissionStatus(TOPIC_InnosEye) == LOG_SUCCESS)
{
    //...
};
```
