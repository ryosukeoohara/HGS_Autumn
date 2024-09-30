//===========================================================
//
// ギミック処理[gimmcik.cpp]
// Author : 大原　怜将
//
//===========================================================
#include "gimmick.h"
#include "billboard.h"
#include "gimmickTiming.h"

//===========================================================
// コンストラクタ
//===========================================================
CGimmick::CGimmick(int nPriority)
{
	m_GimmickType = TYPEWALK;
}

//===========================================================
// デストラクタ
//===========================================================
CGimmick::~CGimmick()
{

}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CGimmick::Init(void)
{

	//CBillBoard::Init();

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CGimmick::Uninit(void)
{
	//CBillBoard::Uninit();

}

//===========================================================
// 更新処理
//===========================================================
void CGimmick::Update(void)
{
	//CBillBoard::Update();

}

//===========================================================
// 描画処理
//===========================================================
void CGimmick::Draw(void)
{
	//CBillBoard::Draw();

}

//===========================================================
// 生成処理
//===========================================================
CGimmick* CGimmick::Create(TYPE type)
{
	CGimmick* pGimmick = nullptr;

	switch (type)
	{
	case CGimmick::TYPEWALK:		// 歩行

		CGimmickTiming::Create();

		break;

	default:

		break;
	}

	if (pGimmick != nullptr)
	{
		pGimmick->Init();
	}

	return pGimmick;
}
