# VOB - functions for object manipulation

## Vob_Rotate

Rotates a specified vob to the given world coordinates.

```dae
func void Vob_Rotate(var string vobName, var C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(0, 180, 90);
Vob_Rotate("CHEST_LOBART", pos);
```

## Vob_MoveTo

Moves a specified vob to the position of a given waypoint, freepoint, or another vob.

```dae
func void Vob_MoveTo(var string vobName, var string pointName) {};
```

- `vobName` - name of vob in the game world
- `pointName` - name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
Vob_MoveTo("CHEST_LOBART", "START");
```

## Vob_MoveToPos

Moves a specified vob to the exact coordinates (X, Y, Z) in the game world.

```dae
func void Vob_MoveToPos(var string t_vobName, C_Position vobPosition) {};
```

- `vobName` - name of vob in the game world
- `vobPosition` - coordinates (X, Y, Z) in the game world

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 23120, 1400);
Vob_MoveTo("CHEST_LOBART", pos);
```

## Vob_SetToFloor

Sticks a vob with a specified name to the ground.

```dae
func void Vob_SetToFloor(var string vobName) {};
```

- `vobName` - name of vob in the game world

```dae title="Example usage"
Vob_SetOnFloor("CHEST_LOBART");
```

## Vob_SetVisual

Sets the visual of a specified vob in the game world.

```dae
func void Vob_SetVisual(var string vobName, var string visualName) {};
```

- `vobName` - name of vob in the game world
- `visualName` - name of assets (e.g. 3DS, ASC or MDS)

```dae title="Example usage"
Vob_SetVisual("CHEST_LOBART", "CHESTBIG_OCCHESTLARGELOCKED.MDS");
```

## Vob_SetCollisionDetection

Enables or disables dynamic and static collision detection for a specified vob.

```dae
func void Vob_SetCollisionDetection(var string vobName, var int dynamicCollDet, var int staticCollDet) {};
```

- `vobName` - name of vob in the game world
- `dynamicCollDet`
- `staticCollDet`

```dae title="Example usage"
Vob_SetCollisionDetection("CHEST_LOBART", FALSE, TRUE);
```
