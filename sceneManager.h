#ifndef sceneManager_h
#define sceneManager_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "baseScene.h"
#include "scenes.h"

class SceneManager {
    private:
        Arduboy2* arduboy;
        Scene currentSceneId;
        BaseScene* currentScene;
        void switchScenes(Scene nextSceneId);

    public:
        SceneManager(Arduboy2* arduboy, Scene startingSceneId):
            arduboy(arduboy),
            currentSceneId(NO_SCENE),
            currentScene(NULL)
        {
            switchScenes(startingSceneId);
        }

        void update(byte frame);
};

#endif

