#ifndef _SERVER
#include "InGameUI.h"
#include "TextureContainer.h"
#include "World.h"
#include "camera.h"
#include "Block.h"
#include "BlockSolid.h"
#include "BlockBackground.h"
#include <iostream>

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

void InGameUI::Update(App& app, TextureContainer &tc, World &world)
{
	sf::Vector2f bla = GetCamera(app).GetCenter() - GetCamera(app).GetHalfSize();
	sf::Vector2f mousePos = sf::Vector2f(
		GetCamera(app).GetCenter().x 
		- GetCamera(app).GetHalfSize().x
		+ app.GetInput().GetMouseX()
		- (8*16),
		+ GetCamera(app).GetCenter().y
		- GetCamera(app).GetHalfSize().y
		+ app.GetInput().GetMouseY());

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
			if(mousePos.x > 96 + bla.x + 16 * i + 144 && mousePos.x < 96 + bla.x + 16 * i + 16 + 128 + 16 && mousePos.y > bla.y + 492 && mousePos.y < bla.y + 492 + 16)
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
				world.setBlockAndMetadata((long)((GetCamera(app).GetCenter().x + app.GetInput().GetMouseX()-(8*16))*0.0625), (long)(GetCamera(app).GetCenter().y + app.GetInput().GetMouseY())>>4, 2, 1, selectedBlockSolid);//world.setBlockAndMetadata(2,(short)( GetCamera(app).GetCenter().x + app.GetInput().GetMouseX()-(8*16)), (short)(GetCamera(app).GetCenter().y + app.GetInput().GetMouseY()), 1, selectedBlockSolid);
			else if(selectedBackground != -1)
				world.setBlockAndMetadata((long)((GetCamera(app).GetCenter().x + app.GetInput().GetMouseX()-(8*16))*0.0625), (long)(GetCamera(app).GetCenter().y + app.GetInput().GetMouseY())>>4, 0, 2, selectedBackground);
				
				//world.setBlockAndMetadata(0, (short)(GetCamera(app).GetCenter().x + app.GetInput().GetMouseX()-(8*16)), (short)(GetCamera(app).GetCenter().y + app.GetInput().GetMouseY()), 2, selectedBackground);
		}
	}
	else if(app.GetInput().IsMouseButtonDown(sf::Mouse::Right))
	{
		int layer = 2;
		//if (world.getBlock(layer, (short)(GetCamera(app).GetCenter().x + app.GetInput().GetMouseX()-(8*16))>>4, (short)(GetCamera(app).GetCenter().y + app.GetInput().GetMouseY())>>4) == 0)
		//	layer = 0;
		world.setBlock((short)(GetCamera(app).GetCenter().x + app.GetInput().GetMouseX()-(8*16))>>4, (short)(GetCamera(app).GetCenter().y + app.GetInput().GetMouseY())>>4, 2, 0);	
	}
}

void InGameUI::Draw(App& app, TextureContainer &tc, World &world)
{
	sf::Vector2f bla = GetCamera(app).GetCenter() - GetCamera(app).GetHalfSize();

	sf::Sprite *mainStripSprite = &(tc.getTextures("UIMainStrip.png")[0]);
	sf::Sprite *buttonBlocksSprite = &(tc.getTextures("UIMainButtonBlocks.png")[0]);

	mainStripSprite->SetPosition(bla.x + 0, bla.y + 512 - 24);
	buttonBlocksSprite->SetPosition(bla.x + 1, bla.y + 512 - 21);

	app.Draw(*mainStripSprite);
	app.Draw(*buttonBlocksSprite);

	for (auto b : world.getBlockTypeMap())//for (std::map<unsigned short, std::function<Block*(unsigned short)>>::iterator b = world.getBlockTypeMap()->begin(); b != world.getBlockTypeMap()->end(); b++)
	{
		//return;
		for(int i = 0; i < 32; i++)
		{
			Block* block = b.second(i);
			if(block->getLayer() == 2 && i < 18)
			{
				block->Draw((i<<4)+bla.x + 96, 1+bla.y+492, app, tc, i);
				//sf::Sprite *tempSprite = &(tc.getTextures(block->getTextureName())[block->getTextureId(app, 0)]);
				//tempSprite->SetPosition(96 + bla.x + 16 * i, bla.y + 492);
				//app.Draw(*tempSprite);
			}
			else if(block->getLayer() == 0 && i >= 18)
			{
				block->Draw((i<<4)+bla.x + 96, 1+bla.y+492, app, tc, i-18);
				//sf::Sprite *tempSprite = &(tc.getTextures(blockk->getTextureName())[blockk->getTextureId(app, 0)]);
				//tempSprite->SetPosition(96 + bla.x + 16 * i + 16, bla.y + 492);
				//app.Draw(*tempSprite);
			}
		}
	}
}
#endif