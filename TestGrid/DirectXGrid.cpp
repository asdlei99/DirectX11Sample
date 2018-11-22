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
#include "DirectXGrid.h"
#include "trace.h"
#include "check.h"

CDirectXGrid::CDirectXGrid() : m_bMouseDown(false)
{
	memset( &m_sttMousePos, 0, sizeof(m_sttMousePos) );
}

CDirectXGrid::~CDirectXGrid()
{
}

/**
 * @ingroup TestGrid
 * @brief �ﰢ���� �׸��� ���� �غ� �۾��� �����Ѵ�.
 * @returns �����ϸ� true �� �����ϰ� �׷��� ������ false �� �����Ѵ�.
 */
bool CDirectXGrid::CreateChild()
{
	// ť�� ���� ����
	VertexPosNormalTexture arrCube[] =
	{
		// �ո�
		{ XMFLOAT3(  0.5,  0.5,  0.5 ), XMFLOAT3(  1.0,  1.0,  1.0 ), XMFLOAT2( 0.0f, 0.0f ) },	// index 0
		{ XMFLOAT3(  0.5, -0.5,  0.5 ), XMFLOAT3(  1.0, -2.0,  1.0 ), XMFLOAT2( 0.0f, 1.0f ) },	// index 1
		{ XMFLOAT3( -0.5, -0.5,  0.5 ), XMFLOAT3( -1.0, -1.0,  2.0 ), XMFLOAT2( 1.0f, 1.0f ) },	// index 2
		{ XMFLOAT3( -0.5,  0.5,  0.5 ), XMFLOAT3( -2.0,  1.0,  1.0 ), XMFLOAT2( 1.0f, 0.0f ) },	// index 3

		// �޸�
		{ XMFLOAT3(  0.5,  0.5, -0.5 ), XMFLOAT3(  1.0,  1.0, -2.0 ), XMFLOAT2( 1.0f, 0.0f ) },	// index 4
		{ XMFLOAT3(  0.5, -0.5, -0.5 ), XMFLOAT3(  2.0, -1.0, -1.0 ), XMFLOAT2( 1.0f, 1.0f ) },	// index 5
		{ XMFLOAT3( -0.5, -0.5, -0.5 ), XMFLOAT3( -1.0, -1.0, -1.0 ), XMFLOAT2( 0.0f, 1.0f ) },	// index 6
		{ XMFLOAT3( -0.5,  0.5, -0.5 ), XMFLOAT3( -1.0,  2.0, -1.0 ), XMFLOAT2( 0.0f, 0.0f ) },	// index 7

		// ���ʸ�
		{ XMFLOAT3( -0.5,  0.5,  0.5 ), XMFLOAT3( -2.0,  1.0,  1.0 ), XMFLOAT2( 0.0f, 0.0f ) },	// index 8
		{ XMFLOAT3( -0.5, -0.5,  0.5 ), XMFLOAT3( -1.0, -1.0,  2.0 ), XMFLOAT2( 0.0f, 1.0f ) },	// index 9
		{ XMFLOAT3( -0.5, -0.5, -0.5 ), XMFLOAT3( -1.0, -1.0, -1.0 ), XMFLOAT2( 1.0f, 1.0f ) },	// index 10
		{ XMFLOAT3( -0.5,  0.5, -0.5 ), XMFLOAT3( -2.0,  1.0, -1.0 ), XMFLOAT2( 1.0f, 0.0f ) },	// index 11

		// �����ʸ�
		{ XMFLOAT3(  0.5,  0.5,  0.5 ), XMFLOAT3(  1.0,  1.0,  1.0 ), XMFLOAT2( 1.0f, 0.0f ) },	// index 12
		{ XMFLOAT3(  0.5, -0.5,  0.5 ), XMFLOAT3(  1.0, -2.0,  1.0 ), XMFLOAT2( 1.0f, 1.0f ) },	// index 13
		{ XMFLOAT3(  0.5, -0.5, -0.5 ), XMFLOAT3(  2.0, -1.0, -1.0 ), XMFLOAT2( 0.0f, 1.0f ) },	// index 14
		{ XMFLOAT3(  0.5,  0.5, -0.5 ), XMFLOAT3(  1.0,  1.0, -2.0 ), XMFLOAT2( 0.0f, 0.0f ) },	// index 15

		// ����
		{ XMFLOAT3(  0.5,  0.5,  0.5 ), XMFLOAT3(  1.0,  1.0,  1.0 ), XMFLOAT2( 1.0f, 0.0f ) },	// index 16
		{ XMFLOAT3(  0.5,  0.5, -0.5 ), XMFLOAT3(  1.0,  1.0, -2.0 ), XMFLOAT2( 1.0f, 1.0f ) },	// index 17
		{ XMFLOAT3( -0.5,  0.5, -0.5 ), XMFLOAT3( -1.0,  2.0, -1.0 ), XMFLOAT2( 0.0f, 1.0f ) },	// index 18
		{ XMFLOAT3( -0.5,  0.5,  0.5 ), XMFLOAT3( -2.0,  1.0,  1.0 ), XMFLOAT2( 0.0f, 0.0f ) },	// index 19

		// �Ʒ���
		{ XMFLOAT3(  0.5, -0.5,  0.5 ), XMFLOAT3(  1.0, -2.0,  1.0 ), XMFLOAT2( 0.0f, 0.0f ) },	// index 20
		{ XMFLOAT3(  0.5, -0.5, -0.5 ), XMFLOAT3(  2.0, -1.0, -1.0 ), XMFLOAT2( 0.0f, 1.0f ) },	// index 21
		{ XMFLOAT3( -0.5, -0.5, -0.5 ), XMFLOAT3( -1.0, -1.0, -1.0 ), XMFLOAT2( 1.0f, 1.0f ) },	// index 22
		{ XMFLOAT3( -0.5, -0.5,  0.5 ), XMFLOAT3( -1.0, -1.0,  2.0 ), XMFLOAT2( 1.0f, 0.0f ) }	// index 23
	};

	UINT arrIndex[] =
	{
		// �ո�
		0, 2, 1,
		0, 3, 2,

		// �޸�
		4, 6, 7,
		4, 5, 6,

		// ���ʸ�
		8, 10, 9,
		8, 11, 10,

		// �����ʸ�
		12, 13, 14,
		12, 14, 15,

		// ����
		16, 17, 18,
		16, 18, 19,

		// �Ʒ���
		20, 22, 21,
		20, 23, 22
	};

	// �������� ���͸� ���� ���ͷ� �����Ѵ�.
	int iVertexCount = _countof(arrCube);
	XMVECTOR vN;
		
	for( int i = 0; i < iVertexCount; ++i )
	{
		vN = XMLoadFloat3( &arrCube[i].Normal );
		vN = XMVector3Normalize( vN );
		XMStoreFloat3( &arrCube[i].Normal, vN );
	}

	// �����ϵ� fx ������ �α��Ѵ�.
	if( m_clsEffect.Create( m_pclsDevice, m_pclsContext, "FX/texture.fxo" ) == false ) return false;

	m_clsFigure.SetDevice( m_pclsDevice, m_pclsContext, &m_clsEffect );
	m_clsFigure.SetVertexIndex( arrCube, _countof(arrCube), arrIndex, _countof(arrIndex) );

	// 5.6.3 ī�޶� ���̴� ������ ����ϱ� ���ؼ� ���� ���� ��ȯ�� �ʿ��ϴ�.
	// ���� ���� ��ȯ�� ���ؼ� ���� �þ߰��� 45���̰� ��Ⱦ�� 1�̸� ����� ����� z=1 �̰� �� ����� z=1000 �� �������� ����� �����Ѵ�.
	XMMATRIX sttP = XMMatrixPerspectiveFovLH( 0.25f * XM_PI, 1.0f, 1.0f, 1000.0f );
	XMStoreFloat4x4( &m_sttProj, sttP );

	// ť�� ��ġ ����
	XMStoreFloat4x4( &m_arrCubeWorld[0], XMMatrixTranslation( 0.0f, 0.0f, 0.0f ) );

	// ���౤ ����
	m_clsDirectionalLight.m_f4Ambient = XMFLOAT4( 0.5f, 0.5f, 0.5f, 1.0f );
	m_clsDirectionalLight.m_f4Diffuse = XMFLOAT4( 0.5f, 0.5f, 0.5f, 1.0f );
	m_clsDirectionalLight.m_f4Specular = XMFLOAT4( 0.5f, 0.5f, 0.5f, 1.0f );
	m_clsDirectionalLight.m_f3Direction = XMFLOAT3( -0.5f, -0.5f, 0.5f );

	// ���� ����
	m_clsMaterial.m_f4Ambient = XMFLOAT4( 0.93f, 0.9f, 0.86f, 1.0f );
	m_clsMaterial.m_f4Diffuse = XMFLOAT4( 0.93f, 0.9f, 0.86f, 1.0f );
	m_clsMaterial.m_f4Specular = XMFLOAT4( 0.93f, 0.9f, 0.86f, 100.0f );

	// �ؽ�ó �̹��� ������ �ε��Ѵ�.
	//CHECK_FAILED( D3DX11CreateShaderResourceViewFromFile( m_pclsDevice, _T("Texture/box.png"), 0, 0, &m_pclsShaderResView, 0 ) );

	return true;
}

