#ifndef gameScene_h
#define gameScene_h

#include "baseScene.h"
#include "scenes.h"

#include "player.h"
#include "overworldMap.h"
#include "tileRoom.h"

class GameScene: public BaseScene {
    private:
        Player player;
        const MapRoomDef* map;
        uint8_t currentRoomIndex;
        TileRoom* tileRoom;

        void detectTileCollisions(void);
        void goToNextRoom(int16_t x, int16_t y);

    public:
        GameScene(Arduboy2* arduboy, Renderer* renderer):
            BaseScene(arduboy, renderer),
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

