#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite()
{
	animation = NULL;
	hasAnimation = false;
}

Sprite::Sprite(Renderer* renderer, Shader& shader, bool initialize) : Entity2D(renderer, shader)
{
	animation = NULL;
	hasAnimation = false;
	if (initialize)
	{
		Init();
	}
}

Sprite::Sprite(Renderer* renderer, Shader& shader, bool useAnimation, bool initialize) : Entity2D(renderer, shader)
{
	if (useAnimation) 
	{
		hasAnimation = useAnimation;
		animation = new Animation();
	}

	if (initialize)
	{
		Init();
	}
}

Sprite::~Sprite()
{
	delete animation;
	UnbindBuffers();
	DeleteBuffers();
}

void Sprite::SetRenderer(Renderer* renderer)
{
	this->renderer = renderer;
}

void Sprite::SetShader(Shader& shader)
{
	this->shader = shader;
}

void Sprite::Init()
{
	vertexBuffer.SetData(spriteVertices, 16);

	vertexArray.Push<float>(2);
	vertexArray.Push<float>(2);
	vertexArray.SetData(vertexBuffer);

	indexBuffer.SetData(spriteIndices, 6);

	shader.Bind();
	shader.SetTextureUniform(0);
	shader.Unbind();
}

void Sprite::SetColor(Color color)
{
	shader.Bind();
	shader.SetColorUniform(color);
	shader.Unbind();
}

void Sprite::AddAnimation(std::string animationName)
{
	//if (animations.find(animationName) != animations.end())
	//{
	//	std::cout << "Animation with the name '" << animationName << "' has already been added" << std::endl;
	//	return;
	//}
	//
	//Animation animation;
	//animation.SetName(animationName);
	//animations[animation.GetName()] = animation;
}

Animation* Sprite::GetAnimation() const
{
	return animation;
}

void Sprite::SetTexture(const std::string& path)
{
	texture.LoadTexture(path);

	shader.Bind();
	shader.SetColorUniform(Color::White());
	shader.Unbind();
}

void Sprite::DrawAnimation(Vector4 uvRect)
{
	//Update UV
	spriteVertices[2] = uvs[0].u;
	spriteVertices[3] =  uvs[0].v;

	spriteVertices[6] = uvs[1].u;
	spriteVertices[7] = uvs[1].v;

	spriteVertices[10] = uvs[2].u;
	spriteVertices[11] = uvs[2].v;

	spriteVertices[14] = uvs[3].u;
	spriteVertices[15] = uvs[3].v;

	//Set UV
	uvs[0].u = uvRect.x + uvRect.z; 
	uvs[0].v = uvRect.y + uvRect.w;

	uvs[1].u = uvRect.x + uvRect.z; 
	uvs[1].v = uvRect.y;

	uvs[2].u = uvRect.x; 
	uvs[2].v = uvRect.y;

	uvs[3].u = uvRect.x; 
	uvs[3].v = uvRect.y + uvRect.w;
}


void Sprite::Draw()
{
	if (hasAnimation)
	{
		DrawAnimation(GetAnimation()->GetFrames());
		vertexBuffer.SetData(spriteVertices, 16);
		vertexArray.SetData(vertexBuffer);
		GetAnimation()->UpdateFrame();
	}

	texture.Bind();	
	renderer->Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);	
	texture.Unbind();
}

void Sprite::SetAnimationData(int framePerRow, int framePerCollumn, float animationDuration, int firstIndex, int lastIndex)
{
	if (animation != NULL) 
	{
		animation->InitSpriteSheetDimensions({ static_cast<float>(framePerRow), static_cast<float>(framePerCollumn) });
		animation->AddFrame(animationDuration, firstIndex, lastIndex);
	}
}
