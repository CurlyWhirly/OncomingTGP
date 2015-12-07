#include "Player.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

// Constructor method
Player::Player()
{

}

// Deconstructor method
Player::~Player()
{

}

bool Player::init()
{
	return true;
}

Player* Player::Create()
{
	Player* myNode = new Player();
	return myNode;
}

void Player::Update(float deltaTime)
{

}