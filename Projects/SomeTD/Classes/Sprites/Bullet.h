
#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

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
public:
	void myInit(float speed, unsigned long target);//�Զ����ʼ������
	virtual ~Bullet(){}



public:
	void update(float dt); // execute every frame
	bool isHit(); //when bullet hit target
	void destory();
	void reuse(float speed, unsigned long targetID, CCSpriteFrame* frame);
	CCRect getCollisionRect();
private:
	float mSpeed;
	CCPoint mTargetPos;
	CCRect mTargetCollisionRect;
	unsigned long mTargetID;

	char temp[256];
};

#endif
