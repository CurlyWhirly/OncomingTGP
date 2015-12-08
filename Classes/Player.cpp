#include "Player.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

// Constructor method
Player::Player(Node* rootNode)
{
	// Create player
	imgPlayer = (Sprite*)rootNode->getChildByName("Player");

	// Create 3 buttons
	leftButton   = static_cast<ui::Button*>(rootNode->getChildByName("leftButton"));
	centreButton = static_cast<ui::Button*>(rootNode->getChildByName("centreButton"));
	rightButton  = static_cast<ui::Button*>(rootNode->getChildByName("rightButton"));

	// Add event listeners for buttons
	leftButton->addTouchEventListener(CC_CALLBACK_2(Player::LeftButtonPressed, this));
	centreButton->addTouchEventListener(CC_CALLBACK_2(Player::CentreButtonPressed, this));
	rightButton->addTouchEventListener(CC_CALLBACK_2(Player::RightButtonPressed, this));
}

void Player::Update(float deltaTime)
{

}

// Set what each button will do when pressed
void Player::LeftButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		
	}
}

void Player::CentreButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{

	}
}

void Player::RightButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{

	}
}

// Deconstructor method
Player::~Player()
{

}
