//===========================================================
//
// ギミック処理[gimmcik.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _GIMMICK_H_             //このマクロ定義がされてなかったら
#define _GIMMICK_H_             //2重インクルード防止のマクロ定義をする

//===========================================================
// インクルードファイル
//===========================================================
#include "billboard.h"

class CGimmickTiming;
class CGimmickRope;
class CGimmickButtonMash;

//===========================================================
// ギミッククラス定義
//===========================================================
class CGimmick : public CBillBoard
{
public:
	enum TYPE
	{
		TYPEWALK = 0,		// 歩行
		TYPEROPE,			// 綱渡り
		TYPEROCK,			// 岩
		TYPEMAX
	};

	CGimmick(int nPriority = 3);  // コンストラクタ
	~CGimmick();                  // デストラクタ

	HRESULT Init(void);            // 初期化処理    
	void Uninit(void);             // 終了処理
	void Update(void);             // 更新処理
	void Draw(void);               // 描画処理

	static CGimmick* Create(float fDestDistance, TYPE type);        // 生成処理

	void Set(TYPE GimmickType, D3DXVECTOR3 pos);

private:
	static CGimmickTiming* m_pGimmickTiming;
	static CGimmickRope* m_pGimmickRope;
	static CGimmickButtonMash* m_pGimmickButtonMash;

	TYPE m_GimmickType;			// 種類
	static float m_fDestPos;		// 目標地点

	bool m_bStart;		// ギミック開始したか
	
};

#endif