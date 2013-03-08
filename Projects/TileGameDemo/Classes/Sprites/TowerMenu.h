
#ifndef _TOWER_MENU_
#define _TOWER_MENU_

#include "cocos2d.h"
#include "Tower.h"
using namespace cocos2d;

class TowerMenu : public CCSprite , public CCTouchDelegate
{
public:	 
	enum MenuItemFrame
	{
		LockNormal,
		LockOff,
		LockDisabled,
		ArcherNormal,
		ArcherOff,
		ArcherDisabled,
		BarrackNormal,
		BarrackOff,
		BarrackDisabled,
		MageNormal,
		MageOff,
		MageDisabled,
		ArtilleryNormal,
		ArtilleryOff,
		ArtilleryDisabled,
		ComfirmNormal,
		ConfirmDisabled,
		RangeCircle,
		RallyCircle,
		MainFrameMax
	};
	enum MenuItemSprite
	{
		Archer,
		Barrack,
		Mage,
		Artillery,
		Upgrade,
		Sale,
		MenuItemSpriteMax
	};

	enum MenuLevel
	{
		Lv0,
		Lv1,
		Lv2,
		Lv3,
		LvS1,
		LvS2
	};
public:
	// ��̬��ʼ������
	//static Bullet* create(BulletInfoModel* pBulletTag);
	static TowerMenu* sharedTowerMenu();//��̬�������ڴ��Զ��ͷţ�
	// ��ƫת�Ƕȵľ�̬��ʼ������
	//static Bullet* createWithRotation(BulletInfoModel* pBulletTag, float pRotation);

public:
public:
	void myInit();//�Զ����ʼ������
	virtual ~TowerMenu(){}
	//��д������غ���----
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);


public:
	void update(float dt); // execute every frame
	void onBuild(); //when bullet hit target
	void onUpgrade();
	void destory();
	void showMenu(CCPoint pos, Tower* tower, MenuLevel lv );

	CCRect getCollisionRect();
private:
	void resetFrame();
	void hideMenu();

private:

	std::vector<CCSpriteFrame*> mMainMenuFrame;
	std::vector<CCSprite*> mMainMenuItem;
	float _speed;
	CCPoint _targetLastPosition;
	CCSprite* _target;
	char temp[256];
protected:
	static TowerMenu* mInstance;
	int mCurLevel;
	Tower* mCurTower;
};

#endif
