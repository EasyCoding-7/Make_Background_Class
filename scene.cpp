#include "stdafx.h"
#include "./System/Device.h"
#include "./Object/Background.h"

//Sprite* mario;
Background* background;
Sprite* allMario;


D3DXMATRIX V, P;

void InitScene()
{
	wstring shaderFile = L"./_Shader2D/Effect.fx";

	//mario = new Sprite(L"./_Textures/mario.png", shaderFile);
	//mario->Position(100, 100);
	background = new Background(shaderFile);

	allMario = new Sprite(L"./_Textures/spriteMario.png", shaderFile, 2, 173, 52, 244);
	allMario->Position(300, 300);
}

void DestroyScene()
{
	//SAFE_DELETE(mario);
	SAFE_DELETE(background);
	SAFE_DELETE(allMario);
	
}


void Update()
{

	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Projection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);


	allMario->Update(V, P);
	background->Update(V, P);
}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(1, 1, 1, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{   
		allMario->Render();
		background->Render();
		
	}
	ImGui::Render();
	SwapChain->Present(0, 0);
}