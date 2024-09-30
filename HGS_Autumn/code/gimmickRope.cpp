//===========================================================
//
// ギミック処理:綱渡り[gimmickRope.cpp]
// Author : 大原　怜将
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
// 定数定義
//===========================================================
namespace
{
	//const float fSafeRot = 0.25f;		// 安全な角度
	const float fDangerRot = 0.75f;		// 危険な角度
	const float fDeathRot = 1.57f;		// 死の角度

}

//===========================================================
// コンストラクタ
//===========================================================
CGimmickRope::CGimmickRope(int nPriority)
{
	m_pObject3D = nullptr;
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
	CPlayer* pPlayer = CPlayer::GetInstance();
	m_pObject3D->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\rope.png"));
	m_pObject3D->SetSize(100.0f, 1500.0f);

	// ロープ歩きに変更
	pPlayer->ChangeState(new CPlayerStateRopeWalk);

	return S_OK;
}

//===========================================================
// 終了処理
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
// 更新処理
//===========================================================
void CGimmickRope::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();
	D3DXVECTOR3 rot;

	rot = pPlayer->GetRotition();

	CManager::GetInstance()->GetDebugProc()->Print("角度:%f\n", rot.z);

}

//===========================================================
// 描画処理
//===========================================================
void CGimmickRope::Draw(void)
{
	
}

//===========================================================
// 生成処理
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
