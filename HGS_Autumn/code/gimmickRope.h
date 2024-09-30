//===========================================================
//
// 綱渡り処理[gimmcik.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _GIMMICKROPE_H_             //このマクロ定義がされてなかったら
#define _GIMMICKROPE_H_             //2重インクルード防止のマクロ定義をする

#include "gimmick.h"

class CGimmick;
class CPlayer;

//===========================================================
// ギミッククラス定義
//===========================================================
class CGimmickRope : public CGimmick
{
public:

	CGimmickRope(int nPriority = 3);  // コンストラクタ
	~CGimmickRope();                  // デストラクタ

	HRESULT Init(void);            // 初期化処理    
	void Uninit(void);             // 終了処理
	void Update(void);             // 更新処理
	void Draw(void);               // 描画処理

	static CGimmickRope* Create(void);        // 生成処理

private:
	//static CBillBoard* m_pBillBoard[NUM_JUDGE];		// ビルボードの情報
	float m_fMove;		// 移動量

};

#endif
