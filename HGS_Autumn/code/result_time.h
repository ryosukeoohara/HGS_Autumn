//===========================================================
//
//ポリゴンを出すやつ[time.h]
//Author 大原怜将
//
//===========================================================
#ifndef _RESULT_TIME_H_             //このマクロ定義がされてなかったら
#define _RESULT_TIME_H_             //2重インクルード防止のマクロ定義をする

#include "number.h"

// 前方宣言
class CObject2D;

//タイムクラス
class CResultTime : public CNumber
{
public:
	CResultTime();  //コンストラクタ
	CResultTime(D3DXVECTOR3 pos);  //コンストラクタ(オーバーロード)
	~CResultTime();  //デストラクタ

	HRESULT Init(void);      //ポリゴンの初期化処理    
	void Uninit(void);    //ポリゴンの終了処理
	void Update(void);    //ポリゴンの更新処理
	void Draw(void);      //ポリゴンの描画処理

	static CResultTime* Create(void);  //生成
	static HRESULT Load(void);  //
	static void UnLoad(void);
	static CResultTime* GetResultTime(void) { return m_ResultTime; };
	static void SetResultTime(int nResultTime) { m_nResultTime = nResultTime; };
	static int Gettime(void) { return m_nResultTime; };
	static void ResultTimeCounter(void);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;        //テクスチャへのポインタ
	D3DXVECTOR3 m_pos;  //位置
	D3DXVECTOR3 m_move; //移動
	static CResultTime* m_ResultTime;
	static CNumber* m_apNumber[2];
	static int m_nResultTimerCount;
	static int m_nResultTime;  //時間
	int m_nIdxTexture;
};

#endif
