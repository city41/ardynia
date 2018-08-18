#ifndef gameScene_h
#define gameScene_h

#include "baseScene.h"
#include "scenes.h"

#include "player.h"
#include "overworld.h"
#include "tileRoom.h"

class GameScene: public BaseScene {
    private:
        Player player;
        const uint8_t* map;
        const uint8_t* tiles;
        uint8_t nextRoomX;
        uint8_t nextRoomY;
        TileRoom tileRoom;

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
            map(overworld_map),
            tiles(overworld_tiles),
            nextRoomX(1),
            nextRoomY(0),
            tileRoom(map, tiles, 0, 0),
            horizontalRoomTransitionCount(0),
            verticalRoomTransitionCount(0)
        {
        }

        Scene update(byte frame);
        void render(byte frame);
};

#endif

