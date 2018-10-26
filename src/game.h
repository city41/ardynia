#ifndef gameScene_h
#define gameScene_h

#include "overworld.h"
#include "dungeons.h"
#include "tileRoom.h"
#include "inGameMenu.h"
#include "hud.h"
#include "entities/player.h"
#include "entity.h"

const uint8_t MAX_ENTITIES = 8;

const uint8_t OVERWORLD_WIDTH_IN_ROOMS = 7;
const uint8_t OVERWORLD_HEIGHT_IN_ROOMS = 6;
const uint8_t DUNGEONS_WIDTH_IN_ROOMS = 8;

enum ChestState: uint8_t {
    AllChestsOpenCorrectly,
    ChestsOpenCorrectlySoFar,
    ChestsOpenedWrong
};

class Game {
    typedef void (Game::*UpdatePtr)(uint8_t);
    typedef void (Game::*RenderPtr)(uint8_t);

    private:
        uint8_t titleRow;

        Player player;


        const uint8_t* const* const* entityDefs;
        const uint8_t* doorDefs;

        uint8_t nextRoomX;
        uint8_t nextRoomY;
        uint8_t bossDelayCount;
        InGameMenu menu;

        uint8_t roomTransitionCount;
        bool firstRoomTransitionFrame;
        uint8_t teleportTransitionCount;
        uint8_t mapWidthInRooms;

        UpdatePtr prevUpdate;
        UpdatePtr currentUpdate;
        UpdatePtr nextUpdate;

        RenderPtr prevRender;
        RenderPtr currentRender;
        RenderPtr nextRender;

        bool swapRooms;
        bool lastRoomWasLit;
        uint8_t holdACount;
        uint8_t toastCount;
        const uint8_t* toastString;

        void detectEntityCollisions(void);
        void goToNextRoom(int16_t playerX, int8_t playerY);
        void loadEntitiesInRoom(uint8_t roomX, uint8_t roomy, uint8_t tileRoomOffset);
        int8_t spawnNewEntity(EntityType, Entity& spawner);

        void drawToast(void);

        void updateLogo(uint8_t frame);
        void renderLogo(uint8_t frame);

        void updateTitle(uint8_t frame);
        void renderTitle(uint8_t frame);

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

        void loadSave(bool straightToPlay = false);
        bool roomIsLit(void);

    public:
        RoomType roomType;
        Entity entities[MAX_ENTITIES];
        bool isBossRoom;

        void removeAllTriggerDoors(void);
        void emergeAllBridges(uint8_t tileRoomOffset = 255);
        void spawnChest(EntityType containedItem);
        uint8_t countEntities(EntityType entityType);
        ChestState chestOpeningOrderState(void);
        void closeAllChests(void);
        void setAllSwitches(uint8_t triggered);
        bool areAllSwitchesTriggered(void);
        bool areAllTorchesLit(void);
        void toast(const uint8_t* str);

        Game():
            titleRow(0),
            player(WIDTH / 2 - 4, HEIGHT / 2 - 4, this),
            nextRoomX(0),
            nextRoomY(0),
            bossDelayCount(0),
            menu(),
            roomTransitionCount(0),
            firstRoomTransitionFrame(false),
            teleportTransitionCount(0),
            prevUpdate(NULL),
            currentUpdate(&Game::updateLogo),
            nextUpdate(NULL),
            prevRender(NULL),
            currentRender(&Game::renderLogo),
            nextRender(NULL),
            swapRooms(false),
            lastRoomWasLit(true),
            holdACount(0),
            roomType(NORMAL)
        {
        }

        void update(uint8_t frame);
        void render(uint8_t frame);
};

#endif

