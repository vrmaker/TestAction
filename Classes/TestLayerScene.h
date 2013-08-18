#pragma once
#include "cocos2d.h"
USING_NS_CC;

class TestLayer : cocos2d::CCLayer 
{
protected:
	TestLayer(void);
	~TestLayer(void);

public:
	static cocos2d::CCScene* scene();
	virtual bool init();

	virtual void onEnter();

};

