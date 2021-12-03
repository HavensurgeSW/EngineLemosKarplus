#include "Game.h"

void Game::Init()
{
	Shader shapeShader("res/shaders/Shape.shader");
	shape = new Shape(GetRenderer(), shapeShader, ShapeType::QUAD, false);
	shape->SetVertexColor(Color::Red(), Color::Yellow(), Color::Red(), Color::Yellow());
	shape->Init();

	Shader enanoShader("res/shaders/Sprite.shader");
	enano = new Sprite(GetRenderer(), enanoShader);
	enano->SetTexture("res/textures/EnanoBostero.png");

	Shader illuminatiShader("res/shaders/Sprite.shader");
	illuminati = new Sprite(GetRenderer(), illuminatiShader);
	illuminati->SetTexture("res/textures/illuminati.png");
	illuminati->SetColor(Color::Green());

	Shader rockShader("res/shaders/Sprite.shader");
	rock = new AnimatedSprite(GetRenderer(), rockShader);
	rock->SetTexture("res/spritesheets/RockSpritesheet.png");
	rock->SetAnimationData(12, 1, 1.0f, 0, 11);

	Vector2 trianglePosition(-0.7f, 0.0f);
	float triangleRotationSpeed = -45.0f;
	Vector3 triangleRotation(0.0f, 0.0f, 1.0f);
	Vector2 quadPosition(0.0f, 0.5f);
	float quadRotationSpeed = 0.0f;
	Vector3 quadRotation(0.0f, 0.0f, 1.0f);
	float scale = 0.6f;

	shape->transform.SetPosition(trianglePosition);
	shape->transform.SetRotation(triangleRotationSpeed, triangleRotation);
	shape->transform.SetScale(scale - 0.3f);

	illuminati->transform.SetPosition(quadPosition);
	illuminati->transform.SetRotation(quadRotationSpeed, quadRotation);
	illuminati->transform.SetScale(scale);

	enano->transform.SetPosition(0.7f, 0.0f, 0.0f);
	enano->transform.SetScale(scale);

	rock->transform.SetPosition(0.0f, -0.5f, 0.0f);
	rock->transform.SetScale(scale + 0.3f);
}

void Game::Update()
{
	if (Input::GetKey(KeyCode::W))
	{
		rock->transform.Translate({ 0, 0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::S))
	{
		rock->transform.Translate({ 0, -0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::D))
	{
		rock->transform.Translate({ 0.01f, 0, 0 });
	}
	if (Input::GetKey(KeyCode::A))
	{
		rock->transform.Translate({ -0.01f,0,0 });
	}
	if (Input::GetKey(KeyCode::Q))
	{
		rock->transform.RotateZAxis(1.0f);
	}
	if (Input::GetKey(KeyCode::E))
	{
		rock->transform.RotateZAxis(-1.0f);
	}

	if (Input::GetKey(KeyCode::UP))
	{
		enano->transform.Translate({ 0, 0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::DOWN))
	{
		enano->transform.Translate({ 0, -0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::RIGHT))
	{
		enano->transform.Translate({ 0.01f, 0, 0 });
	}
	if (Input::GetKey(KeyCode::LEFT))
	{
		enano->transform.Translate({ -0.01f, 0, 0 });
	}
	if (Input::GetKey(KeyCode::NUMPAD_1))
	{
		enano->transform.RotateZAxis(1.0f);
	}
	if (Input::GetKey(KeyCode::NUMPAD_3))
	{
		enano->transform.RotateZAxis(-1.0f);
	}

	if (GetCollisionManager()->CheckCollision(illuminati, enano))
	{
		std::cout << "Ah re loco" << std::endl;
	}

	if (GetCollisionManager()->CheckCollision(shape, enano))
	{
		std::cout << "Harry esta mas turbado que nunca" << std::endl;
	}

	illuminati->Draw();
	shape->Draw();
	rock->Draw();
	enano->Draw();
}

void Game::DeInit()
{
	delete shape;
	delete rock;
	delete enano;
	delete illuminati;
}
