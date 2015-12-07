#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class Player : public cocos2d::Node
{
public:
	Player();
	~Player();

	virtual bool init() override;
	static Player* Create();

	void Update(float);

private:
	cocos2d::Sprite* player;
};

#endif