//===========================================================
//
// 警告画像表示ヘッダー[warning.h]
// Author Ibuki Okusada
//
//===========================================================
#ifndef _WARNING_H_             //このマクロ定義がされてなかったら
#define _WARNING_H_             //2重インクルード防止のマクロ定義をする

#include "object.h"

//マクロ定義
#define SETTIME   (2)  //時間の桁
#define TIME      (90) //ゲームの制限時間
#define INITTIME  (0)  //それぞれの桁の初期値

// 前方宣言
class CObject2D;

//タイムクラス
class CWarning : public CObject
{
public:

	// 警告種類(マップごとに)
	enum TYPE
	{
		TYPE_WALK = 0,	// 歩行
		TYPE_ROCK,		// 石
		TYPE_WIND,		// 風
		TYPE_ROPE,		// 綱渡り
		TYPE_MAX
	};

	CWarning();  //コンストラクタ
	~CWarning();  //デストラクタ

	HRESULT Init(void);      //ポリゴンの初期化処理    
	void Uninit(void);    //ポリゴンの終了処理
	void Update(void);    //ポリゴンの更新処理
	void Draw(void);      //ポリゴンの描画処理

	static CWarning* Create(const int nType);  //生成

private:

	// メンバ変数
	CObject2D* m_pObj;	// ポリゴン
	int m_nType;		// 種類
	int m_nTimer;
};

#endif