//===========================================================
//
// ギミック処理[gimmcik.cpp]
// Author : 大原　怜将
//
//===========================================================
#include "gimmick.h"
#include "billboard.h"
#include "gimmickTiming.h"
#include "player.h"

float CGimmick::m_fDestPos = 0.0f;		// 目標地点

//===========================================================
// 定数定義
//===========================================================
namespace
{
	// ギミック開始位置
	const float fDestPos[2] = 
	{ -5000.0f,		// 歩行
		-10000.0f };	// 綱渡り
}

//===========================================================
// コンストラクタ
//===========================================================
CGimmick::CGimmick(int nPriority)
{
	m_GimmickType = TYPEWALK;
	m_fDestPos = 0.0f;
	m_bStart = false;		// ギミック開始したか

}

//===========================================================
// デストラクタ
//===========================================================
CGimmick::~CGimmick()
{

}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CGimmick::Init(void)
{



	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmick::Uninit(void)
{

}

//===========================================================
// 更新処理
//===========================================================
void CGimmick::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();


	if (fDestPos[0] >= pPlayer->GetPosition().z)
	{ // 綱渡り

		if (m_bStart == false)
		{
			m_GimmickType = TYPEROPE;
			m_bStart = true;

		}
	}

	if (m_bStart == true)
	{
		switch (m_GimmickType)
		{
		case CGimmick::TYPEWALK:		// 歩行
			CGimmickTiming::Create();
			break;

		default:
			break;
		}
	}
}

//===========================================================
// 描画処理
//===========================================================
void CGimmick::Draw(void)
{


}

//===========================================================
// 生成処理
//===========================================================
CGimmick* CGimmick::Create(float fDestDistance, TYPE type)
{
	CGimmick* pGimmick = new CGimmick;

	m_fDestPos = fDestDistance;

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
	}

	// 歩行
	CGimmickTiming::Create();

	return pGimmick;
}
