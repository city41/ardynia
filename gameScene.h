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

const uint8_t MAX_ENTITIES = 10;

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
        const uint8_t* doorDefs;
        const uint8_t* bumperDefs;

        const uint8_t* tiles;
        uint8_t nextRoomX;
        uint8_t nextRoomY;
        TileRoom tileRoom;
        InGameMenu menu;

        uint8_t roomTransitionCount;
        uint8_t mapWidthInRooms;
        uint8_t mapHeightInRooms;

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        boolean paused;

        boolean playerLeftMap(void);
        void detectEntityCollisions(void);
        void goToNextRoom(int16_t playerX, int16_t playerY);
        void setEntitiesInRoom(uint8_t roomX, uint8_t roomy);
        void spawnNewEntity(EntityType, BaseEntity& spawner);

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
            player(6, 16, 2, 3),
            map(overworld_map),
            entityDefs(overworld_entities),
            doorDefs(overworld_doors),
            bumperDefs(overworld_bumpers),
            tiles(overworld_tiles),
            nextRoomX(0),
            nextRoomY(0),
            tileRoom(map, tiles, 0, 0),
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
            setEntitiesInRoom(0, 0);
        }

        void update(uint8_t frame);
        void render(uint8_t frame);
};

#endif