/**
 * @ingroup TestGrid
 * @brief �ﰢ���� ȭ�鿡 �׷��ش�.
 * @returns �����ϸ� true �� �����ϰ� �׷��� ������ false �� �����Ѵ�.
 */
bool CDirectXGrid::DrawChild()
{
	m_clsEffect.SetDirectionalLight( &m_clsDirectionalLight );
	m_clsEffect.SetEyePos( &m_f3EyePos );

	m_clsFigure.SetWorld( &m_arrCubeWorld[0] );
	m_clsFigure.SetMaterial( &m_clsMaterial );
	m_clsFigure.Draw( &m_sttView, &m_sttProj );

	return true;
}

/**
 * @ingroup TestGrid
 * @brief ī�޶� ��ġ�� ī�޶� ť�긦 �ٶ󺸴� ������ �̿��Ͽ��� View ����� �����Ѵ�.
 * @returns true �� �����Ѵ�.
 */
bool CDirectXGrid::Update()
{
	// 5.6.2 ���� �������� �þ� �������� ��ǥ ��ȯ ������ ���� �þ� ����� �����Ѵ�.
	XMVECTOR pos = m_clsCamPos.GetVector();
	TRACE( "x(%.2f) y(%.2f) z(%.2f)\n", pos.m128_f32[0], pos.m128_f32[1], pos.m128_f32[2] );

	// ť�� ��ġ
	XMVECTOR target = XMVectorZero();

	// ī�޶� Ÿ���� �ٶ� ���� ���� ����.
	XMVECTOR up = XMVectorSet( 0.0, 1.0, 0.0, 0.0 );

	// ī�޶� ��ġ�� ī�޶� ť�긦 �ٶ󺸴� ������ �̿��Ͽ��� View ����� �����Ѵ�.
	XMMATRIX view = XMMatrixLookAtLH( pos, target, up );

	XMStoreFloat4x4( &m_sttView, view );

	// ī�޶� ��ġ�� �����Ѵ�.
	m_f3EyePos = m_clsCamPos.GetEyePos();
	
	return true;
}

