//===========================================================
//
// �M�~�b�N����[gimmcik.cpp]
// Author : �匴�@�叫
//
//===========================================================
#include "gimmick.h"
#include "billboard.h"
#include "gimmickTiming.h"
#include "gimmickRope.h"
#include "gimmickButtonMash.h"
#include "player.h"
#include "warning.h"

float CGimmick::m_fDestPos = 0.0f;		// �ڕW�n�_
CGimmickTiming* CGimmick::m_pGimmickTiming = nullptr;
CGimmickRope* CGimmick::m_pGimmickRope = nullptr;
CGimmickButtonMash* CGimmick::m_pGimmickButtonMash = nullptr;

//===========================================================
// �萔��`
//===========================================================
namespace
{
	const D3DXVECTOR3 DEFAULT_POS = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	const int NUM_GIMMICK = 15;		// �M�~�b�N��

	// �M�~�b�N�J�n�ʒu ���I�����玟�̃M�~�b�N�܂ł͌Œ�̒l�Ƃ���
	const float fDestPos[NUM_GIMMICK] = {
		-5000.0f,		// 0.�j
		-7000.0f,		// 1.�I��
		-8000.0f,		// 2.���s
		-13000.0f,		// 3.�I��
		-14000.0f,		// 4.��
		-17000.0f,		// 5.�I��
		-26000.0f,		// 6.���s
		-29000.0f,		// 7.�I��
		-32000.0f,		// 8.��
		-33000.0f,		// 9.�I��
		-44000.0f,		// 10.�j�n��
		-48000.0f,		// 11.�I��
		-57000.0f,		// 12.�j�n��
		-62000.0f,		// 13.�I��
		-65000.0f,		// 14.��

	};
}

//===========================================================
// �R���X�g���N�^
//===========================================================
CGimmick::CGimmick(int nPriority)
{
	m_pGimmickTiming = nullptr;
	m_pGimmickRope = nullptr;
	m_pGimmickButtonMash = nullptr;
	m_GimmickType = TYPEWALK;
	m_fDestPos = 0.0f;
	m_bStart = false;		// �M�~�b�N�J�n������
}

//===========================================================
// �f�X�g���N�^
//===========================================================
CGimmick::~CGimmick()
{

}

//===========================================================
// ����������
//===========================================================
HRESULT CGimmick::Init(void)
{
	

	return S_OK;
}

//===========================================================
// �I������
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
// �X�V����
//===========================================================
void CGimmick::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (fDestPos[13] >= pPlayer->GetPosition().z &&
		fDestPos[14] <= pPlayer->GetPosition().z && m_bStart == true)
	{ // �I��

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_bStart = false;
		m_pGimmickRope->Release();
		m_pGimmickRope = nullptr;
	}
	else if (fDestPos[12] >= pPlayer->GetPosition().z &&
		fDestPos[13] <= pPlayer->GetPosition().z)
	{ // �j�n��

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
	{ // �I��

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_bStart = false;
		m_pGimmickRope->Release();
		m_pGimmickRope = nullptr;
	}
	else if (fDestPos[10] >= pPlayer->GetPosition().z &&
		fDestPos[11] <= pPlayer->GetPosition().z)
	{ // �j�n��

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
	{ // �I��

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		m_bStart = false;
		m_pGimmickTiming->Release();
		m_pGimmickTiming = nullptr;
	}
	else if (fDestPos[6] >= pPlayer->GetPosition().z &&
		fDestPos[7] <= pPlayer->GetPosition().z)
	{ // ���s

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
	{ // �I��

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

		m_bStart = false;
		m_pGimmickTiming->Release();
		m_pGimmickTiming = nullptr;
	}
	else if (fDestPos[2] >= pPlayer->GetPosition().z &&
		fDestPos[3] <= pPlayer->GetPosition().z)
	{ // ���s

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
	{ // �I��

		pPlayer->SetRotition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		m_bStart = false;
		m_pGimmickRope->Release();
		m_pGimmickRope = nullptr;
	}
	else if (fDestPos[0] >= pPlayer->GetPosition().z &&
		fDestPos[1] <= pPlayer->GetPosition().z)
	{ // �j�n��

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
// �`�揈��
//===========================================================
void CGimmick::Draw(void)
{


}

//===========================================================
// ��������
//===========================================================
CGimmick* CGimmick::Create(float fDestDistance, TYPE type)
{
	CGimmick* pGimmick = new CGimmick;

	m_fDestPos = fDestDistance;

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
	}

	// ���s
	m_pGimmickTiming = CGimmickTiming::Create();

	return pGimmick;
}

//===========================================================
// �ݒ菈��
//===========================================================
void CGimmick::Set(TYPE GimmickType, D3DXVECTOR3 pos)
{
	switch (GimmickType)
	{
	case CGimmick::TYPEWALK:	// ����

		m_pGimmickTiming = CGimmickTiming::Create();

		break;
	case CGimmick::TYPEROPE:	// ���[�v

		m_pGimmickRope = CGimmickRope::Create(pos);

		break;

	//case CGimmick::TYPEROCK:	// ��

	//	m_pGimmickButtonMash = CGimmickButtonMash::Create(pos);

	//	break;
	
	default:
		break;
	}
}
