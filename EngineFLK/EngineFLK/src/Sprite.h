#ifndef SPRITE_H
#define SPRITE_H

#include "Exports.h"

#include "Entity2D.h"
#include "Animation.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"

//#include <unordered_map>

struct FLK_API UV
{
	float u;
	float v;
};

class FLK_API Sprite : public Entity2D
{
private:
	Shader shader;
	Texture texture;

	float quadVertices[16] =
	{	 //position     //texture position
		 0.5f,  0.5f,      1.0f, 1.0f,
		 0.5f, -0.5f,      1.0f, 0.0f,
		-0.5f, -0.5f,      0.0f, 0.0f,
		-0.5f,  0.5f,      0.0f, 1.0f
	};
	unsigned int quadIndices[6] =
	{
		0, 1, 3,
		1, 2, 3
	};

	VertexBuffer vertexBuffer;
	VertexArray vertexArray;
	IndexBuffer indexBuffer;

	Animation animation;
	UV uvs[4];

	bool hasAnimation;

public:
	Sprite();
	Sprite(Renderer* renderer, Shader& shader, bool initalize = true);
	Sprite(Renderer* renderer, Shader& shader, bool initalize, bool useAnimation);
	~Sprite();
	
	void Init();

	void SetRenderer(Renderer* renderer);
	void SetShader(Shader& shader);
	void SetColor(Color color);
	void SetTexture(const std::string& path);

	void DrawAnimation(glm::vec4 uvRect);

	void AddAnimation(std::string animationName);
	Animation GetAnimation() const;

	void Draw();

private:
	void UnbindBuffers();
	void DeleteBuffers();
};

#endif