# Hooks API

Some features in the project are customizable and require configuration to work correctly. To support this, DUW plugins provide an API (Application Programming Interface) through special hook functions.  

These hooks allow you to extend or override parts of the game by writing your own script functions in Daedalus, which are executed at specific events (e.g., when opening a menu or selecting a save slot).

!!! info "Engine restrictions"
    Some hooks are only available on specific engines. For example, certain hooks may work **only in Gothic 1** or **only in Gothic 2 Addon (G2A)**. Always check the hook documentation to see which engine it supports. If this information is missing, it means that the hook supports all 4 engines.
