#include "Oncoming.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"
#include "stdio.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace cocos2d;
using namespace cocos2d::ui;

Scene* Oncoming::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Oncoming::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Oncoming::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	this->scheduleUpdate();

	auto winSize = Director::getInstance()->getVisibleSize();

	background1 = (Sprite*)rootNode->getChildByName("Background1");
	background2 = (Sprite*)rootNode->getChildByName("Background2");
	
	playerCar = new Player(rootNode);
	playerCar->imgPlayer->setColor(Color3B(255.0f, 0.0f, 0.0f));

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(Oncoming::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Oncoming::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Oncoming::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(Oncoming::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	startButton = static_cast<ui::Button*>(rootNode->getChildByName("startButton"));
	startButton->addTouchEventListener(CC_CALLBACK_2(Oncoming::StartButtonPressed, this));
	startButton->setPosition(Vec2(winSize.width*0.5f, winSize.height*0.5f));

	GameManager::sharedGameManager()->isGameLive = false;

	speed = 500.0f;

    return true;
}

void Oncoming::update(float deltaTime)
{
	if (GameManager::sharedGameManager()->isGameLive)
	{
		auto  winSize = Director::getInstance()->getVisibleSize();
		Vec2 currentPos1 = background1->getPosition();
		Vec2 currentPos2 = background2->getPosition();
		background1->setPosition(currentPos1.x, currentPos1.y - speed*deltaTime);
		background2->setPosition(currentPos2.x, currentPos2.y - speed*deltaTime);
		if (currentPos1.y < 0)
		{
			background1->setPosition(currentPos1.x, winSize.height*2);
		}
		if (currentPos2.y < 0)
		{
			background2->setPosition(currentPos2.x, winSize.height*2);
		}
	}
}

void Oncoming::StartButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		//CCLOG("touch ended.");
		this->StartGame();
	}
	this->StartGame();
}

void Oncoming::StartGame()
{
	auto winSize = Director::getInstance()->getVisibleSize();

	GameManager::sharedGameManager()->isGameLive = true;

	auto moveTo = MoveTo::create(1.5, Vec2(-winSize.width*0.5f, winSize.height*0.5f)); // Take a second to move off screen.
	startButton->runAction(moveTo);
}

void Oncoming::EndGame()
{
	auto winSize = Director::getInstance()->getVisibleSize();

	GameManager::sharedGameManager()->isGameLive = false;

	//Bring start button back on screen.
	auto moveTo = MoveTo::create(0.5, Vec2(winSize.width*0.5f, winSize.height*0.5f)); // Take half a second to move on screen.
	startButton->runAction(moveTo);
}

bool Oncoming::onTouchBegan(Touch* touch, Event* event)
{
	cocos2d::log("touch began");
	return true;
}

void Oncoming::onTouchEnded(Touch* touch, Event* event)
{
	cocos2d::log("touch ended");
}

void Oncoming::onTouchMoved(Touch* touch, Event* event)
{
	cocos2d::log("touch moved");
}

void Oncoming::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("touch cancelled");
}