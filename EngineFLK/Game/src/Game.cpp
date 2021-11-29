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
	rock = new Sprite(GetRenderer(), rockShader);
	rock->SetTexture("res/textures/TheRock.png");

	Vector2 trianglePosition(0.0f, -0.5f);
	float triangleRotationSpeed = -45.0f;
	Vector3 triangleRotation(0.0f, 0.0f, 1.0f);
	Vector2 quadPosition(0.0f, 0.5f);
	float quadRotationSpeed = 0.0f;
	Vector3 quadRotation(0.0f, 0.0f, 1.0f);
	float scale = 0.6f;

	shape->transform.SetPosition(trianglePosition);
	shape->transform.SetRotation(triangleRotationSpeed, triangleRotation);
	shape->transform.SetScale(scale);

	illuminati->transform.SetPosition(quadPosition);
	illuminati->transform.SetRotation(quadRotationSpeed, quadRotation);
	illuminati->transform.SetScale(scale);

	enano->transform.SetPosition(0.7f, 0, 0);
	enano->transform.SetScale(scale);

	rock->transform.SetPosition(-0.7f, 0, 0);
	rock->transform.SetScale(scale);
}

void Game::Update()
{
	if (Input::GetKey(KeyCode::W))
	{
		shape->transform.Translate({ 0, 0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::S))
	{
		shape->transform.Translate({ 0, -0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::D))
	{
		shape->transform.Translate({ 0.01f, 0, 0 });
	}
	if (Input::GetKey(KeyCode::A))
	{
		shape->transform.Translate({ -0.01f,0,0 });
	}
	if (Input::GetKey(KeyCode::Q))
	{
		shape->transform.RotateZAxis(1.0f);
	}
	if (Input::GetKey(KeyCode::E))
	{
		shape->transform.RotateZAxis(-1.0f);
	}

	if (Input::GetKey(KeyCode::UP))
	{
		illuminati->transform.Translate({ 0, 0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::DOWN))
	{
		illuminati->transform.Translate({ 0, -0.01f, 0 });
	}
	if (Input::GetKey(KeyCode::RIGHT))
	{
		illuminati->transform.Translate({ 0.01f, 0, 0 });
	}
	if (Input::GetKey(KeyCode::LEFT))
	{
		illuminati->transform.Translate({ -0.01f, 0, 0 });
	}
	if (Input::GetKey(KeyCode::NUMPAD_1))
	{
		illuminati->transform.RotateZAxis(1.0f);
	}
	if (Input::GetKey(KeyCode::NUMPAD_3))
	{
		illuminati->transform.RotateZAxis(-1.0f);
	}

	if (GetCollisionManager()->CheckCollision(illuminati, enano))
	{
		std::cout << "Ah re loco" << std::endl;
	}

	if (GetCollisionManager()->CheckCollision(shape, enano))
	{
		std::cout << "Harry esta mas turbado que nunca" << std::endl;
	}

	shape->Draw();
	illuminati->Draw();
	enano->Draw();
	rock->Draw();
}

void Game::DeInit()
{
	delete shape;
	delete rock;
	delete enano;
	delete illuminati;
}
