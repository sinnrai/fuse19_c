//
//  GameScene.h
//  fuse_19
//
//  Created by Akira on 2014/11/29.
//
//

#ifndef __fuse_19__GameScene__
#define __fuse_19__GameScene__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class GameLayer : public Layer
{
private:
    float m_sliderValue[3];
    int m_stageNo;
    Sprite* m_pChara;
    float m_time;
    float m_answer[3];
    bool m_isCleared;
public:
    GameLayer();
    ~GameLayer();
    
    static Layer* create(int stageNo);
    bool init(int stageNo);
    void onExit();
    bool onTouchBegan(Touch *pTouch, Event *pEvent);
    
    void onTouchMoved(Touch *pTouch, Event* pEvent);
    
    void onTouchEnd(Touch* pTouch, Event * pEvent);
    
    void update(float dt);
    
    void gameClear();
    
    void onVolumeChangeSlider(Ref* pSender, Control::EventType event);
    
    void onClickBackButton(Ref* pSender, Control::EventType event);
};

class GameScene : public Scene
{
private:
public:
    static Scene* create(int stageNo);
    bool init(int stageNo);
};

#endif /* defined(__fuse_19__GameScene__) */
