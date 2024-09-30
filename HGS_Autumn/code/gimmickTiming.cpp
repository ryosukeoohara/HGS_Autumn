//===========================================================
//
// ギミック処理:タイミング[gimmickTiming.cpp]
// Author : 大原　怜将
//
//===========================================================
#include "gimmickTiming.h"
#include "manager.h"
#include "player.h"

//===========================================================
// 定数定義
//===========================================================
namespace
{
	const D3DXVECTOR2 JUDGE_SIZE = D3DXVECTOR2(100.0f, 100.0f);

	const D3DXVECTOR3 DEFAULT_POS = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//===========================================================
// コンストラクタ
//===========================================================
CGimmickTiming::CGimmickTiming(int nPriority)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		m_pBillBoard[nCnt] = nullptr;		// ビルボードの情報
	}

}

//===========================================================
// デストラクタ
//===========================================================
CGimmickTiming::~CGimmickTiming()
{

}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CGimmickTiming::Init(void)
{

	// ビルボード
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		if (m_pBillBoard[nCnt] != nullptr)
		{
			m_pBillBoard[nCnt]->Init();
			m_pBillBoard[nCnt]->SetSize(JUDGE_SIZE.x, JUDGE_SIZE.y);
			m_pBillBoard[nCnt]->SetPosition(DEFAULT_POS);

			if (nCnt == 0)
			{ // 上側
				m_pBillBoard[nCnt]->SetJudgeType(JUDGETYPE_UP);
			}
			else if (nCnt == 1)
			{ // 下側
				m_pBillBoard[nCnt]->SetJudgeType(JUDGETYPE_DOWN);

			}
		}
		else if (m_pBillBoard[nCnt] == nullptr)
		{
			return E_FAIL;
		}
	}

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmickTiming::Uninit(void)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		if (m_pBillBoard[nCnt] != nullptr)
		{
			m_pBillBoard[nCnt]->Uninit();
			m_pBillBoard[nCnt] = nullptr;

			delete m_pBillBoard[nCnt];
		}
	}
}

//===========================================================
// 更新処理
//===========================================================
void CGimmickTiming::Update(void)
{
	CPlayer* pPlayer = CManager::GetInstance()->GetPlayer();	// プレイヤー
	D3DXVECTOR3 posPlayer = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// プレイヤーの位置
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// 位置

	posPlayer = pPlayer->GetPosition();

	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		pos = m_pBillBoard[nCnt]->GetPosition();

		m_pBillBoard[nCnt]->SetPosition(D3DXVECTOR3(posPlayer.x + 100.0f, pos.y, posPlayer.z));
	}


}

//===========================================================
// 描画処理
//===========================================================
void CGimmickTiming::Draw(void)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		m_pBillBoard[nCnt]->Draw();
	}
}

//===========================================================
// 生成処理
//===========================================================
CGimmickTiming* CGimmickTiming::Create(void)
{
	CGimmickTiming* pGimmick = new CGimmickTiming;

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
	}

	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		if (m_pBillBoard[nCnt] == nullptr)
		{
			m_pBillBoard[nCnt] = CBillBoard::Create();
		}
	}

	return pGimmick;
}
