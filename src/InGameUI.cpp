#include "InGameUI.h"


InGameUI::InGameUI(TextureContainer &tc, World &world)
{
	tc.AddSpriteSheet("UIMainStrip.png", 768, 24);
	tc.AddSpriteSheet("UIBlockBackground.png", 768, 128);
	tc.AddSpriteSheet("UIMainButtonBlocks.png", 64, 18);
	selectedBlockSolid = 0;
	selectedBackground = 0;
}


InGameUI::~InGameUI(void)
{
}

void InGameUI::Update(sf::RenderWindow &app, TextureContainer &tc, Camera &camera, World &world)
{
	sf::Vector2f bla = camera.GetCenter() - camera.GetHalfSize();
	sf::Vector2f mousePos = sf::Vector2f(camera.GetCenter().x  - camera.GetHalfSize().x + app.GetInput().GetMouseX()-(8*16), camera.GetCenter().y - camera.GetHalfSize().y + app.GetInput().GetMouseY());
	if(app.GetInput().IsMouseButtonDown(sf::Mouse::Left))
	{
		for(int i = 0; i < 16; i++)
		{
			if(mousePos.x > 96 + bla.x + 16 * i - 128 && mousePos.x < 96 + bla.x + 16 * i + 16 -128 && mousePos.y > bla.y + 492 && mousePos.y < bla.y + 492 + 16)
			{
				selectedBackground = -1;
				selectedBlockSolid = i;
				std::cout << "Clicked block solid " << i << std::endl;
			}
		}
		for(int i = 0; i < 16; i++)
		{
			if(mousePos.x > 96 + bla.x + 16 * i + 128 + 16 && mousePos.x < 96 + bla.x + 16 * i + 16 + 128 + 16 && mousePos.y > bla.y + 492 && mousePos.y < bla.y + 492 + 16)
			{
				selectedBlockSolid = -1;
				selectedBackground = i;
				std::cout << "Clicked block background " << i << std::endl;
			}
		}
	}
	if(app.GetInput().IsMouseButtonDown(sf::Mouse::Left))
	{
		if(app.GetInput().GetMouseY() < 512 - 24)
		{
			if(selectedBlockSolid != -1)
				world.setBlock(2,(short)( camera.GetCenter().x + app.GetInput().GetMouseX()-(8*16)), (short)(camera.GetCenter().y + app.GetInput().GetMouseY()), new BlockSolid(selectedBlockSolid));
			else if(selectedBackground != -1)
				world.setBlock(0, (short)(camera.GetCenter().x + app.GetInput().GetMouseX()-(8*16)), (short)(camera.GetCenter().y + app.GetInput().GetMouseY()), new BlockBackground(selectedBackground));
		}
	}
	else if(app.GetInput().IsMouseButtonDown(sf::Mouse::Right))
	{
		world.setBlock(2, (short)(camera.GetCenter().x + app.GetInput().GetMouseX()-(8*16)), (short)(camera.GetCenter().y + app.GetInput().GetMouseY()), NULL);	
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
			if(block->getLayer() == 2 && i <= 16)
			{
				sf::Sprite *tempSprite = &(tc.getTextures(block->getTextureName())[block->getTextureId()]);
				tempSprite->SetPosition(96 + bla.x + 16 * i, bla.y + 492);
				app.Draw(*tempSprite);
			}
			else if(block->getLayer() == 0 && i >= 17)
			{
				Block* blockk = b->second(i-16);
				sf::Sprite *tempSprite = &(tc.getTextures(blockk->getTextureName())[blockk->getTextureId()]);
				tempSprite->SetPosition(96 + bla.x + 16 * i + 16, bla.y + 492);
				app.Draw(*tempSprite);
				delete blockk;
			}
			delete block;
		}
	}
}

