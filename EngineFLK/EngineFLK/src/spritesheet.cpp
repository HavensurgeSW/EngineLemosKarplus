#include "spritesheet.h"

spritesheet::spritesheet(const std::string& path, Vector2 sheetDim, Vector2 spriteDim)
{
	texturesheet = new Texture(path);
	sheetDimensions = sheetDim;
	spriteDimensions = spriteDim;
	CreateEmptyFrames();
}

spritesheet::~spritesheet()
{
}

void spritesheet::SpliceSheet()
{
	
	int IDCount = 0;

	
	/*for (int  y = 0; y < tilesY; y++)
	{
		for (int x = 0; x < tilesX; x++)
		{
			Tile buffer;
			buffer.SetId(IDCount);
			buffer.SetTexture(texturesheet);
			buffer.SetTextureCoordinates({ uvs[0].u, uvs[0].v },
				{ uvs[1].u, uvs[1].v },
				{ uvs[2].u, uvs[2].v },
				{ uvs[3].u, uvs[3].v });
			
			tileID.push_back(buffer);
			IDCount++;
			
		}
	}*/
}

void spritesheet::CreateEmptyFrames()
{

	int tilesX = sheetDimensions.x / spriteDimensions.x;
	int tilesY = sheetDimensions.y / spriteDimensions.y;
	for (int y = 0; y < tilesY; y++)
	{
		for (int x = 0; x < tilesX; x++)
		{
			SpriteFrame frame;

			int xTile = x % static_cast<int>(spriteDimensions.x);
			int yTile = y / static_cast<int>(spriteDimensions.y);

			frame.uvs.x = xTile / spriteDimensions.x;
			frame.uvs.y = yTile / spriteDimensions.y;
			frame.uvs.z = 1.0f / spriteDimensions.x;
			frame.uvs.w = 1.0f / spriteDimensions.y;

			frames.push_back(frame);
			//maxFrames++;
		}
		
	}

}

void spritesheet::ShowFrameUVs(){
	std::cout << frames.size() << std::endl;

}
