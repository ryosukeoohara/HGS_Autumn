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
#include "object3D.h"
#include "texture.h"

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
	m_pObject3D = nullptr;
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
	m_pObject3D->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\rope.png"));
	m_pObject3D->SetSize(100.0f, 1500.0f);

	// ���[�v�����ɕύX
	pPlayer->ChangeState(new CPlayerStateRopeWalk);

	return S_OK;
}

//===========================================================
// �I������
//===========================================================
void CGimmickRope::Uninit(void)
{
	if (m_pObject3D != nullptr)
	{
		m_pObject3D->Uninit();
		m_pObject3D = nullptr;
	}

	CObject::Release();
}

//===========================================================
// �X�V����
//===========================================================
void CGimmickRope::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();
	D3DXVECTOR3 rot;

	rot = pPlayer->GetRotition();

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
CGimmickRope* CGimmickRope::Create(D3DXVECTOR3 pos)
{
	CGimmickRope* pGimmick = new CGimmickRope;

	if (pGimmick != nullptr)
	{
		pGimmick->m_pObject3D = CObject3D::Create(D3DXVECTOR3(pos.x, pos.y + 1.0f, pos.z + 1500.0f));

		pGimmick->Init();

	}

	return pGimmick;
}
