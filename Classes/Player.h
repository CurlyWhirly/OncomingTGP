#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class Player : public cocos2d::Sprite
{
public:
	Player(Node*); // Constructor
	~Player();     // Destructor

	void Update(float);

	void LeftButtonPressed  (Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void CentreButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void RightButtonPressed (Ref *sender, cocos2d::ui::Widget::TouchEventType type);

private:
	Sprite*					imgPlayer;	  // Player image

	cocos2d::ui::Button*    leftButton;   // Left
	cocos2d::ui::Button*    centreButton; // Centre
	cocos2d::ui::Button*    rightButton;  // Right
};

#endif