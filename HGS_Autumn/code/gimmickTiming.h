//===========================================================
//
// ギミック処理[gimmcik.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _GIMMICKTIMING_H_             //このマクロ定義がされてなかったら
#define _GIMMICKTIMING_H_             //2重インクルード防止のマクロ定義をする

#include "gimmick.h"

class CGimmick;
class CPlayer;

//===========================================================
// 定数定義
//===========================================================
namespace
{
	const int NUM_JUDGE = 2;           // 判定の数
}

//===========================================================
// ギミッククラス定義
//===========================================================
class CGimmickTiming : public CGimmick
{
public:

	CGimmickTiming(int nPriority = 3);  // コンストラクタ
	~CGimmickTiming();                  // デストラクタ

	HRESULT Init(void);            // 初期化処理    
	void Uninit(void);             // 終了処理
	void Update(void);             // 更新処理
	void Draw(void);               // 描画処理

	CGimmickTiming* Create(void);        // 生成処理

private:
	CBillBoard* m_pBillBoard[NUM_JUDGE];		// ビルボードの情報

};

#endif
