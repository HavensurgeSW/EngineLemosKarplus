#include "Game.h"

void Game::Init()
{
	

	Shader grassShader("res/shaders/Sprite.shader");
	
	Vector2 mapSize = { 5,5 };
	Vector2 sheetPXSize = { 256,256 };
	Vector2 tilePXSize = { 32,32 };
	std::vector<int> mapFile;
	tilemap = new Tilemap("res/spritesheets/grassTiles.png", sheetPXSize, tilePXSize, mapSize, grassShader);
	tilemap->SetCollisionManager(GetCollisionManager());

	for (int i = 0; i < mapSize.x*mapSize.y; i++)
	{
		int random = std::rand() % static_cast<int>(((sheetPXSize.x * sheetPXSize.y) / (tilePXSize.x * tilePXSize.y)));
		mapFile.push_back(random); //This vector NEEDS to be the same size as the map dimensions (15,15 in this case)
	}

	tilemap->GenerateMapFromVec(mapFile);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(0, 0), 0);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(0, 1), 0);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(1, 0), 0);
	tilemap->getSheet()->SetTilebyID(tilemap->getTile(1, 1), 0);
	tilemap->getTile(2, 2)->SetIsWalkable(false);
	


	Shader playerShader("res/shaders/Sprite.shader");
	p1.tex = new Sprite(playerShader);
	p1.tex->SetTexture("res/textures/ghost.png");
	p1.tex->SetColorTint(Color::White());
	p1.pos = { 0,0 };
	p1.bounds.x = mapSize.x-1;
	p1.bounds.y = mapSize.y - 1;
	p1.tex->transform.SetScale(0.0625f);
	p1.pos.x = 2;
	p1.pos.y = 2;
	p1.tex->transform.SetPosition(tilemap->getTile(0, 0)->transform.GetPosition());
	

	Shader shapeShader("res/shaders/Shape.shader");
	shape = new Shape(shapeShader, PrimitiveType::QUAD);
	shape->SetVertexColor(Color::Red(), Color::Yellow(), Color::Red(), Color::Yellow());

	Shader enanoShader("res/shaders/Sprite.shader");
	enano = new Sprite(enanoShader);
	enano->SetVertexColor(Color::Blue(), Color::Yellow(), Color::Blue(), Color::Yellow());
	enano->SetTexture("res/textures/EnanoBostero.png");


	Shader illuminatiShader("res/shaders/Sprite.shader");
	illuminati = new Sprite(illuminatiShader);
	illuminati->SetTexture("res/textures/illuminati.png");
	illuminati->SetColorTint(Color::White());

	Shader rockShader("res/shaders/Sprite.shader");
	rock = new AnimatedSprite(rockShader, { 32, 5 });

	rock->SetTexture("res/spritesheets/rock-min.png");
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
			std::cout << "Collision between Illuminati and Enano" << std::endl;
		}

		if (GetCollisionManager()->CheckCollision(shape, enano))
		{
			std::cout << "Collision between shape and Enano" << std::endl;
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
		if (tilemap->CheckTileCollisions(p1.tex)) {
			p1.tex->transform.SetPosition(p1.tex->transform.GetPrevPosition());
		}
	
		/*if (Input::GetKey(KeyCode::UP))
		{
			if(p1.pos.y < p1.bounds.y)
			if (tilemap->getTile(p1.pos.x, p1.pos.y+1)->GetIsWalkable()) {
				p1.pos.y++;
				p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
			}
			
		}
		if (Input::GetKey(KeyCode::DOWN))
		{
			if (p1.pos.y >	0)
				if (tilemap->getTile(p1.pos.x, p1.pos.y - 1)->GetIsWalkable()) {
					p1.pos.y--;
					p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
				}

		}
		if (Input::GetKey(KeyCode::RIGHT))
		{
			if (p1.pos.x < p1.bounds.x)
				if (tilemap->getTile(p1.pos.x+1, p1.pos.y)->GetIsWalkable()) {
					p1.pos.x++;
					p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
				}
		}
		if (Input::GetKey(KeyCode::LEFT))
		{
			if (p1.pos.x > 0)
				if (tilemap->getTile(p1.pos.x-1, p1.pos.y)->GetIsWalkable()) {
					p1.pos.x--;
					p1.tex->transform.SetPosition({ (0.125f * p1.pos.x) - 0.875f,(0.125f * p1.pos.y) - 0.875f, 0.0f });
				}
		}*/

		if (Input::GetKey(KeyCode::UP)) {
			p1.tex->transform.Translate({ 0, 0.01f, 0 });
		}
		if (Input::GetKey(KeyCode::DOWN)) {
			p1.tex->transform.Translate({ 0, -0.01f, 0 });
		}
		if (Input::GetKey(KeyCode::RIGHT)) {
			p1.tex->transform.Translate({ 0.01f, 0.0f, 0 });
		}
		if (Input::GetKey(KeyCode::LEFT)) {
			p1.tex->transform.Translate({ -0.01f, 0.0f, 0 });
		}

		tilemap->Draw();
		p1.tex->Draw();
	}	
}

void Game::DeInit()
{
	delete shape;
	delete rock;
	delete enano;
	delete illuminati;
	delete tilemap;
}