/**
 * @ingroup TestGrid
 * @brief ���콺 ��ư down �̺�Ʈ �ڵ鷯
 * @param hWnd	������ �ڵ�
 * @param x			���콺 X ��ġ
 * @param y			���콺 Y ��ġ
 */
void CDirectXGrid::OnMouseDown( HWND hWnd, int x, int y )
{
	m_sttMousePos.x = x;
	m_sttMousePos.y = y;
	m_bMouseDown = true;

	SetCapture( hWnd );
}

/**
 * @ingroup TestGrid
 * @brief ���콺 ��ư up �̺�Ʈ �ڵ鷯
 * @param x			���콺 X ��ġ
 * @param y			���콺 Y ��ġ
 */
void CDirectXGrid::OnMouseUp( int x, int y )
{
	ReleaseCapture();
	m_bMouseDown = false;
}

/**
 * @ingroup TestGrid
 * @brief ���콺 �̵� �̺�Ʈ �ڵ鷯
 * @param hWnd	������ �ڵ�
 * @param x			���콺 X ��ġ
 * @param y			���콺 Y ��ġ
 */
void CDirectXGrid::OnMouseMove( HWND hWnd, int x, int y )
{
	if( m_bMouseDown )
	{
		m_clsCamPos.Move( x - m_sttMousePos.x, y - m_sttMousePos.y );

		m_sttMousePos.x = x;
		m_sttMousePos.y = y;

		Update();
		Draw();
	}
}