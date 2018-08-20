#ifndef gameScene_h
#define gameScene_h

#include "baseScene.h"
#include "scenes.h"

#include "overworld.h"
#include "bitmaps.h"
#include "tileRoom.h"
#include "inGameMenu.h"
#include "hud.h"
#include "player.h"
#include "entity.h"

const uint8_t MAX_ENTITIES = 8;

class GameScene: public BaseScene {
    typedef Scene (GameScene::*UpdatePtr)(uint8_t);
    typedef void (GameScene::*RenderPtr)(uint8_t);

    private:
        Player player;
        Entity entities[MAX_ENTITIES];
        const uint8_t* map;
        const uint8_t*** entityDefs;
        uint8_t numEntitiesInCurrentRoom;
        const uint8_t* tiles;
        uint8_t nextRoomX;
        uint8_t nextRoomY;
        TileRoom tileRoom;
        InGameMenu menu;
        Hud hud;

        int16_t roomTransitionCount;

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        bool paused;

        void detectTileCollisions(void);
        void detectEntityCollisions(void);
        void goToNextRoom(int16_t playerX, int16_t playerY);
        void setEntitiesInRoom(uint8_t roomX, uint8_t roomy);
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
            player(64, 16, 5, 5),
            map(overworld_map),
            entityDefs(overworld_entities),
            numEntitiesInCurrentRoom(0),
            tiles(overworld_tiles),
            nextRoomX(0),
            nextRoomY(0),
            tileRoom(map, tiles, 0, 0),
            menu(),
            hud(),
            roomTransitionCount(0),
            prevUpdate(NULL),
            currentUpdate(&GameScene::updatePlay),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&GameScene::renderPlay),
            nextRender(NULL)
        {
            setEntitiesInRoom(0, 0);
        }

        Scene update(uint8_t frame);
        void render(uint8_t frame);
};

#endif

