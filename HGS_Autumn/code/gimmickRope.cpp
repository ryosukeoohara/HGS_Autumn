//===========================================================
//
// ギミック処理:綱渡り[gimmickRope.cpp]
// Author : 大原　怜将
//
//===========================================================
#include "gimmickRope.h"
#include "manager.h"
#include "player.h"
#include "InputJoyPad.h"

CBillBoard* CGimmickRope::m_pBillBoard[NUM_JUDGE] = {};		// ビルボードの情報

//===========================================================
// 定数定義
//===========================================================
namespace
{
	const D3DXVECTOR2 JUDGE_SIZE = D3DXVECTOR2(10.0f, 10.0f);
	const D3DXVECTOR3 DEFAULT_POS = D3DXVECTOR3(0.0f, 100.0f, 0.0f);
	const float fMoveDest = 100.0f;		// 目標の合計移動量
}

//===========================================================
// コンストラクタ
//===========================================================
CGimmickRope::CGimmickRope(int nPriority)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		m_pBillBoard[nCnt] = nullptr;		// ビルボードの情報
	}
	m_fMove = 0.0f;
}

//===========================================================
// デストラクタ
//===========================================================
CGimmickRope::~CGimmickRope()
{

}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CGimmickRope::Init(void)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		if (m_pBillBoard[nCnt] == nullptr)
		{
			m_pBillBoard[nCnt] = CBillBoard::Create();
		}
	}

	// ビルボード
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		if (m_pBillBoard[nCnt] != nullptr)
		{
			m_pBillBoard[nCnt]->Init();
			m_pBillBoard[nCnt]->SetSize(JUDGE_SIZE.x, JUDGE_SIZE.y);
			m_pBillBoard[nCnt]->SetPosition(DEFAULT_POS);

			m_pBillBoard[nCnt]->SetJudgeRotType(JUDGEROTTYPE_LEFT);

			if (nCnt == 0)
			{ // 上側
				m_pBillBoard[nCnt]->SetJudgeType(JUDGETYPE_UP);
			}
			else if (nCnt == 1)
			{ // 下側
				m_pBillBoard[nCnt]->SetJudgeType(JUDGETYPE_DOWN);

			}
		}
	}

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmickRope::Uninit(void)
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
void CGimmickRope::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();	// プレイヤー
	D3DXVECTOR3 posPlayer = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// プレイヤーの位置
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// 位置

	m_fMove = m_fMove + 1.0f;

	if (pPlayer != nullptr)
	{
		posPlayer = pPlayer->GetPosition();
	}

	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		pos = m_pBillBoard[nCnt]->GetPosition();

		switch (m_pBillBoard[nCnt]->GetJudgeRotType())
		{
		case JUDGEROTTYPE_LEFT:		// 左側

			if (fMoveDest >= m_fMove)
			{
				if (nCnt == 0)
				{
					m_pBillBoard[nCnt]->SetPosition(D3DXVECTOR3(posPlayer.x + 100.0f, -DEFAULT_POS.y + m_fMove, posPlayer.z));
				}
				else if (nCnt == 1)
				{
					m_pBillBoard[nCnt]->SetPosition(D3DXVECTOR3(posPlayer.x + 100.0f, DEFAULT_POS.y - m_fMove, posPlayer.z));

				}
			}
			else
			{
				m_fMove = 0.0f;
				m_pBillBoard[0]->SetJudgeRotType(JUDGEROTTYPE_RIGHT);
				m_pBillBoard[1]->SetJudgeRotType(JUDGEROTTYPE_RIGHT);
			}

			break;

		case JUDGEROTTYPE_RIGHT:		// 右側

			if (fMoveDest >= m_fMove)
			{
				if (nCnt == 0)
				{
					m_pBillBoard[nCnt]->SetPosition(D3DXVECTOR3(posPlayer.x - 100.0f, -DEFAULT_POS.y + m_fMove, posPlayer.z));
				}
				else if (nCnt == 1)
				{
					m_pBillBoard[nCnt]->SetPosition(D3DXVECTOR3(posPlayer.x - 100.0f, DEFAULT_POS.y - m_fMove, posPlayer.z));

				}
			}
			else
			{
				m_fMove = 0.0f;
				m_pBillBoard[0]->SetJudgeRotType(JUDGEROTTYPE_LEFT);
				m_pBillBoard[1]->SetJudgeRotType(JUDGEROTTYPE_LEFT);

			}

			break;


		default:
			break;
		}
	}

	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	if (pInputJoyPad == nullptr)
		return;

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_LB, 0) == true &&
		m_pBillBoard[0]->GetJudgeRotType() == JUDGEROTTYPE_LEFT)
	{
		if (m_fMove <= 50.0f)
		{
			pPlayer->ChangeState(new CPlayerStateStagger);
		}
		else if (m_fMove <= 80.0f)
		{
			pPlayer->ChangeState(new CPlayerStateWalk);
		}
		else if (m_fMove <= 100.0f)
		{
			pPlayer->ChangeState(new CPlayerStateStep);
		}

		m_fMove = 0.0f;

		m_pBillBoard[0]->SetJudgeRotType(JUDGEROTTYPE_RIGHT);
		m_pBillBoard[1]->SetJudgeRotType(JUDGEROTTYPE_RIGHT);
	}
	else if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_RB, 0) == true &&
		m_pBillBoard[0]->GetJudgeRotType() == JUDGEROTTYPE_RIGHT)
	{
		if (m_fMove <= 50.0f)
		{
			pPlayer->ChangeState(new CPlayerStateStagger);
		}
		else if (m_fMove <= 80.0f)
		{
			pPlayer->ChangeState(new CPlayerStateWalk);
		}
		else if (m_fMove <= 100.0f)
		{
			pPlayer->ChangeState(new CPlayerStateStep);
		}

		m_fMove = 0.0f;

		m_pBillBoard[0]->SetJudgeRotType(JUDGEROTTYPE_LEFT);
		m_pBillBoard[1]->SetJudgeRotType(JUDGEROTTYPE_LEFT);

	}
}

//===========================================================
// 描画処理
//===========================================================
void CGimmickRope::Draw(void)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		m_pBillBoard[nCnt]->Draw();
	}
}

//===========================================================
// 生成処理
//===========================================================
CGimmickRope* CGimmickRope::Create(void)
{
	CGimmickRope* pGimmick = new CGimmickRope;

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
	}

	return pGimmick;
}
