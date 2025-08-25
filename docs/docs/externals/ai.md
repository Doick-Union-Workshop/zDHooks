# AI - functions for working with AI

## AI_TurnToWP

Turns an NPC to a specified waypoint in the world.

```dae
func void AI_TurnToWP(var C_NPC npc, var string wp) {};
```

- `npc` - NPC
- `wp` - name of waypoint in the game world

```dae title="Example usage"
AI_TurnToWP(self, "WP_START");
```

## AI_TurnToVob

Turns an NPC to a specified freepoint or vob in the world. It works similarly to `AI_TurnToWP`.

```dae
func void AI_TurnToVob(var C_NPC npc, var string vob) {};
```

- `npc` - NPC
- `vob` - name of freepoint or vob in the game world

```dae title="Example usage"
AI_TurnToVob(self, "CHEST_LOBART");
```
