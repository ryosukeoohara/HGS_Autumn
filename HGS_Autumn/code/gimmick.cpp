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
CGimmickTiming* CGimmick::m_pGimmickTiming = nullptr;

//===========================================================
// 定数定義
//===========================================================
namespace
{
	const int NUM_GIMMICK = 15;		// ギミック数

	// ギミック開始位置 ※終了から次のギミックまでは固定の値とする
	const float fDestPos[NUM_GIMMICK] = {
		-5000.0f,		// 綱
		-10000.0f,		// 終了
		-11000.0f,		// 歩行
		-16000.0f,		// 終了
		-17000.0f,		// 岩
		-23000.0f,		// 終了
		-24000.0f,		// 歩行
		-26000.0f,		// 終了
	
	};
}

//===========================================================
// コンストラクタ
//===========================================================
CGimmick::CGimmick(int nPriority)
{
	m_pGimmickTiming = nullptr;
	m_GimmickType = TYPEWALK;
	m_fDestPos = 0.0f;
	m_bStart = false;		// ギミック開始したか
	m_bEnd = false;
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
	if (m_pGimmickTiming != nullptr)
	{
		m_pGimmickTiming->Uninit();
		m_pGimmickTiming = nullptr;
	}
}

//===========================================================
// 更新処理
//===========================================================
void CGimmick::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (fDestPos[2] >= pPlayer->GetPosition().z &&
		fDestPos[3] <= pPlayer->GetPosition().z)
	{ // 歩行

		if (m_bStart == false)
		{
			m_GimmickType = TYPEWALK;
			m_bStart = true;
			Set(m_GimmickType);
		}
	}
	else if (fDestPos[1] >= pPlayer->GetPosition().z &&
		fDestPos[2] <= pPlayer->GetPosition().z)
	{ // 終了

		m_bStart = false;
	}
	else if (fDestPos[0] >= pPlayer->GetPosition().z &&
		fDestPos[1] <= pPlayer->GetPosition().z)
	{ // 綱渡り

		if (m_bStart == false)
		{
			m_GimmickType = TYPEROPE;
			m_bStart = true;
			m_pGimmickTiming->Release();
			m_pGimmickTiming = nullptr;
			Set(m_GimmickType);
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
	m_pGimmickTiming = CGimmickTiming::Create();

	return pGimmick;
}

//===========================================================
// 生成処理
//===========================================================
void CGimmick::Set(TYPE GimmickType)
{
	switch (GimmickType)
	{
	case CGimmick::TYPEWALK:

		m_pGimmickTiming = CGimmickTiming::Create();

		break;
	case CGimmick::TYPEROPE:
		break;
	
	default:
		break;
	}
}
