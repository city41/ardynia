#include "sceneManager.h"
#include "titleScene.h"
#include "gameScene.h"

void SceneManager::setScene(Scene nextSceneId) {
    currentSceneId = nextSceneId;

    delete currentScene;
    currentScene = NULL;

    switch (nextSceneId) {
        case NO_SCENE:
            currentScene = NULL;
            break;
        case TITLE:
            currentScene = new TitleScene(arduboy);
            break;
        case GAME:
            currentScene = new GameScene(arduboy);
            break;
    }
}

void SceneManager::transitionScene(Scene ns) {
    nextSceneId = ns;
    transitionCount = 128;
}

void SceneManager::updateTransition(byte frame) {
    transitionCount -= 4;

    if (transitionCount <= 0) {
        setScene(nextSceneId);
    } else {
        currentScene->render(frame);

        for (char i = 127; i >= transitionCount; --i) {
            arduboy->drawFastVLine(i, 0, 64, BLACK);
        }
    }
}

void SceneManager::update(byte frame) {
    if (transitionCount > 0) {
        updateTransition(frame);
    } else if (currentScene != NULL) {
        Scene nextSceneId = currentScene->update(frame);
        currentScene->render(frame);

        if (nextSceneId != currentSceneId) {
            transitionScene(nextSceneId);
        }
    }
}
