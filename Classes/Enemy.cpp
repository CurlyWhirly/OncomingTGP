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

void Enemy::reset()
{
	enemy1->setPosition(155, 1800);
	enemy2->setPosition(325, 1800);
	enemy3->setPosition(155, 2700);
	enemy4->setPosition(495, 2700);
	enemy5->setPosition(495, 3600);
	enemy6->setPosition(325, 3600);
}