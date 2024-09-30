//===========================================================
//
// ギミック処理:タイミング[gimmickTiming.cpp]
// Author : 大原　怜将
//
//===========================================================
#include "gimmickTiming.h"
#include "billboard.h"

//===========================================================
// 静的メンバ変数
//===========================================================

//===========================================================
// コンストラクタ
//===========================================================
CGimmickTiming::CGimmickTiming(int nPriority)
{

}

//===========================================================
// デストラクタ
//===========================================================
CGimmickTiming::~CGimmickTiming()
{

}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CGimmickTiming::Init(void)
{

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmickTiming::Uninit(void)
{

}

//===========================================================
// 更新処理
//===========================================================
void CGimmickTiming::Update(void)
{

}

//===========================================================
// 描画処理
//===========================================================
void CGimmickTiming::Draw(void)
{

}

//===========================================================
// 生成処理
//===========================================================
CGimmickTiming* CGimmickTiming::Create(void)
{
	CGimmickTiming* pGimmick = new CGimmickTiming;

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
	}

	return pGimmick;
}
