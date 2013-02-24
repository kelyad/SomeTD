
#ifndef _TOWER_H_
#define _TOWER_H_

#include "cocos2d.h"

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
	void myInit();//�Զ����ʼ������
	virtual ~Tower(){}

	//��д������غ���----
	virtual void onEnter();
	virtual void onExit();
	//virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event){}
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);


public:
	void update(float dt); // execute every frame
	void destory();
	void fire(CCSprite* target);
	void onShoot(CCNode* shooter);
private:
	int mTowerType ;
	int mShooterTypeUp;
	int mShooterTypeUpPart2;
	int mShooterTypeDown;
	int mShooterTypeDownPart2;
	int mTerrainType;
	
	CCSequence* mShooterAnimationSequence;
	CCSequence* mTowerAnimationSequence;

	CCSprite* mShooter;
	CCSprite* mTerrain;
	CCSprite* mTarget;
	float _speed;
	CCPoint _targetLastPosition;
	CCSprite* _target;
	char temp[256];
};

#endif
