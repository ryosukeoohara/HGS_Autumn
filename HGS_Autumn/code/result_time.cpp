//===========================================================
//
// リザルトタイム[time.cpp]
// Author Ibuki Okusada
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "result_time.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "number.h"
#include "time.h"

// 定数定義
namespace
{
	const D3DXVECTOR3 FISHPOS = D3DXVECTOR3(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.75f, 0.0f);
	const float WIDTH = 40.0f;
	const float HEIGHT = 80.0f;
}

//================================================================
//静的メンバ変数宣言
//================================================================
LPDIRECT3DTEXTURE9 CResultTime::m_pTexture = NULL;
CNumber* CResultTime::m_apNumber[2] = {};
int CResultTime::m_nResultTime = 0;
int CResultTime::m_nResultTimerCount = 0;

//================================================================
//コンストラクタ
//================================================================
CResultTime::CResultTime()
{
	m_move = { 0.0f, 0.0f, 0.0f };  //移動量
}

//================================================================
//コンストラクタ(オーバーロード)
//================================================================
CResultTime::CResultTime(D3DXVECTOR3 pos)
{
	m_pos = pos;  //位置
	SetPosition(pos);
	m_move = { 0.0f, 0.0f, 0.0f };  //移動量
}

//================================================================
//デストラクタ
//================================================================
CResultTime::~CResultTime()
{

}

//================================================================
//生成処理
//================================================================
CResultTime* CResultTime::Create(void)
{
	//オブジェクト2Dのポインタ
	CResultTime* pResultTime = NULL;

	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	if (pResultTime == NULL)
	{
		//オブジェクト2Dの生成
		pResultTime = new CResultTime();

		//初期化処理
		pResultTime->Init();
	}

	return pResultTime;
}

//================================================================
// 初期化処理
//================================================================
HRESULT CResultTime::Init(void)
{
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		if (m_apNumber[nCount] == NULL)
		{
			m_apNumber[nCount] = CNumber::Create({ FISHPOS.x + 50.0f * nCount, FISHPOS.y, 0.0f });

			//テクスチャをバインド
			//m_apNumber[nCount]->BindTexture(pTexture->GetAddress(m_nIdxTexture));

			m_apNumber[nCount]->SetNumberType(TYPENUMBER_TIME);

			//初期化処理
			m_apNumber[nCount]->Init();

			m_apNumber[nCount]->m_Number = 0;
			D3DXVECTOR3 pos = D3DXVECTOR3(FISHPOS.x + 80.0f * nCount, FISHPOS.y, 0.0f);
			m_apNumber[nCount]->SetVtxCounter(pos, WIDTH, HEIGHT);
		}
	}

	m_apNumber[0]->m_Number = m_nResultTime % 100 / 10;
	m_apNumber[1]->m_Number = m_nResultTime % 10 / 1;

	ResultTimeCounter();

	return S_OK;
}

//================================================================
// 終了処理
//================================================================
void CResultTime::Uninit(void)
{
	for (int nCount = 0; nCount < 2; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//終了処理
			m_apNumber[nCount]->Uninit();

			m_apNumber[nCount] = NULL;
		}
	}

	Release();

	m_nResultTime = 0;
}

//================================================================
// 更新処理
//================================================================
void CResultTime::Update(void)
{
	
}

//================================================================
// 描画処理
//================================================================
void CResultTime::Draw(void)
{
	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//描画処理
			m_apNumber[nCount]->Draw();
		}
	}
}

//================================================================
//タイム
//================================================================
void CResultTime::ResultTimeCounter(void)
{
	//フェードの情報を取得
	CFade* pFade = CManager::GetInstance()->GetFade();

	m_nResultTimerCount++;

	if (m_nResultTimerCount % 60 == 0)
	{
		m_nResultTime--;

		m_apNumber[0]->m_Number = m_nResultTime % 100 / 10;
		m_apNumber[1]->m_Number = m_nResultTime % 10 / 1;
	}

	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		m_apNumber[nCount]->SetNumber(m_apNumber[nCount]->m_Number);
	}
}