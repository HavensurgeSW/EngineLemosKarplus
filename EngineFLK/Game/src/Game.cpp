#include "Game.h"

void Game::Init()
{
	Shader shapeShader("res/shaders/Shape.shader");
	shape = new Shape(GetRenderer(), shapeShader, ShapeType::QUAD);
	shape->SetVertexColor(Color::Red(), Color::Yellow(), Color::Red(), Color::Yellow());

	Shader enanoShader("res/shaders/Sprite.shader");
	enano = new Sprite(GetRenderer(), enanoShader);
	enano->SetVertexColor(Color::Green(), Color::Red(), Color::Blue(), Color::Yellow());
	enano->SetTexture("res/textures/EnanoBostero.png");

	Shader illuminatiShader("res/shaders/Sprite.shader");
	illuminati = new Sprite(GetRenderer(), illuminatiShader);
	illuminati->SetTexture("res/textures/illuminati.png");
	illuminati->SetColorTint(Color::White());

	Shader rockShader("res/shaders/Sprite.shader");
	rock = new AnimatedSprite(GetRenderer(), rockShader, {12, 2});
	rock->SetTexture("res/spritesheets/RockSpritesheet2.png");
	rock->AddAnimation("VibeCheck", 1.0f, 0, 11, true);
	rock->AddAnimation("BOOM", 1.0f, 12, 22, true);
	rock->SetCurrentAnimation("BOOM");

	shape->transform.SetPosition({ -0.7f, 0.0f });
	shape->transform.SetRotation(-45.0f, { 0.0f, 0.0f, 1.0f });
	shape->transform.SetScale(0.3f);

	illuminati->transform.SetPosition({ 0.0f, 0.5f });
	illuminati->transform.SetRotation(0.0f, { 0.0f, 0.0f, 1.0f });
	illuminati->transform.SetScale(0.6f);

	enano->transform.SetPosition(0.7f, 0.0f, 0.0f);
	enano->transform.SetScale(0.6f);

	rock->transform.SetPosition(0.0f, -0.5f, 0.0f);
	rock->transform.SetScale(0.6f + 0.3f);
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
