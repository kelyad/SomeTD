

#include "ShipSprite.h"

ShipSprite* ShipSprite::createWithShipInfo(EnemyInfoModel* enemyInfo)
{
	ShipSprite* shipSprite = new ShipSprite();
	shipSprite->mEnemyInfo = enemyInfo;
	shipSprite->initWithSpriteFrameName(enemyInfo->textureName);
	shipSprite->schedule(schedule_selector(ShipSprite::shoot), enemyInfo->AttackSpeed);

	return shipSprite;
} 
void ShipSprite::shoot(float dt)
{
	CCPoint pos = this->getPosition();
	Bullet* bullet = Bullet::create(BULLET_TYPE::TYPE1);
	//GameManager::getSingleton().getPool(POOL_TYPE::BULLET).add(bullet);
	this->getParent()->addChild(bullet, bullet->mBulletInfo->zOrder, BULLET_TYPE::TYPE1);
	bullet->setPosition(CCPoint(pos.x, pos.y - this->getContentSize().height * 0.2));
}

void ShipSprite::getHit(BULLET_TYPE bulletType)
{
	this->mEnemyInfo->HP -= WeaponInfoModel::GetDamage(bulletType);
}

CCRect ShipSprite::getCollisionRect()
{
	CCPoint pos = this->getPosition();
	return CCRect(pos.x - 3, pos.y -3, 6, 6);
}

void ShipSprite::destroy()
{

}

void ShipSprite::update(float dt)
{
	if (this->mEnemyInfo->HP <= 0)
	{
		this->Active = false;
	}
	this->_timeTick += dt;
	if (this->_timeTick > 0.1)
	{
		this->_timeTick = 0;
		if (this->mEnemyInfo->HurtColorLife >  0)
		{
			this->mEnemyInfo->HurtColorLife--;
		}
		if (this->mEnemyInfo->HurtColorLife == 1)
		{
			this->setColor(ccc3(255,255,255));
		}
	}
	//	this->removeChild()
}