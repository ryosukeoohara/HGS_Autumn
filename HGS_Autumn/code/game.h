//===========================================================
//
//ポリゴンを出すやつ[game.h]
//Author 大原怜将
//
//===========================================================
#ifndef _GAME_H_
#define _GAME_H_

//===========================================================
// インクルードファイル
//===========================================================
#include "manager.h"

//===========================================================
// 前方宣言
//===========================================================
class CPause;
class CObject2D;
class CPlayer;

//===========================================================
// ゲームクラス定義
//===========================================================
class CGame : public CScene
{
public:
	CGame();
	CGame(CScene::MODE mode);
	~CGame();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CGame *Create(void);

	// 設定系
	static void SetbPause(bool bpause) { m_bPause = bpause; }

	// 取得系
	static bool GetbPause(void) { return m_bPause; }

private:

	static CPause *m_pPause;
	static bool m_bPause;
	CObject2D* m_pBg;
	CPlayer* m_pPlayer;

};

#endif // !_GAME_H_