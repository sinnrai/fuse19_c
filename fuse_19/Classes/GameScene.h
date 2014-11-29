//
//  GameScene.h
//  fuse_19
//
//  Created by Akira on 2014/11/29.
//
//

#ifndef __fuse_19__GameScene__
#define __fuse_19__GameScene__

#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class GameLayer : public Layer
{
private:
public:
    bool init();
    CREATE_FUNC(GameLayer);
};

class GameScene : public Scene
{
private:
public:
    bool init();

    CREATE_FUNC(GameScene);
};

#endif /* defined(__fuse_19__GameScene__) */
