/* 
 * Copyright (C) 2012 Yee Young Han <websearch@naver.com> (http://blog.naver.com/websearch)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#include "stdafx.h"
#include "DirectXCube.h"

CDirectXCube::CDirectXCube() : m_fTheta(1.5f * XM_PI), m_fPhi(1.25f * XM_PI), m_fRadius(5.0f)
{
}

CDirectXCube::~CDirectXCube()
{
}

/**
 * @ingroup TestTriangle
 * @brief �ﰢ���� �׸��� ���� �غ� �۾��� �����Ѵ�.
 * @returns �����ϸ� true �� �����ϰ� �׷��� ������ false �� �����Ѵ�.
 */
bool CDirectXCube::CreateChild()
{
	// ť�� ���� ����
	Vertex arrCube[] =
	{
		// �ո� (������)
		{ XMFLOAT3(  0.5f,  0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f,  0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f,  0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f, -0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 0.0f, 1.0f ) },
		
		// �޸� (�����)
		{ XMFLOAT3(  0.5f,  0.5f, -0.5f ), XMFLOAT4( 1.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f, -0.5f, -0.5f ), XMFLOAT4( 1.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f, -0.5f ), XMFLOAT4( 1.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f,  0.5f, -0.5f ), XMFLOAT4( 1.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f, -0.5f ), XMFLOAT4( 1.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f,  0.5f, -0.5f ), XMFLOAT4( 1.0f, 1.0f, 0.0f, 1.0f ) },

		// ���� �� (�Ķ���)
		{ XMFLOAT3( -0.5f,  0.5f,  0.5f ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f, -0.5f ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f,  0.5f ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f,  0.5f,  0.5f ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f,  0.5f, -0.5f ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f, -0.5f ), XMFLOAT4( 0.0f, 0.0f, 1.0f, 1.0f ) },

		// ������ �� (�����)
		{ XMFLOAT3(  0.5f,  0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f, -0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f,  0.5f, -0.5f ), XMFLOAT4( 1.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f,  0.5f, -0.5f ), XMFLOAT4( 1.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f, -0.5f,  0.5f ), XMFLOAT4( 1.0f, 0.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f, -0.5f, -0.5f ), XMFLOAT4( 1.0f, 0.0f, 1.0f, 1.0f ) },

		// ���� (���)
		{ XMFLOAT3(  0.5f,  0.5f,  0.5f ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f,  0.5f, -0.5f ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f,  0.5f, -0.5f ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f,  0.5f,  0.5f ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f,  0.5f, -0.5f ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f,  0.5f,  0.5f ), XMFLOAT4( 0.0f, 1.0f, 0.0f, 1.0f ) },

		// �Ʒ��� (�ϴû�)
		{ XMFLOAT3(  0.5f, -0.5f,  0.5f ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f, -0.5f ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f, -0.5f, -0.5f ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3(  0.5f, -0.5f,  0.5f ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f,  0.5f ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) },
		{ XMFLOAT3( -0.5f, -0.5f, -0.5f ), XMFLOAT4( 0.0f, 1.0f, 1.0f, 1.0f ) }
	};

	// ���� ���۸� �����Ѵ�.
	D3D11_BUFFER_DESC sttBD;
  
	sttBD.Usage = D3D11_USAGE_IMMUTABLE;
  sttBD.ByteWidth = sizeof(Vertex) * 36;
  sttBD.BindFlags = D3D11_BIND_VERTEX_BUFFER;
  sttBD.CPUAccessFlags = 0;
  sttBD.MiscFlags = 0;
	sttBD.StructureByteStride = 0;

  D3D11_SUBRESOURCE_DATA sttSRD;
  sttSRD.pSysMem = arrCube;
  
	CHECK_FAILED( m_pclsDevice->CreateBuffer( &sttBD, &sttSRD, &m_pclsVB ) );

	// 
	if( CreateEffect( "FX/color.fxo", &m_pclsEffect ) == false ) return false;

	m_pclsEffectTech = m_pclsEffect->GetTechniqueByName("ColorTech");
	m_pclsWorldViewProj = m_pclsEffect->GetVariableByName("gWorldViewProj")->AsMatrix();

	D3D11_INPUT_ELEMENT_DESC arrVertexDesc[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	D3DX11_PASS_DESC sttPassDesc;

	m_pclsEffectTech->GetPassByIndex(0)->GetDesc( &sttPassDesc );
	CHECK_FAILED( m_pclsDevice->CreateInputLayout( arrVertexDesc, 2, sttPassDesc.pIAInputSignature, sttPassDesc.IAInputSignatureSize, &m_pclsInputLayout ) );

	XMMATRIX sttI = XMMatrixIdentity();
	XMStoreFloat4x4( &m_sttWorld, sttI );
	XMStoreFloat4x4( &m_sttView, sttI );

	XMMATRIX sttP = XMMatrixPerspectiveFovLH( 0.25f * XM_PI, 1.0f, 1.0f, 1000.0f );
	XMStoreFloat4x4( &m_sttProj, sttP );

	return true;
}

/**
 * @ingroup TestTriangle
 * @brief �ﰢ���� ȭ�鿡 �׷��ش�.
 * @returns �����ϸ� true �� �����ϰ� �׷��� ������ false �� �����Ѵ�.
 */
bool CDirectXCube::DrawChild()
{
	m_pclsContext->IASetInputLayout( m_pclsInputLayout );

	UINT iStride = sizeof(Vertex);
  UINT iOffset = 0;

  m_pclsContext->IASetVertexBuffers( 0, 1, &(m_pclsVB.p), &iStride, &iOffset );

	XMMATRIX world = XMLoadFloat4x4( &m_sttWorld );
	XMMATRIX view  = XMLoadFloat4x4( &m_sttView );
	XMMATRIX proj  = XMLoadFloat4x4( &m_sttProj );
	XMMATRIX worldViewProj = world * view * proj;

	m_pclsWorldViewProj->SetMatrix( reinterpret_cast<float*>(&worldViewProj) );

	D3DX11_TECHNIQUE_DESC sttTechDesc;
	m_pclsEffectTech->GetDesc( &sttTechDesc );

	for( UINT p = 0; p < sttTechDesc.Passes; ++p )
	{
		m_pclsEffectTech->GetPassByIndex(p)->Apply( 0, m_pclsContext );
		m_pclsContext->Draw( 36, 0 );
	}

	return true;
}

bool CDirectXCube::Update()
{
	float x = m_fRadius * sinf( m_fPhi ) * cosf( m_fTheta );
	float z = m_fRadius * sinf( m_fPhi ) * sinf( m_fTheta );
	float y = m_fRadius * cosf( m_fPhi );

	// ī�޶� ��ġ
	//XMVECTOR pos = XMVectorSet( x, y, z, 1.0f );
	XMVECTOR pos = XMVectorSet( 5.0f, 5.0f, 5.0f, 1.0f );

	// ť�� ��ġ
	XMVECTOR target = XMVectorZero();

	// ī�޶� Ÿ���� �ٶ� ���� ���� ����.
	XMVECTOR up = XMVectorSet( 0.0f, 1.0f, 0.0f, 0.0f );

	// ī�޶� ��ġ�� ī�޶� ť�긦 �ٶ󺸴� ������ �̿��Ͽ��� View ����� �����Ѵ�.
	XMMATRIX view = XMMatrixLookAtLH( pos, target, up );

	XMStoreFloat4x4( &m_sttView, view );

	return true;
}