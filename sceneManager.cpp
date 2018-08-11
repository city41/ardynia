#include "sceneManager.h"
#include "titleScene.h"
#include "gameScene.h"

void SceneManager::switchScenes(Scene nextSceneId) {
    if (nextSceneId != currentSceneId) {
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
}

void SceneManager::update(byte frame) {
    if (currentScene != NULL) {
        Scene nextSceneId = currentScene->update(frame);
        currentScene->render();

        switchScenes(nextSceneId);
    }
}
