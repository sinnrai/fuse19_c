//
//  TitleScene.cpp
//  fuse_19
//
//  Created by Akira on 2014/11/29.
//
//

#include "TitleScene.h"
#include "GameScene.h"

bool TitleLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    for (int i = 0; i < 3; i++) {
        auto pControlButton = ControlButton::create(String::createWithFormat("ステージ%d", i + 1)->getCString(), "", 20);
        pControlButton->setTag(i);
        pControlButton->setPosition(Vec2(400 * (i + 1), 200));
        pControlButton->addTargetWithActionForControlEvents(this, cccontrol_selector(TitleLayer::onClickStageButton), Control::EventType::TOUCH_UP_INSIDE);
        this->addChild(pControlButton);

    }
    
    return true;
}

void TitleLayer::onClickStageButton(cocos2d::Ref *pSender, Control::EventType eventType)
{
    Node* pControlButton = dynamic_cast<Node*>(pSender);
    
    Director::getInstance()->replaceScene(GameScene::create(pControlButton->getTag() + 1));
}

bool TitleScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    
    this->addChild(TitleLayer::create());
    
    return true;
}