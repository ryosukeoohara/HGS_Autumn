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

//===========================================================
// �萔��`
//===========================================================
namespace
{
	// �M�~�b�N�J�n�ʒu
	const float fDestPos[2] = 
	{ -5000.0f,		// ���s
		-10000.0f };	// �j�n��
}

//===========================================================
// �R���X�g���N�^
//===========================================================
CGimmick::CGimmick(int nPriority)
{
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

}

//===========================================================
// �X�V����
//===========================================================
void CGimmick::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();


	if (fDestPos[0] >= pPlayer->GetPosition().z)
	{ // �j�n��

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
		case CGimmick::TYPEWALK:		// ���s
			CGimmickTiming::Create();
			break;

		default:
			break;
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
	CGimmickTiming::Create();

	return pGimmick;
}
