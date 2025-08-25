# MOB - interactive object functions

## Mob_SetFocusName

Sets the focus name of specified oCMOB in the game world.

```dae
func void Mob_SetFocusName(var string mobName, var string focusName) {};
```

- `mobName`
- `focusName`

```dae title="Example usage"
Mob_SetFocusName("CHEST_LOBART", "MOBNAME_CHAIR");
```

## Mob_GetFocusName

Returns focus name of specified oCMOB in the game world.

```dae
func string Mob_GetFocusName(var string mobName) {};
```

- `mobName`
- `return` - focus name of oCMOB

```dae title="Example usage"
var string focusName;
focusName = Mob_GetFocusName("CHEST_LOBART");

if (Hlp_StrCmp(focusName, MOBNAME_CHEST))
{
    //...
};
```
