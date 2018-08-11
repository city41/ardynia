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
        Scene nextSceneId;
        BaseScene* currentScene;
        byte transitionCount;

        void transitionScene(Scene nextSceneId);
        void updateTransition(byte frame);
        void setScene(Scene nextSceneId);

    public:
        SceneManager(Arduboy2* arduboy, Scene startingSceneId):
            arduboy(arduboy),
            currentSceneId(NO_SCENE),
            nextSceneId(NO_SCENE),
            currentScene(NULL),
            transitionCount(0)
        {
            setScene(startingSceneId);
        }

        void update(byte frame);
};

#endif

