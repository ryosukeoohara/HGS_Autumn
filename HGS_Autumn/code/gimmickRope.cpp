//===========================================================
//
// �M�~�b�N����:�j�n��[gimmickRope.cpp]
// Author : �匴�@�叫
//
//===========================================================
#include "gimmickRope.h"
#include "manager.h"
#include "debugproc.h"
#include "player.h"
#include "InputJoyPad.h"

//===========================================================
// �萔��`
//===========================================================
namespace
{
	//const float fSafeRot = 0.25f;		// ���S�Ȋp�x
	const float fDangerRot = 0.75f;		// �댯�Ȋp�x
	const float fDeathRot = 1.57f;		// ���̊p�x

}

//===========================================================
// �R���X�g���N�^
//===========================================================
CGimmickRope::CGimmickRope(int nPriority)
{
	
	m_fMove = 0.0f;
}

//===========================================================
// �f�X�g���N�^
//===========================================================
CGimmickRope::~CGimmickRope()
{

}

//===========================================================
// ����������
//===========================================================
HRESULT CGimmickRope::Init(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	// ���[�v�����ɕύX
	pPlayer->ChangeState(new CPlayerStateRopeWalk);

	return S_OK;
}

//===========================================================
// �I������
//===========================================================
void CGimmickRope::Uninit(void)
{
	
}

//===========================================================
// �X�V����
//===========================================================
void CGimmickRope::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();
	D3DXVECTOR3 rot;

	rot = pPlayer->GetRotition();

	if (rot.z >= fDangerRot)
	{
		// ���[�v�����ɕύX
		//pPlayer->ChangeState(new CPlayerStateRopeWalk);
	}

	CManager::GetInstance()->GetDebugProc()->Print("�p�x:%f\n", rot.z);

}

//===========================================================
// �`�揈��
//===========================================================
void CGimmickRope::Draw(void)
{
	
}

//===========================================================
// ��������
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
