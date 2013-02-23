//
//  Bullet.cpp
//  TileGameDemo
//
//  Created by kelyad on 02-17-2013.
//

#include "Tower.h"
#include "../Helper/CommonHelpers.h"
using namespace cocos2d;
Tower* Tower::create(float speed, CCSprite* target, const char* spName)
{
	Tower *bullte = new Tower();

	if (bullte && bullte->initWithSpriteFrameName(spName))//��ע1
	{
		bullte->myInit(speed, target);
		bullte->autorelease();

		return bullte;
	}
	CC_SAFE_DELETE(bullte);
	return NULL;

}
void Tower::ccTouchMoved(CCTouch* touch, CCEvent* event)
{

	//��ȡ��ǰ�û����������겢��3d����ӳ��2d����ϵ
	//CCPoint touchPoint = touch->locationInView( touch->view() );
	//touchPoint = CCDirector::sharedDirector()->convertToGL( touchPoint );

	//touchPoint.x, getPosition().y
	//if(touchPoint.x> CCDirector::sharedDirector()->getWinSize().width/2){
	//	CCLog("%s","����22~~ccTouchMoved");
	//}
}

void Tower::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	//CCLog("%s","����33~~~ccTouchEnded");
} 

//---SpriteClassModel ��ʼ�������������ں���----
void Tower::onEnter()
{
	//ע�����   1.dele�࣬2.���ȼ���3.YESΪ�谭�������move �� end

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
	CCSprite::onEnter();
}

void Tower::onExit()
{
	//�Ƴ�����
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCSprite::onExit();
}



void Tower::myInit(float speed, CCSprite* target)
{
	this->_speed = speed;
	this->_target = target;
	this->_targetLastPosition = target->getPosition();
}
void Tower::reuse()
{
	this->scheduleUpdate();
	this->setVisible(true);
}



void Tower::update(float dt)
{
	CCPoint pos = this->getPosition();
	//pos.y -= this->mBulletInfo->BulletSpeed * dt;
	this->setPositionY(pos.y);
	if(this->isHit())
	{
		this->unscheduleUpdate();
		//this->destory();
		
		CCSequence* sequence = CCSequence::createWithTwoActions(
			CCAnimate::create(CCAnimationCache::sharedAnimationCache()->animationByName("magebolt_boom")),
			CCCallFunc::create(this, callfunc_selector(Tower::destory))
		);
		this->runAction(sequence);
	}
	else
	{
		CCPoint pos = this->getPosition();
		CCPoint targetPosNew = this->_target->getPosition();
		//ccVertex2F toOldTarget = vertex2( this->_targetLastPosition.x - pos.x, this->_targetLastPosition.y - pos.y );

		ccVertex2F toNewTarget = vertex2( targetPosNew.x - pos.x, targetPosNew.y - pos.y);
		//ccVertex2F toNewPos = vertex2FAdd(toOldTarget, toNewTarget);
		ccVertex2F toNewPos = vertex2FMul(&vertex2FNormalization(toNewTarget), dt * this->_speed * 5);
		
		//sprintf_s(temp,255, "%-08.4f",dt);
		//CCLog(temp);
		CCPoint newPos = CCPoint(pos.x + toNewPos.x, pos.y + toNewPos.y);
		this->setPosition(newPos);

		float angleRadians = atanf((float)toNewPos.y / (float)toNewPos.x);
		float angleDegrees = CC_RADIANS_TO_DEGREES(angleRadians);
		float cocosAngle = -1 * angleDegrees + 180;
		this->setRotation(cocosAngle);

	}
	//CCSpriteFrameCache.addSpriteFrame()
	// this->setPosition(ccpAdd(this->getPosition(), ccpMult(mVelocity, dt)));
}
bool Tower::isHit()
{
	CCPoint target = this->_target->getPosition();
	CCRect targetCollisionRect = CCRect(target.x - 3, target.y -3, 6, 6);

	CCPoint pos = this->getPosition();
	CCRect collisionRect  = CCRect(pos.x - 3, pos.y - 3, 6, 6);
	if(targetCollisionRect.intersectsRect(collisionRect))
		return true;
	else
		return false;

}
void Tower::destory()
{

	this->setVisible(false);
}

CCRect Tower::getCollisionRect()
{
	CCPoint pos = this->getPosition();
	return CCRect(pos.x - 3, pos.y -3, 6, 6);
}



