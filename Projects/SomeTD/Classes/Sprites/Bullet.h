
#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"

using namespace cocos2d;

class Bullet : public CCSprite , public CCTouchDelegate
{

public:
	// ��̬��ʼ������
	//static Bullet* create(BulletInfoModel* pBulletTag);
	static Bullet* create(float speed, unsigned long targetID, const char* spName);//��̬�������ڴ��Զ��ͷţ�
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
	void reuse();
	CCRect getCollisionRect();
private:
	float _speed;
	CCPoint _targetLastPosition;
	unsigned long _target;
	char temp[256];
};

#endif
