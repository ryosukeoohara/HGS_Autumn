//===========================================================
//
// 警告ボタン表示ヘッダー[manual_button.h]
// Author Ibuki Okusada
//
//===========================================================
#ifndef _MANUAL_BUTTON_H_             //このマクロ定義がされてなかったら
#define _MANUAL_BUTTON_H_             //2重インクルード防止のマクロ定義をする

#include "object.h"

// 前方宣言
class CBillBoard;

//タイムクラス
class CManualButton : public CObject
{
public:

	// 警告種類(マップごとに)
	enum TYPE
	{
		TYPE_LEFT = 0,	// Lボタン
		TYPE_RIGHT,		// Rボタン
		TYPE_MAX
	};

	CManualButton();  //コンストラクタ
	~CManualButton();  //デストラクタ

	HRESULT Init(void);      //ポリゴンの初期化処理    
	void Uninit(void);    //ポリゴンの終了処理
	void Update(void);    //ポリゴンの更新処理
	void Draw(void);      //ポリゴンの描画処理
	void Select(const int nSelect) { m_nSelect = nSelect; }	// 入力方向設定
	static CManualButton* Create();

private:

	// メンバ変数
	CBillBoard* m_apObj[TYPE_MAX];	// ポリゴン
	int m_nSelect;
};

#endif