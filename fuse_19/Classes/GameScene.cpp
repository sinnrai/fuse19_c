//
//  GameScene.cpp
//  fuse_19
//
//  Created by Akira on 2014/11/29.
//
//

#include "GameScene.h"
#include "TitleScene.h"

GameLayer::GameLayer():
m_pChara(nullptr),
m_stageNo(0),
m_time(0),
m_isCleared(false)
{
    for (int i = 0; i < 3; i++) {
        m_sliderValue[i] = 0;
        m_answer[i] = 0;
    }
}

GameLayer::~GameLayer()
{
}

Layer*  GameLayer::create(int stageNo)
{
    auto pRet = new GameLayer();
    if (pRet && pRet->init(stageNo)) {
        pRet->autorelease();
    } else {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

bool GameLayer::init(int stageNo)
{
    if (!Layer::init()) {
        return false;
    }
    
    m_stageNo = stageNo;
    
    for (int i = 0; i < 3; i++) {
        if (i < m_stageNo) {
            srand(time(NULL));
            m_answer[i] = (rand() % 5) + 1;
            auto pSprite = Sprite::create("res/ControlBox_288x112.png");
            pSprite->setPosition(pSprite->getContentSize().width * 0.5 + 300 * i, 100);
            this->addChild(pSprite);
            
            auto pControlSlider = ControlSlider::create("res/SliderTrack_244x20.png", "res/slider_progress.png", "res/SliderThumb_32x32.png");
            pControlSlider->addTargetWithActionForControlEvents(this, cccontrol_selector(GameLayer::onVolumeChangeSlider), Control::EventType::VALUE_CHANGED);
            pControlSlider->setPosition(pSprite->getContentSize().width * 0.5, pSprite->getContentSize().height * 0.6);
            pControlSlider->setMinimumValue(1);
            pControlSlider->setMaximumValue(5);
            pControlSlider->setValue(3);
            pControlSlider->setTag(i);
            m_sliderValue[i] = pControlSlider->getValue();
            pSprite->addChild(pControlSlider);
        }
    }
    
    m_pChara = Sprite::create("res/mattun.png");
    m_pChara->setPosition(Vec2(this->getContentSize().width * 0.5, this->getContentSize().height * 0.5));
    m_pChara->setScale(0.5);
    this->addChild(m_pChara);
    
    auto pControlButton = ControlButton::create("戻る", "", 20);
    pControlButton->setPosition(Vec2(100, 640));
    pControlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(GameLayer::onClickBackButton), Control::EventType::TOUCH_UP_INSIDE);
    this->addChild(pControlButton);
    
//    this->setTouchEnabled(true);
    this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    
    this->scheduleUpdate();
    
    return true;
}

void GameLayer::onExit()
{
    this->unscheduleUpdate();
    
    Layer::onExit();
}

bool GameLayer::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    return true;
}

void GameLayer::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{}

void GameLayer::onTouchEnd(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
}

void GameLayer::update(float dt)
{
    m_time += dt;
    if (m_isCleared == false) {
        float sign = m_sliderValue[0] * (sin( m_sliderValue[2] * m_time - m_sliderValue[1]));
        float sign2 = (m_answer[0] * (sin( m_answer[2] * m_time - m_answer[1])));
        
        if (sign - sign2 == 0) {
            this->gameClear();
        } else {
            m_pChara->setPositionY(m_pChara->getPositionY() + sign - sign2);
            if (m_pChara->getContentSize().height * 0.5 + m_pChara->getPosition().y >= 750) {
                m_pChara->setPositionY(750 - m_pChara->getContentSize().height * 0.5);
            }
        }
    }
}

void GameLayer::gameClear()
{
    m_isCleared = true;
    auto pLabel = Label::create("GameClear", "", 30);
    pLabel->setPosition(this->getContentSize().width * 0.5, this->getContentSize().height * 0.5);
    this->addChild(pLabel);
}

void GameLayer::onVolumeChangeSlider(cocos2d::Ref *pSender, Control::EventType event)
{
    ControlSlider* pControlSlider = dynamic_cast<ControlSlider*>(pSender);
    
    int tag = pControlSlider->getTag();
    m_sliderValue[tag] = floor(pControlSlider->getValue());
}

void GameLayer::onClickBackButton(cocos2d::Ref *pSender, Control::EventType event)
{
    Director::getInstance()->replaceScene(TitleScene::create());
}

Scene* GameScene::create(int stageNo)
{
    auto pRet = new GameScene();
    
    if (pRet && pRet->init(stageNo)) {
        pRet->autorelease();
    } else {
        CC_SAFE_DELETE(pRet);
    }
    
    return pRet;
}

bool GameScene::init(int stageNo)
{
    if (!Scene::init()) {
        return false;
    }
    
    this->addChild(GameLayer::create(stageNo));
    
    return true;
}