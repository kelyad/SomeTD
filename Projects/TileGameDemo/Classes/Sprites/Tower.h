
#ifndef _TOWER_H_
#define _TOWER_H_

#include "cocos2d.h"
#include "Bullet.h"
#include "../Model/Enumeration.h"
using namespace cocos2d;

//Tower class


class Tower : public CCSprite , public CCTouchDelegate
{

public:
	// ��̬��ʼ������
	//static Bullet* create(BulletInfoModel* pBulletTag);
	static Tower* create();//��̬�������ڴ��Զ��ͷţ�
	// ��ƫת�Ƕȵľ�̬��ʼ������
	//static Bullet* createWithRotation(BulletInfoModel* pBulletTag, float pRotation);

public:
public:
	virtual ~Tower(){}

	//��д������غ���----
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);


public:
	void update(float dt); // execute every frame
	void destory();
	void fire(CCSprite* target);
	void onShoot(CCNode* shooter);

public:
	//Menu
	void onMenuSelected(int type);
	void loadResource(eTower_Terrain terrain);//�Զ����ʼ������

private:

	void BuildTower();
	void showPreivew(bool isShow);
	void showRange(bool isShow);

private:
	eTower mTowerType ;
	eTower_Shooter mShooterTypeUp;
	eTower_Shooter mShooterTypeUpPart2;
	eTower_Shooter mShooterTypeDown;
	eTower_Shooter mShooterTypeDownPart2;
	eTower_Terrain mTerrainType;
	eTower_Preview mPreviewType;
	
	//CCSequence* mShooterAnimationSequence;
	//CCSequence* mTowerAnimationSequence;
private:
	/*
	 ��صľ������
	 */
	CCSprite* mShooter;
	CCSprite* mTerrain;
	CCSprite* mTarget;
private:

	float _speed;
	CCPoint _targetLastPosition;
	CCSprite* _target;
	char temp[256];
	Bullet* testBullet;
	bool canFire;
};



typedef void (Tower::*SEL_MenuTouchedFunc)(int);

#define towerMenuCallFunc(func) (SEL_MenuTouchedFunc)(&func)


#endif