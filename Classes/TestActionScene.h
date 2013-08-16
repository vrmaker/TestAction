#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "sprite_nodes/CCSprite.h"
#include <string>
using namespace std;

USING_NS_CC;

class TestAction : public cocos2d::CCLayer
{
protected:
	CCSprite*	 m_sprite1;
	CCSprite*	 m_sprite2;
	char*		 s_pPathGrossini;

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

	//render
	virtual void onEnter();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(TestAction);
};

#endif // __HELLOWORLD_SCENE_H__
