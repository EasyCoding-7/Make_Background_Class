#pragma once
class Sprite{

	Shader* shader;
	ID3D11Buffer* vertexBuffer;

	D3DXVECTOR2 position;//world position
	D3DXVECTOR2 scale;

	wstring textureFile;
	ID3D11ShaderResourceView* srv;

private:
	struct Vertex {
		D3DXVECTOR3 Position;//vertex position
		D3DXVECTOR2 Uv;
	};
private:
	void UpdateWorld();
	void Initialize(wstring spriteFile, wstring shaderFile, float startX, float startY, float endX, float endY);
public:
	Sprite(wstring textureFile, wstring shaderFile);
	Sprite(wstring textureFile ,wstring shaderFile, float endX, float endY);
	Sprite(wstring textureFile, wstring shaderFile, float startX,float stratY,float endX, float endY);
	virtual ~Sprite(); //상속대비
 
	virtual void Update(D3DXMATRIX& V, D3DXMATRIX& P); //overrding
	virtual void Render();

public:
	void Position(float x, float y);
	void Position(D3DXVECTOR2& vec);
	D3DXVECTOR2 Position() { return position; };

	void Scale(float x, float y);
	void Scale(D3DXVECTOR2& vec);
	D3DXVECTOR2 Scale() { return scale; };


};

////////////////////////////////////////////////////////////////////////////////////////////////////////
class Sprites 
{
private:
	friend class Sprite; // 모든 sprite가 sprites의 모든 private를 사용할수 있음 
private:
	static ID3D11ShaderResourceView* Load(wstring file);
	static void Remove(wstring file);
private:
	struct SpriteDesc {
		UINT RefCount = 0;
		ID3D11ShaderResourceView* SRV = NULL;
	};
	
	static map<wstring, SpriteDesc> spriteMap; //모든static 변수는 cpp 파일에 다시한번 선언  map<wstring, Sprites::SpriteDesc> Sprites::spriteMap;


};