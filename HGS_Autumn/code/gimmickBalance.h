//===========================================================
//
// ギミック処理[gimmcik.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _GIMMICKBALANCE_H_             //このマクロ定義がされてなかったら
#define _GIMMICKBALANCE_H_             //2重インクルード防止のマクロ定義をする

#include "gimmick.h"

class CGimmick;

//===========================================================
// ギミッククラス定義
//===========================================================
class CGimmickBalance : public CGimmick
{
public:
	CGimmickBalance(int nPriority = 3);  // コンストラクタ
	~CGimmickBalance();                  // デストラクタ

	HRESULT Init(void);            // 初期化処理    
	void Uninit(void);             // 終了処理
	void Update(void);             // 更新処理
	void Draw(void);               // 描画処理

	CGimmickBalance* Create(void);        // 生成処理

private:

};

#endif