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

	// ロープ歩きに変更
	pPlayer->ChangeState(new CPlayerStateRopeWalk);

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmickRope::Uninit(void)
{
	
}

//===========================================================
// 更新処理
//===========================================================
void CGimmickRope::Update(void)
{
	CPlayer* pPlayer = CPlayer::GetInstance();
	D3DXVECTOR3 rot;

	rot = pPlayer->GetRotition();

	if (rot.z >= fDangerRot)
	{
		// ロープ歩きに変更
		//pPlayer->ChangeState(new CPlayerStateRopeWalk);
	}

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
CGimmickRope* CGimmickRope::Create(void)
{
	CGimmickRope* pGimmick = new CGimmickRope;

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
	}

	return pGimmick;
}
