//
//  GamePlayScene.cpp
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#include "GamePlayScene.h"

GamePlayScene::GamePlayScene()
{
}

GamePlayScene::~GamePlayScene()
{
}

bool GamePlayScene::init()
{
    bool ret = false;
    
    do {
        CC_BREAK_IF(!CCScene::init());
        
        // ������
        this->addChild(GamePlayBGLayer::create(), 0);
        // ��Ϸ��
        this->addChild(GamePlayLayer::create(), 1);
        
        ret = true;
    } while (0);
    
    return ret;
}