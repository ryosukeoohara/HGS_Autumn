//===========================================================
//
// プレイヤー処理[player.cpp]
// Author 大原怜将
//
//===========================================================
#include "main.h"
#include "player.h"
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "InputKeyBoard.h"
#include "InputJoyPad.h"
#include "sound.h"
#include "debugproc.h"
#include "texture.h"
#include "camera.h"
#include "game.h"
#include "fade.h"
#include "collision.h"
#include "camera.h"
#include "object.h"
#include "utility.h"
#include "particle.h"
#include "effect2D.h"

//===========================================================
// 静的メンバ変数
//===========================================================
CPlayer *CPlayer::m_pPlayer = nullptr;

//===========================================================
// 定数定義
//===========================================================
namespace
{
	
}

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(D3DXVECTOR3 pos, int nPriority)
{
}

CPlayer::~CPlayer()
{
}

HRESULT CPlayer::Init(void)
{
	return E_NOTIMPL;
}

void CPlayer::Uninit(void)
{
}

void CPlayer::Update(void)
{
}

void CPlayer::Draw(void)
{
}

CPlayer* CPlayer::Create(D3DXVECTOR3 pos, int nPriority)
{
	return nullptr;
}

void CPlayer::Control(void)
{
}
