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

	Rect getBoundingBox() const;;

	void Update(float);

	void btnLeftPressed  (Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void btnCentrePressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);
	void btnRightPressed (Ref *sender, cocos2d::ui::Widget::TouchEventType type);

private:
	Sprite*					imgPlayer;	  // Player image

	cocos2d::ui::Button*    leftButton;   // Left
	cocos2d::ui::Button*    centreButton; // Centre
	cocos2d::ui::Button*    rightButton;  // Right
};

#endif