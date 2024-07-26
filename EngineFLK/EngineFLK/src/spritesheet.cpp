#include "spritesheet.h"

spritesheet::spritesheet(Texture sheet, Vector2 sheetDim, Vector2 spriteDim)
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

	uvs.x = xTile / dimensions.x;
	uvs.y = yTile / dimensions.y;
	uvs.z = 1.0f / dimensions.x;
	uvs.w = 1.0f / dimensions.y;

	for (int  y = 0; y < tilesY; y++)
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
	}
}
