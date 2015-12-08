#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class Player : public cocos2d::Sprite
{
public:
	Sprite*	imgPlayer; // Player image

	Player(Node*); // Constructor
	~Player();     // Destructor

	void Update(float);

	void LeftButton();
	void CentreButton();
	void RightButton();

private:
	cocos2d::ui::Button*    leftButton;   // Left
	cocos2d::ui::Button*    centreButton; // Centre
	cocos2d::ui::Button*    rightButton;  // Right
};

#endif