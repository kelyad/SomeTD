//
//  AboutScene.h
//  MoonWarriors-x
//
//  Created by Tom on 12-7-30.
//  Copyright (c) 2012�� __MyCompanyName__. All rights reserved.
//

#ifndef MoonWarriors_x_AboutScene_h
#define MoonWarriors_x_AboutScene_h

#include "cocos2d.h"
#include "AboutBGLayer.h"

USING_NS_CC;

// ���ڳ���
class AboutScene: public CCScene
{
    
public:
    AboutScene();
    ~AboutScene();
    
    bool init();
    
    CREATE_FUNC(AboutScene);
    
};

#endif
