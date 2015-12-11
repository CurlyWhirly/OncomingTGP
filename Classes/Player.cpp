 #include "Player.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

// Constructor method
Player::Player(Node* rootNode)
{
	// Create player
	imgPlayer = (Sprite*)rootNode->getChildByName("Player");

	//set starting position
	imgPlayer->setPosition(322.14, 144.68);

	// Create 3 buttons
	leftButton   = static_cast<ui::Button*>(rootNode->getChildByName("leftButton"));
	centreButton = static_cast<ui::Button*>(rootNode->getChildByName("centreButton"));
	rightButton  = static_cast<ui::Button*>(rootNode->getChildByName("rightButton"));

	// Add event listeners for buttons
	leftButton->addTouchEventListener(CC_CALLBACK_2(Player::btnLeftPressed, this));
	centreButton->addTouchEventListener(CC_CALLBACK_2(Player::btnCentrePressed, this));
	rightButton->addTouchEventListener(CC_CALLBACK_2(Player::btnRightPressed, this));
}

Rect Player::getBoundingBox() const
{
	return imgPlayer->getBoundingBox();
}

void Player::Update(float deltaTime)
{

}

// Set what each button will do when pressed

// Left button
void Player::btnLeftPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto moveTo = MoveTo::create(0.2, Vec2(157.55, 144.68));
		imgPlayer->runAction(moveTo);
	}
}

// Centre button
void Player::btnCentrePressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto moveTo = MoveTo::create(0.2, Vec2(322.14, 144.68));
		imgPlayer->runAction(moveTo);
	}
}

// Right button
void Player::btnRightPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto moveTo = MoveTo::create(0.2, Vec2(486.74, 144.68));
		imgPlayer->runAction(moveTo);
	}
}

// Deconstructor method
Player::~Player()
{

}
