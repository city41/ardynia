#ifndef gameScene_h
#define gameScene_h

#include <Arduino.h>
#include <Arduboy2.h>

#include "baseScene.h"
#include "scenes.h"

#include "player.h"
#include "overworldMap.h"
#include "tileRoom.h"

class GameScene: public BaseScene {
    private:
        Arduboy2* arduboy;
        Player player;
        const MapRoomDef* map;
        uint8_t currentRoomIndex;
        TileRoom* tileRoom;

        void detectTileCollisions(void);
        void goToNextRoom(int16_t x, int16_t y);

    public:
        GameScene(Arduboy2* arduboy):
            arduboy(arduboy),
            player(64, 32),
            map(overworldMap),
            currentRoomIndex(1)
        {
            tileRoom = new TileRoom(map[currentRoomIndex].roomDef);
        }

        Scene update(byte frame);
        void render(byte frame);
};

#endif

