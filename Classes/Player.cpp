#include "Player.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

// Constructor method
Player::Player(Node* rootNode)
{
	imgPlayer = (Sprite*)rootNode->getChildByName("Player");

	// Create 3 buttons
	leftButton   = static_cast<ui::Button*>(rootNode->getChildByName("leftButton"));
	centreButton = static_cast<ui::Button*>(rootNode->getChildByName("centreButton"));
	rightButton  = static_cast<ui::Button*>(rootNode->getChildByName("rightButton"));
}

// Deconstructor method
Player::~Player()
{

}



void Player::Update(float deltaTime)
{

}

// Create 3 methods for button press