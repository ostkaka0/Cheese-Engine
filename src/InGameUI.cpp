#include "InGameUI.h"


InGameUI::InGameUI(TextureContainer &tc, World &world)
{
	tc.AddSpriteSheet("UIMainStrip.png", 768, 24);
	tc.AddSpriteSheet("UIBlockBackground.png", 768, 128);
	tc.AddSpriteSheet("UIMainButtonBlocks.png", 64, 18);

}


InGameUI::~InGameUI(void)
{
}

void InGameUI::Update(sf::RenderWindow &app, TextureContainer &tc, Camera &camera, World &world)
{
	if(app.GetInput().IsMouseButtonDown(sf::Mouse::Left))
	{
		sf::Vector2f mousePos = sf::Vector2f(camera.GetCenter().x + app.GetInput().GetMouseX()-(8*16), camera.GetCenter().y + app.GetInput().GetMouseY());

	}
}

void InGameUI::Draw(sf::RenderWindow &app, TextureContainer &tc, Camera &camera, World &world)
{
	sf::Vector2f bla = camera.GetCenter() - camera.GetHalfSize();

	sf::Sprite *mainStripSprite = &(tc.getTextures("UIMainStrip.png")[0]);
	sf::Sprite *buttonBlocksSprite = &(tc.getTextures("UIMainButtonBlocks.png")[0]);

	mainStripSprite->SetPosition(bla.x + 0, bla.y + 512 - 24);
	buttonBlocksSprite->SetPosition(bla.x + 1, bla.y + 512 - 21);

	app.Draw(*mainStripSprite);
	app.Draw(*buttonBlocksSprite);

	for (std::map<unsigned short, std::function<Block*(unsigned short)>>::iterator b = world.getBlockTypeMap()->begin(); b != world.getBlockTypeMap()->end(); b++)
	{
		for(int i = 0; i < 32; i++)
		{
			Block* block = b->second(i);
			int layer = block->getLayer();
			sf::Sprite *tempSprite = &(tc.getTextures(block->getTextureName())[block->getTextureId()]);
			tempSprite->SetPosition(96 + bla.x + 16 * i, bla.y + 492);
			app.Draw(*tempSprite);
			delete block;
		}
	}
}

