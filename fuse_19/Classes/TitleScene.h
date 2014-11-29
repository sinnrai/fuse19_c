//
//  TitleScene.h
//  fuse_19
//
//  Created by Akira on 2014/11/29.
//
//

#ifndef __fuse_19__TitleScene__
#define __fuse_19__TitleScene__

#include <cocos2d.h>
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TitleLayer : public Layer
{
public:
    bool init();
    CREATE_FUNC(TitleLayer);
    
    void onClickStageButton(Ref* pSender, Control::EventType eventType);
};

class TitleScene : public Scene
{
public:
    bool init();
    CREATE_FUNC(TitleScene);
};

#endif /* defined(__fuse_19__TitleScene__) */
