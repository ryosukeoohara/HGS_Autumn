//===========================================================
//
// �M�~�b�N����[gimmcik.cpp]
// Author : �匴�@�叫
//
//===========================================================
#include "gimmick.h"
#include "billboard.h"
#include "gimmickTiming.h"
#include "player.h"

float CGimmick::m_fDestPos = 0.0f;		// �ڕW�n�_
CGimmickTiming* CGimmick::m_pGimmickTiming = nullptr;

//===========================================================
// �萔��`
//===========================================================
namespace
{
	const int NUM_GIMMICK = 15;		// �M�~�b�N��

	// �M�~�b�N�J�n�ʒu ���I�����玟�̃M�~�b�N�܂ł͌Œ�̒l�Ƃ���
	const float fDestPos[NUM_GIMMICK] = {
		-5000.0f,		// �j
		-10000.0f,		// �I��
		-11000.0f,		// ���s
		-16000.0f,		// �I��
		-17000.0f,		// ��
		-23000.0f,		// �I��
		-24000.0f,		// ���s
		-26000.0f,		// �I��
	
	};
}

//===========================================================
// �R���X�g���N�^
//===========================================================
CGimmick::CGimmick(int nPriority)
{
	m_pGimmickTiming = nullptr;
	m_GimmickType = TYPEWALK;
	m_fDestPos = 0.0f;
	m_bStart = false;		// �M�~�b�N�J�n������
	m_bEnd = false;
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
}

//===========================================================
// �X�V����
//===========================================================
void CGimmick::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (fDestPos[2] >= pPlayer->GetPosition().z &&
		fDestPos[3] <= pPlayer->GetPosition().z)
	{ // ���s

		if (m_bStart == false)
		{
			m_GimmickType = TYPEWALK;
			m_bStart = true;
			Set(m_GimmickType);
		}
	}
	else if (fDestPos[1] >= pPlayer->GetPosition().z &&
		fDestPos[2] <= pPlayer->GetPosition().z)
	{ // �I��

		m_bStart = false;
	}
	else if (fDestPos[0] >= pPlayer->GetPosition().z &&
		fDestPos[1] <= pPlayer->GetPosition().z)
	{ // �j�n��

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
// ��������
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
