#include "Game.h"

void Game::Init()
{
	

	Shader grassShader("res/shaders/Sprite.shader");
	
	tilemap = new Tilemap("res/spritesheets/grassTiles.png", { 256,256 }, { 32,32 }, {6,5}, grassShader);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(0, 0), 62);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(0, 1), 56);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(0, 2), 62);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(0, 3), 24);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(0, 4), 52);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(1, 0), 55);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(1, 1), 8);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(1, 2), 56);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(1, 3), 24);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(1, 4), 2);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(2, 0), 55);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(2, 1), 8);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(2, 2), 55);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(2, 3), 24);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(2, 4), 26);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(3, 0), 55);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(3, 1), 8);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(3, 2), 56);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(3, 3), 24);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(3, 4), 42);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(4, 0), 56);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(4, 1), 3);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(4, 2), 56);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(4, 3), 24);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(4, 4), 12);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(5, 0), 56);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(5, 1), 3);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(5, 2), 62);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(5, 3), 47);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(5, 4), 12);

	tilemap->getTile(0,3)->SetIsWalkable(false);


	

	Shader shapeShader("res/shaders/Shape.shader");
	shape = new Shape(shapeShader, PrimitiveType::QUAD);
	shape->SetVertexColor(Color::Red(), Color::Yellow(), Color::Red(), Color::Yellow());

	Shader enanoShader("res/shaders/Sprite.shader");
	enano = new Sprite(enanoShader);
	enano->SetVertexColor(Color::Blue(), Color::Yellow(), Color::Blue(), Color::Yellow());
	enano->SetTexture("res/textures/EnanoBostero.png");

	Shader playerShader("res/shaders/Sprite.shader");
	player = new Sprite(playerShader);
	player->SetTexture("res/textures/ghost.png");

	p1.tex = new Sprite(playerShader);
	p1.tex->SetTexture("res/textures/ghost.png");
	p1.tex->SetColorTint(Color::Red());
	p1.pos = { 0,0 };

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

	player->transform.SetPosition(tilemap->getTile(0, 0)->transform.GetPosition());
	
	player->transform.SetScale(0.125f);
	player->SetColorTint(Color::White());
	p1.tex->transform.SetScale(0.125f);

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
		//tilemap->Draw();
	}
	else
	{
		

		if (Input::GetKey(KeyCode::W))
		{
			player->transform.Translate({ 0, 0.005f, 0 });
		}
		if (Input::GetKey(KeyCode::S))
		{
			player->transform.Translate({ 0, -0.005f, 0 });
		}
		if (Input::GetKey(KeyCode::D))
		{
			player->transform.Translate({ 0.005f, 0, 0 });
		}
		if (Input::GetKey(KeyCode::A))
		{
			player->transform.Translate({ -0.005f,0,0 });
		}

		if (Input::GetKey(KeyCode::UP))
		{
			if (tilemap->getTile(p1.pos.x, p1.pos.y + 1)->GetIsWalkable()){
				p1.pos.y++;
				p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
			}
		}
		if (Input::GetKey(KeyCode::DOWN))
		{
			if (tilemap->getTile(p1.pos.x, p1.pos.y - 1)->GetIsWalkable()){
				p1.pos.y--;
				p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
			}

		}
		if (Input::GetKey(KeyCode::RIGHT))
		{
			if (tilemap->getTile(p1.pos.x + 1, p1.pos.y)->GetIsWalkable()) {
				p1.pos.x++;
				p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
			}
		}
		if (Input::GetKey(KeyCode::LEFT))
		{
			if (tilemap->getTile(p1.pos.x - 1, p1.pos.y)->GetIsWalkable()){
				p1.pos.x--;
				p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
			}
		}


		tilemap->Draw();
		player->Draw();
		p1.tex->Draw();
	}	
}

void Game::DeInit()
{
	delete shape;
	delete rock;
	delete enano;
	delete illuminati;
	delete player;
	delete tilemap;
}
