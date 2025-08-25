# Selling items by player

!!! info "Engine restrictions"
    It's only available for **Gothic 2 Addon (G2A)**!

This hook is triggered whenever the player tries to **sell an item** to an NPC during a trade.  
It extends the default Gothic 2 Addon trading system by allowing script conditions to decide whether an item can be sold.  

When the player attempts to sell an item, the hook looks for the following Daedalus function: `C_PlayerCanSellItem`.

- `item` - selected item in player's inventory to sell
- `self` - player
- `other` - trader

```dae title="Example usage"
func int C_PlayerCanSellItem()
{
    if (!Hlp_IsValidItem(item)) { return false; };

    if (Hlp_GetInstanceID(item) == ItMi_InnosEye_Mis)
    {
        Print("You cannot sell this unique item!");
        AI_PlayAni(self, "T_NO");
        AI_PlayAni(other, "T_DONTKNOW");
        return false;
    };

    return true;
};
```
