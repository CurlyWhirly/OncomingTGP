#include "Enemy.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

//-------------------------------------------------------------------------

Enemy* Enemy::create(Node* rootNode)
{
	Enemy* enemy1 = new Enemy(rootNode);
	if (enemy1->init())
	{
		enemy1->autorelease();
		return enemy1;
	}
	else
	{
		CC_SAFE_DELETE(enemy1);
		return nullptr;
	}
	return enemy1;
}

//-------------------------------------------------------------------------

bool Enemy::init()
{
	if (!Node::init())
	{
		return false;
	}

	auto winSize = Director::getInstance()->getVisibleSize();
	this->scheduleUpdate();

	currentSpeed = 700.0f;

	enemy1 = (Sprite*)rootNode->getChildByName("enemyCar1");
	enemy1->setPosition(155, 1800);
	enemy2 = (Sprite*)rootNode->getChildByName("enemyCar2");
	enemy2->setPosition(325, 1800);
	enemy3 = (Sprite*)rootNode->getChildByName("enemyCar3");
	enemy3->setPosition(155, 2700);
	enemy4 = (Sprite*)rootNode->getChildByName("enemyCar4");
	enemy4->setPosition(495, 2700);
	enemy5 = (Sprite*)rootNode->getChildByName("enemyCar5");
	enemy5->setPosition(495, 3600);
	enemy6 = (Sprite*)rootNode->getChildByName("enemyCar6");
	enemy6->setPosition(325, 3600);

	return true;
}

Enemy::Enemy()
{
}

Enemy::Enemy(Node* nodeToSet)
{
	rootNode = nodeToSet;
}


Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	if (GameManager::sharedGameManager()->isGameLive)
	{
		auto  winSize = Director::getInstance()->getVisibleSize();

		Vec2 currentEnemy1Pos = enemy1->getPosition();
		enemy1->setPosition(currentEnemy1Pos.x, currentEnemy1Pos.y - currentSpeed*deltaTime);
		if (currentEnemy1Pos.y < 0)
		{
			enemy1->setPosition(currentEnemy1Pos.x, 2500);
			GameManager::sharedGameManager()->AddToScore(1);
		}

		Vec2 currentEnemy2Pos = enemy2->getPosition();
		enemy2->setPosition(currentEnemy2Pos.x, currentEnemy2Pos.y - currentSpeed*deltaTime);
		if (currentEnemy2Pos.y < 0)
		{
			enemy2->setPosition(currentEnemy2Pos.x, 2500);
		}

		Vec2 currentEnemy3Pos = enemy3->getPosition();
		enemy3->setPosition(currentEnemy3Pos.x, currentEnemy3Pos.y - currentSpeed*deltaTime);
		if (currentEnemy3Pos.y < 0)
		{
			enemy3->setPosition(currentEnemy3Pos.x, 2500);
			GameManager::sharedGameManager()->AddToScore(1);
		}

		Vec2 currentEnemy4Pos = enemy4->getPosition();
		enemy4->setPosition(currentEnemy4Pos.x, currentEnemy4Pos.y - currentSpeed*deltaTime);
		if (currentEnemy4Pos.y < 0)
		{
			enemy4->setPosition(currentEnemy4Pos.x, 2500);
		}

		Vec2 currentEnemy5Pos = enemy5->getPosition();
		enemy5->setPosition(currentEnemy5Pos.x, currentEnemy5Pos.y - currentSpeed*deltaTime);
		if (currentEnemy5Pos.y < 0)
		{
			enemy5->setPosition(currentEnemy5Pos.x, 2500);
			GameManager::sharedGameManager()->AddToScore(1);
		}

		Vec2 currentEnemy6Pos = enemy6->getPosition();
		enemy6->setPosition(currentEnemy6Pos.x, currentEnemy6Pos.y - currentSpeed*deltaTime);
		if (currentEnemy6Pos.y < 0)
		{
			enemy6->setPosition(currentEnemy6Pos.x, 2500);
		}
	}
}

bool Enemy::hasCollidedWithPlayer(Rect collisionBoxToCheck)
{
	//Did either of the enemies collide with the player.

	//Enemy 1
	Rect modifiedEnemy1;
	modifiedEnemy1.size = enemy1->getBoundingBox().size;
	modifiedEnemy1.origin = convertToWorldSpaceAR(enemy1->getBoundingBox().origin);

	//Enemy 2
	Rect modifiedEnemy2;
	modifiedEnemy2.size = enemy2->getBoundingBox().size;
	modifiedEnemy2.origin = convertToWorldSpaceAR(enemy2->getBoundingBox().origin);

	//Enemy 3
	Rect modifiedEnemy3;
	modifiedEnemy3.size = enemy3->getBoundingBox().size;
	modifiedEnemy3.origin = convertToWorldSpaceAR(enemy3->getBoundingBox().origin);

	//Enemy 4
	Rect modifiedEnemy4;
	modifiedEnemy4.size = enemy4->getBoundingBox().size;
	modifiedEnemy4.origin = convertToWorldSpaceAR(enemy4->getBoundingBox().origin);

	//Enemy 5
	Rect modifiedEnemy5;
	modifiedEnemy5.size = enemy5->getBoundingBox().size;
	modifiedEnemy5.origin = convertToWorldSpaceAR(enemy5->getBoundingBox().origin);

	//Enemy 6
	Rect modifiedEnemy6;
	modifiedEnemy6.size = enemy6->getBoundingBox().size;
	modifiedEnemy6.origin = convertToWorldSpaceAR(enemy6->getBoundingBox().origin);
	//-----------------------------------------------------------------------------------------


	//Did the incoming Rect collide with either modified Rects?
	if (modifiedEnemy1.intersectsRect(collisionBoxToCheck) || 
		modifiedEnemy2.intersectsRect(collisionBoxToCheck) ||
		modifiedEnemy3.intersectsRect(collisionBoxToCheck) ||
		modifiedEnemy4.intersectsRect(collisionBoxToCheck) || 
		modifiedEnemy5.intersectsRect(collisionBoxToCheck) ||
		modifiedEnemy6.intersectsRect(collisionBoxToCheck) )
	{
		return true;
	}

	return false;
}


void Enemy::reset()
{
	enemy1->setPosition(155, 1800);
	enemy2->setPosition(325, 1800);
	enemy3->setPosition(155, 2700);
	enemy4->setPosition(495, 2700);
	enemy5->setPosition(495, 3600);
	enemy6->setPosition(325, 3600);
}