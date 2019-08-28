#include"stdafx.h"
#include"Background.h"

Background::Background(wstring shaderFile)
{
	wstring textureFile = L"";
	//cloud
	textureFile = L"./_Textures/Cloud.png";
	cloud[0] = new Sprite(textureFile, shaderFile, 137, 128);
	cloud[1] = new Sprite(textureFile, shaderFile, 144, 0,336,128);
	//bush
	textureFile = L"./_Textures/Bush.png";
	bush[0] = new Sprite(textureFile,shaderFile);
	textureFile = L"./_Textures/Bush2.png";
	bush[1] = new Sprite(textureFile, shaderFile);
	//tile
	textureFile = L"./_Textures/Tile.png";
	tile[0] = new Sprite(textureFile,shaderFile);
	tile[1] = new Sprite(textureFile, shaderFile,0,66,128,128);//흙


}

Background::~Background()
{
	SAFE_DELETE(cloud[0]);
	SAFE_DELETE(cloud[1]);
	SAFE_DELETE(bush[0]);
	SAFE_DELETE(bush[1]);
	SAFE_DELETE(tile[0]);
	SAFE_DELETE(tile[1]);
}

void Background::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	cloud[0]->Update(V, P);
	cloud[1]->Update(V, P);

	bush[0]->Update(V, P);
	bush[1]->Update(V, P);

	tile[0]->Update(V, P);
	tile[1]->Update(V, P);

}

void Background::Render()
{
	//world를 이용해서 여러개를 찍어보자
	cloud[0]->Position(40, 420);
	cloud[0]->Render();

	cloud[0]->Position(200, 420);
	cloud[0]->Render();

	cloud[1]->Position(500, 420);
	cloud[1]->Render();

	bush[1]->Position(-50, 170);
	bush[1]->Render();
	bush[1]->Position(300, 170);
	bush[1]->Render();
	bush[1]->Position(600, 170);
	bush[1]->Render();

	bush[0]->Position(100, 170);
	bush[0]->Render();
	bush[0]->Position(650, 170);
	bush[0]->Render();

	float tileWidth = tile[0]->Scale().x;
	//float tileWidth2 = tile[1]->Scale().x;
	for (int i = 0; i < 8; i++) {

		tile[0]->Position((float)i*tileWidth, 45);
		tile[0]->Render();

		tile[1]->Position((float)i*tileWidth, 0);
		tile[1]->Render();
	}
}
