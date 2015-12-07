#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d;

class Player : public cocos2d::Sprite
{
public:
	Player(Node* );
	~Player();

	void Update(float);
	Sprite* imgPlayer;
	/*cocos2d::ui::Button*    startButton; LEFT
	cocos2d::ui::Button*    startButton; CENTRE
	cocos2d::ui::Button*    startButton; RIGHT */
private:
	
};

#endif