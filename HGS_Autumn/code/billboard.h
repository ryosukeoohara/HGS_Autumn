//===========================================================
//
// ビルボード処理 [billboard.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _BILLBOARD_H_             //このマクロ定義がされてなかったら
#define _BILLBOARD_H_             //2重インクルード防止のマクロ定義をする

//===========================================================
// インクルードファイル
//===========================================================
#include "main.h"
#include "object.h"

//===========================================================
// ビルボードクラス定義
//===========================================================
class CBillBoard : public CObject
{
public:

	enum TYPE
	{
		TYPE_NONE = 0,
		TYPE_HIT,
		TYPE_MAX
	};

	// 歩き判定の種類
	enum JUDGETYPE
	{
		JUDGETYPE_NONE = 0,		// 何もなし
		JUDGETYPE_UP,			// 上側
		JUDGETYPE_DOWN,			// 下側
		JUDGETYPE_MAX
	};

	// 歩き判定の方向
	enum JUDGEROTTYPE
	{
		JUDGEROTTYPE_NONE = 0,		// 何もなし
		JUDGEROTTYPE_LEFT,			// 左側
		JUDGEROTTYPE_RIGHT,			// 右側
		JUDGEROTTYPE_MAX
	};

	CBillBoard(int nPriority = 3);
	~CBillBoard();

	HRESULT Init(void);  // 初期化処理    
	void Uninit(void);   // 終了処理
	void Update(void);   // 更新処理
	void Draw(void);     // 描画処理
	
	static CBillBoard *Create(int nPriority = 3);  //生成

	// 設定系
	void SetCurrent(D3DXMATRIX *Current) { m_pCurrent = Current; }        // 親のマトリックス
	void SetSize(float fHeight, float fWidth);                            // サイズ(中心が真ん中)
	void SetEdgeCenter(float fWidth, float fHeight);                      // サイズ(角が真ん中)
	void SetTex(float fTex);
	void SetAnim(void);
	void SetIdxTex(int Idx) { m_nIdxTexture = Idx; }                      // テクスチャのインデックス番号
	void SetPosition(D3DXVECTOR3 pos) { m_pos = pos; }                    // 位置
	void SetRotition(D3DXVECTOR3 rot) { m_rot = rot; }                    // 向き
	void SetColor(D3DXCOLOR col);                                         // 色
	void SetType(TYPE type) { m_Type = type; }                            // 種類
	void SetDraw(bool bDraw = true) { m_bDraw = bDraw; }                  // 描画するかどうか
	void SetJudgeType(JUDGETYPE type) { m_Judgetype = type; }			// 判定の種類
	void SetJudgeRotType(JUDGEROTTYPE type) { m_Judgerottype = type; }			// 判定の種類


	// 取得系
	float GetWidth() { return m_fWidth; }
	float GetHeight() { return m_fHeight; }
	D3DXVECTOR3 GetPosition(void) { return m_pos; }
	D3DXVECTOR3 GetRotition(void) { return m_rot; }
	JUDGETYPE GetJudgeType(void) { return m_Judgetype; }			// 判定の種類
	JUDGEROTTYPE GetJudgeRotType(void) { return m_Judgerottype; }	// 判定の種類

private:
	LPDIRECT3DTEXTURE9 m_pTexture;             // テクスチャへのポインタ
	D3DXMATRIX m_mtxView;
	D3DXMATRIX m_mtxWorld;                     // ワールドマトリックス
	D3DXMATRIX *m_pCurrent;
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;        // 頂点バッファへのポインタ
	D3DXVECTOR3 m_pos;                         // 位置
	D3DXVECTOR3 m_rot;                         // 向き
	D3DXCOLOR m_col;                           // 色
	int m_nIdxTexture;                         // テクスチャのインデックス番号
	int m_nNowPattern;                         // アニメーションパターン
	int m_nNumPattern;                         // アニメーションパターン
	int m_nCounterAnim;
	int m_nHeight;
	int m_nWidth;
	float m_fHeight;                           // 高さ
	float m_fWidth;                            // 幅
	bool m_bDraw;                              // 描画するかどうか

	TYPE m_Type;
	JUDGETYPE m_Judgetype;			// 判定の種類
	JUDGEROTTYPE m_Judgerottype;	// 歩き判定の向き
};

#endif