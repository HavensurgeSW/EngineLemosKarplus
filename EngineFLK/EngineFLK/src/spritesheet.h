#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "Exports.h"

#include "Vector4.h"
#include "Vector2.h"

#include "Tile.h"
#include "texture.h"

#include <iostream>
#include <vector>

class FLK_API spritesheet
{
private:
	struct SpriteFrame {
		Vector4 corners;
	};

	struct UV {
		float u;
		float v;
	};

	Texture* texturesheet;
	Vector2 sheetDimensions;
	UV uvs[4];

	Vector2 spriteDimensions;
	SpriteFrame corners;
	std::vector<SpriteFrame> frames;

public:
	spritesheet(const std::string& path, Vector2 sheetDim, Vector2 spriteDim);
	~spritesheet();
	
	void ShowFrameUVs();
	void SetTilebyID(Tile* t, int n);
	std::vector<Tile*> tileID;
	Vector2 GetSpriteDim();

private:
	void SpliceSheet();
	void CreateEmptyFrames();
	Vector4 GetFrameUVs(int n);
	
};

#endif

