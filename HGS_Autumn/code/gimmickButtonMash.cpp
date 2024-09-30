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

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmickButtonMash::Uninit(void)
{

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
		pGimmick->m_pObjectX = CObjectX::Create("data\\MODEL\\Field\\rock.x", pos);
		pGimmick->m_pos = pos;
	}

	return pGimmick;
}