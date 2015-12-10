#ifndef __Oncoming__Enemy__
#define __Oncoming__Enemy__

#include "cocos2d.h"

class Enemy : public cocos2d::Node
{
public:
	Enemy();
	Enemy(Node* rootNode);
	~Enemy();

	virtual bool init() override;
	static Enemy* create(Node* rootNode);

	void         update(float);

	bool         hasCollidedWithPlayer(cocos2d::Rect collisionBoxToCheck);
	void         reset();

private:
	cocos2d::Sprite* enemy1;
	cocos2d::Sprite* enemy2;
	cocos2d::Sprite* enemy3;
	cocos2d::Sprite* enemy4;
	cocos2d::Sprite* enemy5;
	cocos2d::Sprite* enemy6;

	float            startXPosition;
	float            startYPosition;
	float            currentSpeed;
	Node*			 rootNode;
};

#endif