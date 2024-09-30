//===========================================================
//
// �M�~�b�N����:�{�^���A��[gimmcik.cpp]
// Author : �匴�@�叫
//
//===========================================================
#include "gimmickButtonMash.h"
#include "objectX.h"
#include "player.h"
#include "collision.h"

//===========================================================
// �R���X�g���N�^
//===========================================================
CGimmickButtonMash::CGimmickButtonMash(D3DXVECTOR3 pos, int nPriority)
{

}

//===========================================================
// �f�X�g���N�^
//===========================================================
CGimmickButtonMash::~CGimmickButtonMash()
{

}

//===========================================================
// ����������
//===========================================================
HRESULT CGimmickButtonMash::Init(void)
{

	return S_OK;
}

//===========================================================
// �I������
//===========================================================
void CGimmickButtonMash::Uninit(void)
{

}

//===========================================================
// �X�V����
//===========================================================
void CGimmickButtonMash::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (pPlayer == nullptr)
		return;

	int nNum = pPlayer->GetButtonpushCount();

	if (nNum >= 50)
	{
		m_bClear = true;
		
	}

	if (m_bClear == true)
	{
		D3DXVECTOR3 pos = m_pObjectX->GetPosition();
		D3DXVECTOR3 rot = m_pObjectX->GetRotition();

		pos.x += 50.0f;
		pos.y += 50.0f;
		pos.z -= 50.0f;

		//rot.x += 

		m_pObjectX->SetPosition(pos);
	}

	CCollision* pCollision = CCollision::GetInstance();

	if (pCollision == nullptr)
		return;

	if (pCollision->Circle(m_pos, pPlayer->GetPosition(), 500.0f, 50.0f) == true)
	{
		if (pPlayer->GetState() != pPlayer->STATE_HAMMER)
		{
			pPlayer->ChangeState(new CPlayerStateHummer);
		}
	}
}

//===========================================================
// �`�揈��
//===========================================================
void CGimmickButtonMash::Draw(void)
{

}

//===========================================================
// ��������
//===========================================================
CGimmickButtonMash* CGimmickButtonMash::Create(D3DXVECTOR3 pos)
{
	CGimmickButtonMash* pGimmick = new CGimmickButtonMash(pos);

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
		pGimmick->m_pObjectX = CObjectX::Create("data\\MODEL\\Field\\rock.x", pos);
		pGimmick->m_pos = pos;
	}

	return pGimmick;
}