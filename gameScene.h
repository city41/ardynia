#ifndef gameScene_h
#define gameScene_h

#include "baseScene.h"
#include "scenes.h"

#include "player.h"
#include "overworld.h"
#include "tileRoom.h"
#include "inGameMenu.h"

class GameScene: public BaseScene {
    typedef Scene (GameScene::*UpdatePtr)(uint8_t);
    typedef void (GameScene::*RenderPtr)(uint8_t);

    private:
        Player player;
        const uint8_t* map;
        const uint8_t* tiles;
        uint8_t nextRoomX;
        uint8_t nextRoomY;
        TileRoom tileRoom;
        InGameMenu menu;

        int16_t roomTransitionCount;

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        void detectTileCollisions(void);
        void goToNextRoom(int16_t x, int16_t y);
        void renderVerticalRoomTransition(uint8_t frame);
        void renderHorizontalRoomTransition(uint8_t frame);

        Scene updatePlay(uint8_t frame);
        void renderPlay(uint8_t frame);

        Scene updateRoomTransition(uint8_t frame);
        void renderRoomTransition(uint8_t frame);

        Scene updateMenu(uint8_t frame);
        void renderMenu(uint8_t frame);

        void push(UpdatePtr newUpdate, RenderPtr newRender);
        void pop();

    public:
        GameScene(Arduboy2* arduboy, Renderer* renderer):
            BaseScene(arduboy, renderer),
            player(64, 32),
            map(overworld_map),
            tiles(overworld_tiles),
            nextRoomX(1),
            nextRoomY(0),
            tileRoom(map, tiles, 0, 0),
            menu(),
            roomTransitionCount(0),
            prevUpdate(NULL),
            currentUpdate(&GameScene::updatePlay),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&GameScene::renderPlay),
            nextRender(NULL)
        {
        }

        Scene update(uint8_t frame);
        void render(uint8_t frame);
};

#endif

