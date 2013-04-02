
#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"
#include "EnemyUnit.h"
using namespace cocos2d;

class Bullet : public CCSprite , public CCTouchDelegate
{

public:
	// ��̬��ʼ������
	//static Bullet* create(BulletInfoModel* pBulletTag);
	static Bullet* create();//��̬�������ڴ��Զ��ͷţ�
	// ��ƫת�Ƕȵľ�̬��ʼ������
	//static Bullet* createWithRotation(BulletInfoModel* pBulletTag, float pRotation);

public:
	virtual ~Bullet(){}



public:
	void update(float dt); // execute every frame
	bool hitChecker(); //when bullet hit target
	//bool isGetPostion();
	void playHitAnimation();
	void onMove(CCPoint pos, CCPoint targetPos, float dt);
	void destory();
	void reuse(float speed, EnemyUnit* target, CCSpriteFrame* frame);
	CCRect getCollisionRect();
private:
	float mSpeed;
	CCPoint mTargetPos;
	CCRect mTargetCollisionRect;
	 long mTargetID;

	char temp[256];
};

#endif
