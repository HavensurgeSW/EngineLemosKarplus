#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "Exports.h"

#include "Vector4.h"
#include "Vector2.h"

//#include "Tile.h"
#include "texture.h"

#include <iostream>
#include <vector>

class FLK_API spritesheet
{
private: 
	struct SpriteFrame {
		Vector4 uvs;
	};

	Texture* texturesheet;
	Vector2 sheetDimensions;

	Vector2 spriteDimensions;
	SpriteFrame uvs;
	//std::vector<Tile> tileID;
	std::vector<SpriteFrame> frames;

public:
	spritesheet(const std::string& path, Vector2 sheetDim, Vector2 spriteDim);
	~spritesheet();
	
	void ShowFrameUVs();

private:
	void SpliceSheet();
	void CreateEmptyFrames();
	
};

#endif

