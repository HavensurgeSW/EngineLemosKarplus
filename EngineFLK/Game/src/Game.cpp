#include "Game.h"

void Game::Init()
{
	showTilemap = false;
	tilemap = new Tilemap();
	tilemap->SetTileID(0, 0, 1);
	tilemap->SetTileID(1, 0, 1);
	tilemap->SetTileID(2, 0, -1);
	tilemap->SetTileID(0, 1, -1);
	tilemap->SetTileID(1, 1, 1);
	tilemap->SetTileID(2, 1, 1);
	tilemap->SetTileID(0, 2, 1);
	tilemap->SetTileID(1, 2, 1);
	tilemap->SetTileID(2, 2, -1);

	Shader shapeShader("res/shaders/Shape.shader");
	shape = new Shape(shapeShader, PrimitiveType::QUAD);
	shape->SetVertexColor(Color::Red(), Color::Yellow(), Color::Red(), Color::Yellow());

	Shader enanoShader("res/shaders/Sprite.shader");
	enano = new Sprite(enanoShader);
	enano->SetVertexColor(Color::Blue(), Color::Yellow(), Color::Blue(), Color::Yellow());
	enano->SetTexture("res/textures/EnanoBostero.png");

	Shader playerShader("res/shaders/Sprite.shader");
	player = new Sprite(playerShader);
	player->SetTexture("res/textures/amogus.png");

	Shader illuminatiShader("res/shaders/Sprite.shader");
	illuminati = new Sprite(illuminatiShader);
	illuminati->SetTexture("res/textures/illuminati.png");
	illuminati->SetColorTint(Color::White());

	Shader rockShader("res/shaders/Sprite.shader");
	rock = new AnimatedSprite(rockShader, { 32, 5 });

	rock->SetTexture("res/spritesheets/rock-min.png");
	//rock->SetTexture("res/spritesheets/rock.png");
	rock->AddAnimation("JOHN_CHINA", 4.0f, 0, 31, true);   //
	rock->AddAnimation("SUSSY_BOOM", 1.0f, 32, 41, true);  //
	rock->AddAnimation("BOOM", 1.0f, 64, 73, true);        // Animations look fucked because the spritesheet 
	rock->AddAnimation("Eyebrow", 1.5f, 96, 113, true);	   // is not properly done(idk why photoshop played me)
	rock->AddAnimation("Approve", 2.0f, 128, 151, true);   //
	rock->SetCurrentAnimation("JOHN_CHINA");               //

	shape->transform.SetPosition({ -0.7f, 0.0f });
	shape->transform.SetRotation(-45.0f, { 0.0f, 0.0f, 1.0f });
	shape->transform.SetScale(0.3f);

	illuminati->transform.SetPosition({ 0.0f, 0.5f });
	illuminati->transform.SetRotation(0.0f, { 0.0f, 0.0f, 1.0f });
	illuminati->transform.SetScale(0.6f);

	enano->transform.SetPosition(0.7f, 0.0f, 0.0f);
	enano->transform.SetScale(0.6f);

	player->transform.SetPosition({ 0.0f, 0.0f, 0.0f });
	player->transform.SetScale(0.45f);

	rock->transform.SetPosition(0.0f, -0.5f, 0.0f);
	rock->transform.SetScale(0.6f + 0.3f);
}

void Game::Update()
{
	if (Input::GetKey(KeyCode::NUMPAD_1)) 
	{
		showTilemap = true;
	}

	if (Input::GetKey(KeyCode::NUMPAD_2))
	{
		showTilemap = false;
	}

	if (!showTilemap) 
	{
		if (GetCollisionManager()->CheckCollision(illuminati, enano))
		{
			std::cout << "Ah re loco" << std::endl;
		}

		if (GetCollisionManager()->CheckCollision(shape, enano))
		{
			std::cout << "Harry esta mas turbado que nunca" << std::endl;
		}

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

		illuminati->Draw();
		shape->Draw();
		rock->Draw();
		enano->Draw();
	}
	else
	{
		//if (GetCollisionManager()->CheckCollision(player, enano))
		//{
		//	std::cout << "Harry esta mas turbado que nunca" << std::endl;
		//}

		if (Input::GetKey(KeyCode::W))
		{
			player->transform.Translate({ 0, 0.01f, 0 });
		}
		if (Input::GetKey(KeyCode::S))
		{
			player->transform.Translate({ 0, -0.01f, 0 });
		}
		if (Input::GetKey(KeyCode::D))
		{
			player->transform.Translate({ 0.01f, 0, 0 });
		}
		if (Input::GetKey(KeyCode::A))
		{
			player->transform.Translate({ -0.01f,0,0 });
		}

		tilemap->Draw();
		player->Draw();
	}	
}

void Game::DeInit()
{
	delete shape;
	delete rock;
	delete enano;
	delete illuminati;
}
