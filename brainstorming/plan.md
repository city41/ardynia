# ArduZel

A Zelda style game for the ArduBoy

## overview

* move up/down/left/right in overhead view
* no scrolling, move about on one screen
* when exit screen, move onto next
* a button -> attack with sword
* b button -> use current item
* hold a+b -> open item menu

### item menu

* lists all items user has vertically
* focus ring on currently selected item
* press up/down -> choose another item
* let go of a+b -> last focused item is new current item

### finite items

items that have finite usages (like potions), once used, automatically
choose a non-finite item. If one does not exist, choose nothing

## Engine needs

* scene management
* tiling
* movement
* attacking with sword
* use item
* move between screens
* sprite animation
* entity management
* message display
    * show message on screen
    * press a to see next message, or close if no more messages
* enemy movement
* enemy attack
* health, both enemy and player
* NPCs
* save/restore to/from eeprom

## chapters

design it so the game can ship in several chapters. each chapter has the engine,
and a starting point for the player. Either a hardcoded starting point, or carry over
from previous chapter via eeprom


