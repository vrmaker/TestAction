#include "TestActionScene.h"

USING_NS_CC;

CCScene* TestAction::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TestAction *layer = TestAction::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TestAction::init()
{
	
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(TestAction::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

	s_pPathGrossini = "Images/grossini.png";
	//初始化移动物体
	m_sprite1 = CCSprite::create(s_pPathGrossini);
	m_sprite2 = CCSprite::create("Images/grossinis_sister1.png");
	m_sprite1->retain();
	m_sprite2->retain();

	addChild(m_sprite1,1);
	addChild(m_sprite2,1);

	m_sprite1->setPosition(ccp(0,0));
	m_sprite2->setPosition(ccp(70,70));
    
    return true;
}

void TestAction::onEnter()
{
	CCLayer::onEnter();

	//平移
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCActionInterval* actionTo = CCMoveTo::create(2,ccp(size.width/2,size.height/2));
	CCActionInterval* actionBy = CCMoveBy::create(2,ccp(10,10));

	m_sprite1->runAction(actionTo);

	//按顺序旋转
	CCActionInterval* actionBy2 = CCRotateBy::create(2,360);
	CCActionInterval* actionBack = actionBy2->reverse();

	m_sprite2->runAction(CCSequence::create(actionBy2,actionBack,NULL));

	
	
}
void TestAction::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
