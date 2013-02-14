#include "InGameUI.h"


InGameUI::InGameUI(TextureContainer &tc)
{
	tc.AddSpriteSheet("UIMainStrip.png", 768, 24);
	tc.AddSpriteSheet("UIBlockBackground.png", 768, 128);
	tc.AddSpriteSheet("UIMainButtonBlocks.png", 64, 18);

	for(int i = 0; i < 32; i++)
	{
		sf::Sprite *tempSprite = &(tc.getTextures("BlockSolid.png")[i]);
		tempSprite->SetPosition(96 + i*16, 512 - 20);
		InGameUIItemList.insert(std::pair<sf::Sprite*, sf::Vector2f>(tempSprite, tempSprite->GetPosition()));
	}
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

	for (std::map<sf::Sprite*, sf::Vector2f>::iterator i = InGameUIItemList.begin(); i != InGameUIItemList.end(); i++)
    {
		sf::Sprite *tempSprite = i->first;
		tempSprite->SetPosition(i->second.x + bla.x, i->second.y + bla.y);
		app.Draw(*tempSprite);
	}
}

