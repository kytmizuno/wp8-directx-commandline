﻿#pragma once

#include "Direct3DBase.h"

#include "Mesh.h"

struct ModelViewProjectionConstantBuffer
{
	DirectX::XMFLOAT4X4 model;
	DirectX::XMFLOAT4X4 view;
	DirectX::XMFLOAT4X4 projection;
};

// This class renders a simple spinning cube.
ref class CubeRenderer sealed : public Direct3DBase
{
public:
	CubeRenderer();

	// Direct3DBase methods.
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;
	virtual void Render() override;
	
	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);

private:
	void			updateProjection();
	bool m_loadingComplete;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_vertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_indexBuffer;
	Microsoft::WRL::ComPtr<ID3D11VertexShader> m_vertexShader;
	Microsoft::WRL::ComPtr<ID3D11PixelShader> m_pixelShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer> m_constantBuffer;

	ID3D11ShaderResourceView*				m_pTextures[ 2 ];
	//Microsoft::WRL::ComPtr<ID3D11Texture2D>	m_texture;

	uint32 m_indexCount;
	ModelViewProjectionConstantBuffer m_constantBufferData;

	float			m_fov;
	float			m_rotX;
	float			m_rotZ;


	Mesh*			m_pMesh;
	Mesh*			m_pCheckerMesh;
};