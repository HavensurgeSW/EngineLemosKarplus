#include "spritesheet.h"

spritesheet::spritesheet(const std::string& path, Vector2 sheetDim, Vector2 spriteDim)
{
	texturesheet = new Texture(path);
	sheetDimensions = sheetDim;
	spriteDimensions = spriteDim;
	CreateEmptyFrames();
	SpliceSheet();
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
			Tile* buffer = new Tile();
			buffer->SetId(IDCount);
			
			const Vector4& uv = GetFrameUVs(IDCount);

			uvs[0].u = uv.x + uv.z;
			uvs[0].v = uv.y + uv.w;

			uvs[1].u = uv.x + uv.z;
			uvs[1].v = uv.y;

			uvs[2].u = uv.x;
			uvs[2].v = uv.y;

			uvs[3].u = uv.x;
			uvs[3].v = uv.y + uv.w;
			

			buffer->SetTextureCoordinates({ uvs[0].u, uvs[0].v },
				{ uvs[1].u, uvs[1].v },
				{ uvs[2].u, uvs[2].v },
				{ uvs[3].u, uvs[3].v });
			buffer->Configure();

			tileID.push_back(buffer);

			IDCount++;

			
		}
	}
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

			int xTile = x * static_cast<int>(spriteDimensions.x);
			int yTile = y * static_cast<int>(spriteDimensions.y);

			frame.corners.x = static_cast<float>(xTile) / sheetDimensions.x;
			frame.corners.y = static_cast<float>(yTile) / sheetDimensions.y;;
			frame.corners.z = static_cast<float>(spriteDimensions.x) / sheetDimensions.x;
			frame.corners.w = static_cast<float>(spriteDimensions.y) / sheetDimensions.x;

			frames.push_back(frame);
			
		}
		
	}

}

Vector4 spritesheet::GetFrameUVs(int n)
{
	return frames[n].corners;
}

void spritesheet::ShowFrameUVs(){
	std::cout << frames.size() << std::endl;

}

void spritesheet::SetTilebyID(Tile* t, int n)
{
	const Vector4& uv = GetFrameUVs(n);

	uvs[0].u = uv.x + uv.z;
	uvs[0].v = uv.y + uv.w;

	uvs[1].u = uv.x + uv.z;
	uvs[1].v = uv.y;

	uvs[2].u = uv.x;
	uvs[2].v = uv.y;

	uvs[3].u = uv.x;
	uvs[3].v = uv.y + uv.w;

	t->SetTextureCoordinates({ uvs[0].u, uvs[0].v },
		{ uvs[1].u, uvs[1].v },
		{ uvs[2].u, uvs[2].v },
		{ uvs[3].u, uvs[3].v });
	t->SetId(n);
}
