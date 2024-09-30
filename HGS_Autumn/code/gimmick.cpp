//===========================================================
//
// ギミック処理[gimmcik.cpp]
// Author : 大原　怜将
//
//===========================================================
#include "gimmick.h"
#include "billboard.h"
#include "gimmickTiming.h"
#include "gimmickRope.h"
#include "gimmickButtonMash.h"
#include "player.h"
#include "warning.h"

float CGimmick::m_fDestPos = 0.0f;		// 目標地点
CGimmickTiming* CGimmick::m_pGimmickTiming = nullptr;
CGimmickRope* CGimmick::m_pGimmickRope = nullptr;
CGimmickButtonMash* CGimmick::m_pGimmickButtonMash = nullptr;

//===========================================================
// 定数定義
//===========================================================
namespace
{
	const D3DXVECTOR3 DEFAULT_POS = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	const int NUM_GIMMICK = 15;		// ギミック数

	// ギミック開始位置 ※終了から次のギミックまでは固定の値とする
	const float fDestPos[NUM_GIMMICK] = {
		-5000.0f,		// 0.綱
		-7000.0f,		// 1.終了
		-8000.0f,		// 2.歩行
		-13000.0f,		// 3.終了
		-14000.0f,		// 4.岩
		-17000.0f,		// 5.終了
		-26000.0f,		// 6.歩行
		-29000.0f,		// 7.終了
		-32000.0f,		// 8.岩
		-33000.0f,		// 9.終了
		-44000.0f,		// 10.綱渡り
		-48000.0f,		// 11.終了
		-57000.0f,		// 12.綱渡り
		-62000.0f,		// 13.終了
		-65000.0f,		// 14.岩

	};
}

//===========================================================
// コンストラクタ
//===========================================================
CGimmick::CGimmick(int nPriority)
{
	m_pGimmickTiming = nullptr;
	m_pGimmickRope = nullptr;
	m_pGimmickButtonMash = nullptr;
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
	if (m_pGimmickTiming != nullptr)
	{
		m_pGimmickTiming->Uninit();
		m_pGimmickTiming = nullptr;
	}

	if (m_pGimmickRope != nullptr)
	{
		m_pGimmickRope->Uninit();
		m_pGimmickRope = nullptr;
	}

	CObject::Release();
}

//===========================================================
// 更新処理
//===========================================================
void CGimmick::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (fDestPos[13] >= pPlayer->GetPosition().z &&
		fDestPos[14] <= pPlayer->GetPosition().z && m_bStart == true)
	{ // 終了

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_bStart = false;
		m_pGimmickRope->Release();
		m_pGimmickRope = nullptr;
	}
	else if (fDestPos[12] >= pPlayer->GetPosition().z &&
		fDestPos[13] <= pPlayer->GetPosition().z)
	{ // 綱渡り

		if (m_bStart == false)
		{
			CWarning::Create(CWarning::TYPE_ROPE);
			m_GimmickType = TYPEROPE;
			m_bStart = true;
			Set(m_GimmickType, D3DXVECTOR3(DEFAULT_POS.x, DEFAULT_POS.y, fDestPos[12]));
		}
	}
	else if (fDestPos[11] >= pPlayer->GetPosition().z &&
		fDestPos[12] <= pPlayer->GetPosition().z && m_bStart == true)
	{ // 終了

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_bStart = false;
		m_pGimmickRope->Release();
		m_pGimmickRope = nullptr;
	}
	else if (fDestPos[10] >= pPlayer->GetPosition().z &&
		fDestPos[11] <= pPlayer->GetPosition().z)
	{ // 綱渡り

		if (m_bStart == false)
		{
			CWarning::Create(CWarning::TYPE_ROPE);
			m_GimmickType = TYPEROPE;
			m_bStart = true;
			Set(m_GimmickType, D3DXVECTOR3(DEFAULT_POS.x, DEFAULT_POS.y, fDestPos[10]));
		}
	}
	else if (fDestPos[7] >= pPlayer->GetPosition().z &&
		fDestPos[8] <= pPlayer->GetPosition().z &&
		m_bStart == true)
	{ // 終了

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		m_bStart = false;
		m_pGimmickTiming->Release();
		m_pGimmickTiming = nullptr;
	}
	else if (fDestPos[6] >= pPlayer->GetPosition().z &&
		fDestPos[7] <= pPlayer->GetPosition().z)
	{ // 歩行

		if (m_bStart == false)
		{
			CWarning::Create(CWarning::TYPE_WALK);
			m_GimmickType = TYPEWALK;
			m_bStart = true;
			Set(m_GimmickType, D3DXVECTOR3(DEFAULT_POS.x, DEFAULT_POS.y, DEFAULT_POS.z));
		}
	}
	else if (fDestPos[3] >= pPlayer->GetPosition().z &&
		fDestPos[4] <= pPlayer->GetPosition().z &&
		m_bStart == true)
	{ // 終了

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		m_bStart = false;
		m_pGimmickTiming->Release();
		m_pGimmickTiming = nullptr;
	}
	else if (fDestPos[2] >= pPlayer->GetPosition().z &&
		fDestPos[3] <= pPlayer->GetPosition().z)
	{ // 歩行

		if (m_bStart == false)
		{
			CWarning::Create(CWarning::TYPE_WALK);
			m_GimmickType = TYPEWALK;
			m_bStart = true;
			Set(m_GimmickType, D3DXVECTOR3(DEFAULT_POS.x, DEFAULT_POS.y, DEFAULT_POS.z));
		}
	}
	else if (fDestPos[1] >= pPlayer->GetPosition().z &&
		fDestPos[2] <= pPlayer->GetPosition().z && m_bStart == true)
	{ // 終了

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_bStart = false;
		m_pGimmickRope->Release();
		m_pGimmickRope = nullptr;
	}
	else if (fDestPos[0] >= pPlayer->GetPosition().z &&
		fDestPos[1] <= pPlayer->GetPosition().z)
	{ // 綱渡り

		if (m_bStart == false)
		{
			CWarning::Create(CWarning::TYPE_ROPE);
			m_GimmickType = TYPEROPE;
			m_bStart = true;
			m_pGimmickTiming->Release();
			m_pGimmickTiming = nullptr;
			Set(m_GimmickType, D3DXVECTOR3(DEFAULT_POS.x, DEFAULT_POS.y, fDestPos[0]));
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
// 設定処理
//===========================================================
void CGimmick::Set(TYPE GimmickType, D3DXVECTOR3 pos)
{
	switch (GimmickType)
	{
	case CGimmick::TYPEWALK:	// 歩き

		m_pGimmickTiming = CGimmickTiming::Create();

		break;
	case CGimmick::TYPEROPE:	// ロープ

		m_pGimmickRope = CGimmickRope::Create(pos);

		break;

	//case CGimmick::TYPEROCK:	// 岩

	//	m_pGimmickButtonMash = CGimmickButtonMash::Create(pos);

	//	break;
	
	default:
		break;
	}
}
