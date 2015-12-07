#include "Player.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

// Constructor method
Player::Player(Node* rootNode)
{
	imgPlayer = (Sprite*)rootNode->getChildByName("Player");
	imgPlayer->setPosition(Vec2(100.0f, 144.0f));

	// Create 3 buttons
}

// Deconstructor method
Player::~Player()
{

}



void Player::Update(float deltaTime)
{

}

// Create 3 methods for button press