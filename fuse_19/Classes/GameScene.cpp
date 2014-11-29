//
//  GameScene.cpp
//  fuse_19
//
//  Created by Akira on 2014/11/29.
//
//

#include "GameScene.h"

bool GameLayer::init()
{
    if (Layer::init()) {
        return false;
    }
    
    return true;
}

bool GameScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    
    return true;
}