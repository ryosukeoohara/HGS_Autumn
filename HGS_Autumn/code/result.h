//===========================================================
//
// リザルト画面[result.h]
// Author 大原怜将
//
//===========================================================
#ifndef _RESULT_H_
#define _RESULT_H_

//===========================================================
// インクルードファイル
//===========================================================
#include "manager.h"

//===========================================================
// 前方宣言
//===========================================================
class CField;
class CMap;
class CAppearanceUI;
class CUserRankUI;

//===========================================================
// リザルトクラス定義
//===========================================================
class CResult : public CScene
{
public:

	enum STATE
	{
		STATE_FAILED = 0,	// 失敗
		STATE_SUCCESS,		// 成功
		STATE_MAX
	};

	CResult();                     // コンストラクタ
	~CResult();                    // デストラクタ
						           
	HRESULT Init(void);            // 初期化処理
	void Uninit(void);             // 終了処理
	void Update(void);             // 更新処理
	void Draw(void);               // 描画処理
	static void Setsuccess(int i) { m_nSuccess = i; }
	static CResult *Create(void);  // 生成処理

private:
	CMap *m_pMap;
	CField *m_pField;
	CAppearanceUI *m_pNumber;
	CUserRankUI *m_pUserRank;
	static int m_nSuccess;
	static int m_nTime;

	int m_nCounter;
};

#endif