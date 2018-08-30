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

        const uint8_t*** entityDefs;
        const uint8_t* doorDefs;
        const uint8_t* bumperDefs;

        uint8_t nextRoomX;
        uint8_t nextRoomY;
        InGameMenu menu;

        uint8_t roomTransitionCount;
        uint8_t teleportTransitionCount;
        uint8_t swordWarningCount;
        uint8_t mapWidthInRooms;
        uint8_t mapHeightInRooms;

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        boolean paused;

        __FlashStringHelper* toast;
        uint8_t toastCount;

        boolean playerLeftMap(void);
        void detectEntityCollisions(void);
        void goToNextRoom(int16_t playerX, int16_t playerY);
        void loadEntitiesinRoom(uint8_t roomX, uint8_t roomy);
        void spawnNewEntity(EntityType, BaseEntity& spawner);

        void updatePlay(uint8_t frame);
        void renderPlay(uint8_t frame);

        void updateRoomTransition(uint8_t frame);
        void renderRoomTransition(uint8_t frame);

        void updateTeleportTransition(uint8_t frame);
        void renderTeleportTransition(uint8_t frame);

        void updateGameOver(uint8_t frame);
        void renderGameOver(uint8_t frame);

        void updateMenu(uint8_t frame);
        void renderMenu(uint8_t frame);

        void push(UpdatePtr newUpdate, RenderPtr newRender);
        void pop();

        void loadSave();

    public:
        GameScene(Arduboy2* arduboy, Renderer* renderer):
            arduboy(arduboy),
            renderer(renderer),
            player(WIDTH / 2 - 4, HEIGHT / 2 - 4),
            nextRoomX(1),
            nextRoomY(1),
            menu(),
            roomTransitionCount(0),
            teleportTransitionCount(0),
            swordWarningCount(0),
            prevUpdate(NULL),
            nextUpdate(NULL),
            prevRender(NULL),
            nextRender(NULL),
            paused(false),
            toast(NULL),
            toastCount(0)
        {
            loadSave();

        }

        void update(uint8_t frame);
        void render(uint8_t frame);
};

#endif

