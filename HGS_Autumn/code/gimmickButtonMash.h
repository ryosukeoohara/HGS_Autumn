//===========================================================
//
// ギミック処理[gimmcik.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _GIMMICKBUTTONMASH_H_             //このマクロ定義がされてなかったら
#define _GIMMICKBUTTONMASH_H_             //2重インクルード防止のマクロ定義をする

#include "gimmick.h"

class CGimmick;
class CObjectX;

//===========================================================
// ギミッククラス定義
//===========================================================
class CGimmickButtonMash : public CGimmick
{
public:
	CGimmickButtonMash(D3DXVECTOR3 pos, int nPriority = 3);  // コンストラクタ
	~CGimmickButtonMash();                  // デストラクタ

	HRESULT Init(void);            // 初期化処理    
	void Uninit(void);             // 終了処理
	void Update(void);             // 更新処理
	void Draw(void);               // 描画処理

	static CGimmickButtonMash* Create(D3DXVECTOR3 pos);        // 生成処理

private:

	CObjectX* m_pObjectX = nullptr;
	D3DXVECTOR3 m_pos = {};
	bool m_bClear = false;

};

#endif
