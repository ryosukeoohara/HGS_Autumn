//===========================================================
//
// ギミック処理[gimmcik.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _GIMMICK_H_             //このマクロ定義がされてなかったら
#define _GIMMICK_H_             //2重インクルード防止のマクロ定義をする

//===========================================================
// ギミッククラス定義
//===========================================================
class CGimmick
{
public:
	CGimmick(int nPriority = 3);  // コンストラクタ
	~CGimmick();                  // デストラクタ

	HRESULT Init(void);            // 初期化処理    
	void Uninit(void);             // 終了処理
	void Update(void);             // 更新処理
	void Draw(void);               // 描画処理

	CGimmick* Create(void);        // 生成処理

private:
	
};

#endif