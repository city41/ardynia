#ifndef gameScene_h
#define gameScene_h

#include <Arduboy2.h>
#include "renderer.h"
#include "overworld.h"
#include "dungeons.h"
#include "bitmaps.h"
#include "tileRoom.h"
#include "inGameMenu.h"
#include "hud.h"
#include "player.h"
#include "entity.h"

const uint8_t MAX_ENTITIES = 8;

class GameScene {
    typedef void (GameScene::*UpdatePtr)(uint8_t);
    typedef void (GameScene::*RenderPtr)(uint8_t);

    private:
        Arduboy2* arduboy;
        Renderer* renderer;
        Player player;
        Entity entities[MAX_ENTITIES];
        const uint8_t* map;
        const uint8_t*** entityDefs;
        int8_t numEntitiesInCurrentRoom;
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

        bool paused;

        void detectTileCollisions(void);
        void detectEntityCollisions(void);
        void goToNextRoom(int16_t playerX, int16_t playerY);
        void setEntitiesInRoom(uint8_t roomX, uint8_t roomy);

        void updatePlay(uint8_t frame);
        void renderPlay(uint8_t frame);

        void updateRoomTransition(uint8_t frame);
        void renderRoomTransition(uint8_t frame);

        void updateMenu(uint8_t frame);
        void renderMenu(uint8_t frame);

        void push(UpdatePtr newUpdate, RenderPtr newRender);
        void pop();

    public:
        GameScene(Arduboy2* arduboy, Renderer* renderer):
            arduboy(arduboy),
            renderer(renderer),
            player(6, 16, 3, 3),
            map(overworld_map),
            entityDefs(overworld_entities),
            numEntitiesInCurrentRoom(0),
            tiles(overworld_tiles),
            nextRoomX(1),
            nextRoomY(0),
            tileRoom(map, tiles, 1, 0),
            menu(),
            roomTransitionCount(0),
            prevUpdate(NULL),
            currentUpdate(&GameScene::updatePlay),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&GameScene::renderPlay),
            nextRender(NULL),
            paused(false)
        {
            setEntitiesInRoom(1, 0);
        }

        void update(uint8_t frame);
        void render(uint8_t frame);
};

#endif

