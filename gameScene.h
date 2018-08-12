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
        uint8_t nextRoomIndex;
        TileRoom* tileRoom;
        TileRoom* nextRoom;

        int16_t horizontalRoomTransitionCount;
        int16_t verticalRoomTransitionCount;

        void detectTileCollisions(void);
        void goToNextRoom(int16_t x, int16_t y);
        void renderVerticalRoomTransition(uint8_t frame);
        void renderHorizontalRoomTransition(uint8_t frame);

    public:
        GameScene(Arduboy2* arduboy, Renderer* renderer):
            BaseScene(arduboy, renderer),
            player(64, 32),
            map(overworldMap),
            currentRoomIndex(1),
            nextRoomIndex(0),
            horizontalRoomTransitionCount(0),
            verticalRoomTransitionCount(0)
        {
            tileRoom = new TileRoom(map[currentRoomIndex].roomDef);
        }

        Scene update(byte frame);
        void render(byte frame);
};

#endif

