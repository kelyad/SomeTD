//
//  Bullet.cpp
//  TileGameDemo
//
//  Created by kelyad on 02-17-2013.
//

#include "TowerMenu.h"
#include "../Helper/CommonHelpers.h"
using namespace cocos2d;
TowerMenu* TowerMenu::create()
{
	TowerMenu *menu = new TowerMenu();

	if (menu && menu->initWithSpriteFrameName("gui_ring.png"))//��ע1
	{
		menu->myInit();
		menu->autorelease();

		return menu;
	}
	CC_SAFE_DELETE(menu);
	return NULL;

}

void TowerMenu::myInit()
{
	CCSpriteFrameCache* frameChache = CCSpriteFrameCache::sharedSpriteFrameCache();
	
	//Frames
	this->mMainMenuFrame.resize(MenuItemFrame::MainFrameMax);
	this->mMainMenuFrame[MenuItemFrame::ArcherNormal] = frameChache->spriteFrameByName("main_icons_0001.png");
	this->mMainMenuFrame[MenuItemFrame::ArcherOff] = frameChache->spriteFrameByName("main_icons_off_0001.png");
	this->mMainMenuFrame[MenuItemFrame::ArcherDisabled] = frameChache->spriteFrameByName("main_icons_disabled_0001.png");

	this->mMainMenuFrame[MenuItemFrame::BarrackNormal] = frameChache->spriteFrameByName("main_icons_0002.png");
	this->mMainMenuFrame[MenuItemFrame::BarrackOff] = frameChache->spriteFrameByName("main_icons_off_0002.png");
	this->mMainMenuFrame[MenuItemFrame::BarrackDisabled] = frameChache->spriteFrameByName("main_icons_disabled_0002.png");

	this->mMainMenuFrame[MenuItemFrame::MageNormal] = frameChache->spriteFrameByName("main_icons_0003.png");
	this->mMainMenuFrame[MenuItemFrame::MageOff] = frameChache->spriteFrameByName("main_icons_off_0003.png");
	this->mMainMenuFrame[MenuItemFrame::MageDisabled] = frameChache->spriteFrameByName("main_icons_disabled_0003.png");

	this->mMainMenuFrame[MenuItemFrame::ArtilleryNormal] = frameChache->spriteFrameByName("main_icons_0004.png");
	this->mMainMenuFrame[MenuItemFrame::ArtilleryOff] = frameChache->spriteFrameByName("main_icons_off_0004.png");
	this->mMainMenuFrame[MenuItemFrame::ArtilleryDisabled] = frameChache->spriteFrameByName("main_icons_disabled_0004.png");

	//Item
	this->mMainMenuItem.resize(MenuItemSprite::MenuItemSpriteMax);
	this->mMainMenuItem[MenuItemSprite::Upgrade] = CCSprite::createWithSpriteFrameName("main_icons_0014.png");
	this->mMainMenuItem[MenuItemSprite::Upgrade]->setPosition(CCPoint(74, 74));
	this->mMainMenuItem[MenuItemSprite::Upgrade]->setVisible(false);
	this->mMainMenuItem[MenuItemSprite::Archer] = CCSprite::createWithSpriteFrameName("main_icons_0001.png");
	this->mMainMenuItem[MenuItemSprite::Archer]->setPosition(CCPoint(-49 + 74, 56 + 74));
	this->mMainMenuItem[MenuItemSprite::Barrack] = CCSprite::createWithSpriteFrameName("main_icons_0002.png");
	this->mMainMenuItem[MenuItemSprite::Barrack]->setPosition(CCPoint(49 + 74, 56 + 74));
	this->mMainMenuItem[MenuItemSprite::Mage] = CCSprite::createWithSpriteFrameName("main_icons_0003.png");
	this->mMainMenuItem[MenuItemSprite::Mage]->setPosition(CCPoint(-49 + 74, -56 + 74));
	this->mMainMenuItem[MenuItemSprite::Atillery] = CCSprite::createWithSpriteFrameName("main_icons_0004.png");
	this->mMainMenuItem[MenuItemSprite::Atillery]->setPosition(CCPoint(49 + 74, -56 + 74));
	for (std::vector<CCSprite*>::iterator it = this->mMainMenuItem.begin(); it != this->mMainMenuItem.end(); it ++)
	{
		if(*it != NULL)
			this->addChild(*it);
	}

}

bool TowerMenu::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	return true;
}

void TowerMenu::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

	//��ȡ��ǰ�û����������겢��3d����ӳ��2d����ϵ
	//CCPoint touchPoint = touch->locationInView( touch->view() );
	//touchPoint = CCDirector::sharedDirector()->convertToGL( touchPoint );

	//touchPoint.x, getPosition().y
	//if(touchPoint.x> CCDirector::sharedDirector()->getWinSize().width/2){
	//	CCLog("%s","����22~~ccTouchMoved");
	//}
}

void TowerMenu::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCLog("%s","����33~~~ccTouchEnded");
} 

//---SpriteClassModel ��ʼ�������������ں���----
void TowerMenu::onEnter()
{
	//ע�����   1.dele�࣬2.���ȼ���3.YESΪ�谭�������move �� end

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}

void TowerMenu::onExit()
{
	//�Ƴ�����
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}

void TowerMenu::update(float dt)
{
	
}

void TowerMenu::destory()
{

	this->setVisible(false);
}

CCRect TowerMenu::getCollisionRect()
{
	CCPoint pos = this->getPosition();
	return CCRect(pos.x - 3, pos.y -3, 6, 6);
}



