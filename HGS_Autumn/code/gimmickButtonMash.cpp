//===========================================================
//
// ギミック処理:ボタン連打[gimmcik.cpp]
// Author : 大原　怜将
//
//===========================================================
#include "gimmickButtonMash.h"
#include "objectX.h"
#include "player.h"
#include "collision.h"

//===========================================================
// コンストラクタ
//===========================================================
CGimmickButtonMash::CGimmickButtonMash(D3DXVECTOR3 pos, int nPriority)
{

}

//===========================================================
// デストラクタ
//===========================================================
CGimmickButtonMash::~CGimmickButtonMash()
{

}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CGimmickButtonMash::Init(void)
{
	if(m_pObjectX == nullptr)
		m_pObjectX = CObjectX::Create("data\\MODEL\\Field\\rock.x", m_pos);

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmickButtonMash::Uninit(void)
{
	if (m_pObjectX != nullptr)
	{
		m_pObjectX->Uninit();
		m_pObjectX = nullptr;
	}

	CObject::Release();
}

//===========================================================
// 更新処理
//===========================================================
void CGimmickButtonMash::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	if (pPlayer == nullptr)
		return;

	int nNum = pPlayer->GetButtonpushCount();

	if (nNum >= 30)
		m_bClear = true;

	if (m_bClear == true)
	{
		D3DXVECTOR3 pos = m_pObjectX->GetPosition();
		D3DXVECTOR3 rot = m_pObjectX->GetRotition();

		pos.x += 25.0f;
		pos.y += 25.0f;
		pos.z -= 25.0f;

		rot.x += 0.2f;
		rot.y += 0.2f;
		rot.z += 0.2f;

		m_pObjectX->SetPosition(pos);
		m_pObjectX->SetRotition(rot);
		pPlayer->ChangeState(new CPlayerStateStep);
	}

	if (m_bClear == true)
		return;

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
// 描画処理
//===========================================================
void CGimmickButtonMash::Draw(void)
{

}

//===========================================================
// 生成処理
//===========================================================
CGimmickButtonMash* CGimmickButtonMash::Create(D3DXVECTOR3 pos)
{
	CGimmickButtonMash* pGimmick = new CGimmickButtonMash(pos);

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
		//pGimmick->
		pGimmick->m_pos = pos;
	}

	return pGimmick;
}