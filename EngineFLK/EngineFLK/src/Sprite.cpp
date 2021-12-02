#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite()
{
	animation = NULL;
	hasAnimation = false;
}

Sprite::Sprite(Renderer* renderer, Shader& shader, bool initialize) : Entity2D()
{
	this->renderer = renderer;
	this->shader = shader;
	animation = NULL;
	hasAnimation = false;
	if (initialize)
	{
		Init();
	}
}

Sprite::Sprite(Renderer* renderer, Shader& shader, bool useAnimation, bool initialize) : Entity2D()
{
	this->renderer = renderer;
	this->shader = shader;

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
	vertexBuffer.SetData(quadVertices, 16);

	vertexArray.Push<float>(2);
	vertexArray.Push<float>(2);
	vertexArray.SetData(vertexBuffer);

	indexBuffer.SetData(quadIndices, 6);

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

void Sprite::DrawAnimation(glm::vec4 uvRect)
{
	//Update UV
	quadVertices[2] = uvs[0].u; 
	quadVertices[3] =  uvs[0].v;

	quadVertices[6] = uvs[1].u; 
	quadVertices[7] = uvs[1].v;

	quadVertices[10] = uvs[2].u; 
	quadVertices[11] = uvs[2].v;

	quadVertices[14] = uvs[3].u; 
	quadVertices[15] = uvs[3].v;

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
		vertexBuffer.SetData(quadVertices, 16);
		vertexArray.SetData(vertexBuffer);
		GetAnimation()->UpdateFrame();
	}

	texture.Bind();	
	renderer->Draw(shader, transform, vertexArray, vertexBuffer, indexBuffer);	
	texture.Unbind();
}

void Sprite::UnbindBuffers()
{
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	indexBuffer.Unbind();
	shader.Unbind();
}

void Sprite::DeleteBuffers()
{
	vertexArray.Delete();
	vertexBuffer.Delete();
	indexBuffer.Delete();
	shader.Delete();
}

void Sprite::SetAnimationData(int framePerRow, int framePerCollumn, float durationInSeconds, int firstIndex, int lastIndex)
{
	if (animation != NULL) 
	{
		animation->InitSpriteSheetDimensions(glm::ivec2(framePerRow, framePerCollumn));
		animation->AddFrame(durationInSeconds, firstIndex, lastIndex);
	}
}
