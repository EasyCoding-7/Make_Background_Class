#pragma once
class Background {

private:
	Sprite* cloud[2];
	Sprite* bush[2];
	Sprite* tile[2];


public:
	Background(wstring ShaderFile);
	~Background();
	void Update(D3DXMATRIX& V,D3DXMATRIX& P);
	void Render();

};