# NPC - character functions

## Npc_GetRoutineFuncName

Returns the function name of the NPC's current routine (e.g. `RTN_PRESTART_100`).

```dae
func string Npc_GetRoutineFuncName(var C_NPC npc) {};
```

- `npc` - NPC
- `return` - function name of the NPC's current routine

```dae title="Example usage"
if (Hlp_StrCmp(Npc_GetRoutineFuncName(self), "RTN_PreStart_100"))
{
    //...
};
```

## Npc_GetRoutineName

Returns the name of the NPC's current routine (e.g. `PRESTART`).

```dae
func string Npc_GetRoutineName(var C_NPC npc) {};
```

- `npc` - NPC
- `return` - name of the NPC's current routine

```dae title="Example usage"
if (Hlp_StrCmp(Npc_GetRoutineName(self), "PreStart"))
{
    //...
};
```

## Npc_EquipItem

Equips or unequips the specified item on the NPC.

```dae
func void Npc_EquipItem(var C_NPC npc, var int itemInstance) {};
```

- `npc` - NPC
- `itemInstance` - instance name of the item

```dae title="Example usage"
Npc_EquipItem(self, ItLsTorch);
```

## Npc_GetWalkMode

Returns the current walk mode of the NPC.

```dae
func int Npc_GetWalkMode(var C_NPC npc) {};
```

- `npc` - NPC
- `return` - integer value of walk mode

```dae title="Example usage"
if (Npc_GetWalkMode(self) == NPC_SNEAK)
{
    //...
};
```

## Npc_IsStanding

Checks if the NPC is currently standing still.

```dae
func int Npc_IsStanding(var C_NPC npc) {};
```

- `npc` - NPC
- `return` - `TRUE` if NPC is standing, `FALSE` otherwise

```dae title="Example usage"
if (Npc_IsStanding(self))
{
    //...
};
```

## Npc_IsWalking

Checks if the NPC is currently walking.

```dae
func int Npc_IsWalking(var C_NPC npc) {};
```

- `npc` - NPC
- `return` - `TRUE` if NPC is walking, `FALSE` otherwise

```dae title="Example usage"
if (Npc_IsWalking(self))
{
    //...
};
```

## Npc_HasOverlay

Checks if the NPC has the specified animation overlay active.

```dae
func int Npc_HasOverlay(var C_NPC npc, var string overlay) {};
```

- `npc` - NPC
- `return` - `TRUE` if NPC has overlay with specified name, `FALSE` otherwise

```dae title="Example usage"
if (Npc_HasOverlay(self, "Humans_Tired.mds"))
{
    //...
};
```

## Npc_HasTimedOverlay

Checks if the NPC has the specified timed animation overlay active.

```dae
func int Npc_HasTimedOverlay(var C_NPC npc, var string overlay) {};
```

- `npc` - NPC
- `return` - `TRUE` if NPC has overlay with specified name, `FALSE` otherwise

```dae title="Example usage"
if (Npc_HasTimedOverlay(self, "Humans_Sprint.mds"))
{
    //...
};
```

## Npc_OpenDeadNpcInventory

Opens NPC's plunder inventory.

```dae
func void Npc_OpenDeadNpcInventory(var C_NPC npc) {};
```

- `npc` - NPC

```dae title="Example usage"
Npc_OpenDeadNpcInventory(self);
```

## Npc_CloseInventory

Closes NPC's main inventory.

```dae
func void Npc_CloseInventory(var C_NPC npc) {};
```

- `npc` - NPC

```dae title="Example usage"
Npc_CloseInventory(self);
```

## Npc_CloseInventorySteal

Closes the steal inventory of `npc`'s focus NPC.

```dae
func void Npc_CloseInventorySteal(var C_NPC npc) {};
```

- `npc` - NPC

```dae title="Example usage"
Npc_CloseInventorySteal(self);
```

## Npc_CloseDeadNpcInventory

Closes NPC's plunder inventory.

```dae
func void Npc_CloseDeadNpcInventory(var C_NPC npc) {};
```

- `npc` - NPC

```dae title="Example usage"
Npc_CloseDeadNpcInventory(self);
```
