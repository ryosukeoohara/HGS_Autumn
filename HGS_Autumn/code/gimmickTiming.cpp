//===========================================================
//
// �M�~�b�N����:�^�C�~���O[gimmickTiming.cpp]
// Author : �匴�@�叫
//
//===========================================================
#include "gimmickTiming.h"
#include "manager.h"
#include "player.h"

//===========================================================
// �萔��`
//===========================================================
namespace
{
	const D3DXVECTOR2 JUDGE_SIZE = D3DXVECTOR2(100.0f, 100.0f);

	const D3DXVECTOR3 DEFAULT_POS = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//===========================================================
// �R���X�g���N�^
//===========================================================
CGimmickTiming::CGimmickTiming(int nPriority)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		m_pBillBoard[nCnt] = nullptr;		// �r���{�[�h�̏��
	}

}

//===========================================================
// �f�X�g���N�^
//===========================================================
CGimmickTiming::~CGimmickTiming()
{

}

//===========================================================
// ����������
//===========================================================
HRESULT CGimmickTiming::Init(void)
{

	// �r���{�[�h
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		if (m_pBillBoard[nCnt] != nullptr)
		{
			m_pBillBoard[nCnt]->Init();
			m_pBillBoard[nCnt]->SetSize(JUDGE_SIZE.x, JUDGE_SIZE.y);
			m_pBillBoard[nCnt]->SetPosition(DEFAULT_POS);

			if (nCnt == 0)
			{ // �㑤
				m_pBillBoard[nCnt]->SetJudgeType(JUDGETYPE_UP);
			}
			else if (nCnt == 1)
			{ // ����
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
// �I������
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
// �X�V����
//===========================================================
void CGimmickTiming::Update(void)
{
	CPlayer* pPlayer = CManager::GetInstance()->GetPlayer();	// �v���C���[
	D3DXVECTOR3 posPlayer = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �v���C���[�̈ʒu
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		// �ʒu

	posPlayer = pPlayer->GetPosition();

	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		pos = m_pBillBoard[nCnt]->GetPosition();

		m_pBillBoard[nCnt]->SetPosition(D3DXVECTOR3(posPlayer.x + 100.0f, pos.y, posPlayer.z));
	}


}

//===========================================================
// �`�揈��
//===========================================================
void CGimmickTiming::Draw(void)
{
	for (int nCnt = 0; nCnt < NUM_JUDGE; nCnt++)
	{
		m_pBillBoard[nCnt]->Draw();
	}
}

//===========================================================
// ��������
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
