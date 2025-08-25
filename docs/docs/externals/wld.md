# WLD - world manipulation functions

## Wld_InsertVob

Inserts a vob into the world at the position of a given waypoint, freepoint, or another vob.

```dae
func void Wld_InsertVob(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Wld_InsertVob("SECRET_CHEST", "WP_START");
```

## Wld_InsertMob

Inserts a static interactive object (mob) into the world at a given location.

```dae
func void Wld_InsertMob(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Wld_InsertMob("SIGNPOST", "WP_START");
```

## Wld_InsertMobInter

Inserts an interactive mob (e.g., cauldron, forge) into the world at a given location.

```dae
func void Wld_InsertMobInter(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Wld_InsertMobInter("EDDA_CAULDRON", "WP_START");
```

## Wld_InsertMobContainer

Inserts a container mob (e.g., chest) into the world at a given location.

```dae
func void Wld_InsertMobContainer(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Wld_InsertMobContainer("CAVALORN_CHEST", "WP_START");
```

## Wld_InsertMobFire

Inserts a fire mob (e.g., campfire, torch) into the world at a given location.

```dae
func void Wld_InsertMobFire(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Wld_InsertMobFire("CAVALORN_CAMPFIRE", "WP_START");
```

## Wld_InsertMobDoor

Inserts a door mob into the world at a given location.

```dae
func void Wld_InsertMobDoor(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Wld_InsertMobDoor("BOSPER_HOUSE_DOOR", "NW_CITY_BOSPER_HOUSE_ENTRANCE");
```

## Wld_InsertMobBed

Inserts a bed mob into the world at a given location.

```dae
func void Wld_InsertMobBed(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Wld_InsertMobDoor("BOSPER_BED", "NW_CITY_BOSPER_HOUSE_BED");
```

## Wld_InsertVobPos

Inserts a vob into the world at exact coordinates.

```dae
func void Wld_InsertVobPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(0, 0, 0);
Wld_InsertVobPos("SECRET_CHEST", pos);
```

## Wld_InsertMobPos

Inserts a mob into the world at exact coordinates.

```dae
func void Wld_InsertMobPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(23120, 1400, 16795);
Wld_InsertMobPos("SIGNPOST", pos);
```

## Wld_InsertMobInterPos

Inserts an interactive mob into the world at exact coordinates.

```dae
func void Wld_InsertMobInterPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 1400, 23120);
Wld_InsertMobInterPos("EDDA_CAULDRON", pos);
```

## Wld_InsertMobContainerPos

Inserts a container mob into the world at exact coordinates.

```dae
func void Wld_InsertMobContainerPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 23120, 1400);
Wld_InsertMobContainerPos("CAVALORN_CHEST", pos);
```

## Wld_InsertMobFirePos

Inserts a fire mob into the world at exact coordinates.

```dae
func void Wld_InsertMobFirePos(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 23120, 1400);
Wld_InsertMobFirePos("CAVALORN_CAMPFIRE", pos);
```

## Wld_InsertMobDoorPos

Inserts a door mob into the world at exact coordinates.

```dae
func void Wld_InsertMobDoorPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(1400, 16795, 23120);
Wld_InsertMobDoorPos("BOSPER_HOUSE_DOOR", pos);
```

## Wld_InsertMobBedPos

Inserts a bed mob into the world at exact coordinates.

```dae
func void Wld_InsertMobBedPos(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(1400, 16795, 23120);
Wld_InsertMobBedPos("BOSPER_BED", pos);
```

## Wld_RemoveVob

Removes a specified vob from the game world.

```dae
func int Wld_RemoveVob(var string vobName) {};
```

- `vobName` - name of vob in the game world
- `return` - `TRUE` if the vob has been correctly removed, `FALSE` otherwise

```dae
if (Wld_RemoveVob("CHEST_LOBART"))
{
    Print("Vob successfully removed");
};
```

## Wld_GetPos

Creates and returns a `C_Position` object from the given coordinates or angles.

```dae
func C_Position Wld_GetPos(var int posX, var int posY, vart int posZ) {};
```

- `posX` - position or angle in X axis
- `posY` - position or angle in Y axis
- `posZ` - position or angle in Z axis
- `return` - C_Position

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(0, 180, 0);
```

## Wld_GetPlayerPortalRoom

Returns name of portal room where the player currently is.

```dae
func string Wld_GetPlayerPortalRoom() {};
```

- `return` - name of player's portal room

```dae title="Example usage"
var string playerPortalRoom;
playerPortalRoom = Wld_GetPlayerPortalRoom();

if (Hlp_StrCmp(playerPortalRoom, "hütte2"))
{
    //...
};
```
