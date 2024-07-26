#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include "Exports.h"

#include "Vector4.h"
#include "Vector2.h"

#include "Tile.h"

#include <iostream>
#include <vector>

class FLK_API spritesheet
{
private: 
	struct SpriteFrame {
		Vector4 uvs;
	};


	Texture texturesheet;
	Vector2 sheetDimensions;

	Vector2 spriteDimensions;
	std::vector<Tile> tileID;

public:
	spritesheet(Texture tex, Vector2 sheetDim, Vector2 spriteDim);
	~spritesheet();
	

private:
	void SpliceSheet();
	Vector4 GetFrameUVs() const;
	
};

#endif

