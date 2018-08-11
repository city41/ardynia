#ifndef gameScene_h
#define gameScene_h

#include <Arduino.h>
#include <Arduboy2.h>

#include "baseScene.h"
#include "scenes.h"

#include "player.h"
#include "tileRoom.h"
#include "rooms.h"

class GameScene: public BaseScene {
    private:
        Arduboy2* arduboy;
        Player player;
        TileRoom room;

    public:
        GameScene(Arduboy2* arduboy):
            arduboy(arduboy),
            player(64, 32),
            room(firstRoom)
        {}

        Scene update(byte frame);
        void render(byte frame);
};

#endif

