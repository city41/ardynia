#ifndef sceneManager_h
#define sceneManager_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "baseScene.h"
#include "scenes.h"
#include "renderer.h"

class SceneManager {
    private:
        Arduboy2* arduboy;
        Renderer* renderer;
        Scene currentSceneId;
        Scene nextSceneId;
        BaseScene* currentScene;
        byte transitionCount;

        void transitionScene(Scene nextSceneId);
        void updateTransition(byte frame);
        void setScene(Scene nextSceneId);

    public:
        SceneManager(Arduboy2* arduboy, Renderer* renderer, Scene startingSceneId):
            arduboy(arduboy),
            renderer(renderer),
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

