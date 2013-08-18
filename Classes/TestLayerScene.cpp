#include "TestLayerScene.h"


TestLayer::TestLayer(void)
{
}


TestLayer::~TestLayer(void)
{
}

CCScene* TestLayer::scene()
{
	CCScene* scene = CCScene::create();
	TestLayer* layer = CCLayer::create();
	scene->addChild(layer);

	return scene;
}
