#include "spritesheet.h"

spritesheet::spritesheet(Sprite sheet, Vector2 sheetDim, Vector2 spriteDim)
{
	texturesheet = sheet;
	sheetDimensions = sheetDim;
	spriteDimensions = spriteDim;
}

spritesheet::~spritesheet()
{
}

void spritesheet::SpliceSheet()
{
	int tilesX = sheetDimensions.x / spriteDimensions.x;
	int tilesY = sheetDimensions.y / spriteDimensions.y;
	int IDCount = 0;

	for (int  y = 0; y < tilesY; y++)
	{
		for (int x = 0; x < tilesX; x++)
		{
			Tile buffer;
			buffer.SetId(IDCount);
			buffer.SetTextureCoordinates();
			
			tileID.push_back(buffer);
			IDCount++;
			
		}
	}
}
