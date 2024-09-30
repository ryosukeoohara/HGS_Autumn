//===========================================================
//
// 警告ボタン表示処理[manual_button.cpp]
// Author Ibuki Okusada
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "manual_button.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "number.h"
#include "billboard.h"
#include "player.h"
#include "InputJoyPad.h"

// 定数定義
namespace
{
	// 位置はこれいじって
	const float SPACE = 75.0f;	// プレイヤーからの話す距離
	const float UP = 50.0f;	// プレイヤーからの高さ


	const float DEF_WIDTH = 15.0f;					// 幅
	const float DEF_HEIGHT = 15.0f;					// 設置座標
	const float BIG_WIDTH = 30.0f;
	const float BIG_HEIGHT = 30.0f;
	const char* FILENAME[CManualButton::TYPE_MAX] = {	// ファイル名
		"data\\TEXTURE\\button\\button_lb.png",
		"data\\TEXTURE\\button\\button_rb.png",
	};

}


// 左右用
namespace LEFTRIGHT
{
	const float ASPACE[CManualButton::TYPE_MAX] = {
		SPACE,
		-SPACE
	};
}

//================================================================
// コンストラクタ
//================================================================
CManualButton::CManualButton()
{
	for (int i = 0; i < TYPE_MAX; i++)
	{
		m_apObj[i] = nullptr;
	}

	m_nSelect = TYPE_MAX;
}

//================================================================
// デストラクタ
//================================================================
CManualButton::~CManualButton()
{

}

//================================================================
// 生成処理
//================================================================
CManualButton* CManualButton::Create(void)
{
	//オブジェクト2Dのポインタ
	CManualButton* pManualButton = NULL;

	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	if (pManualButton == NULL)
	{
		//オブジェクト2Dの生成
		pManualButton = new CManualButton();

		//初期化処理
		pManualButton->Init();
	}

	return pManualButton;
}

//================================================================
// 初期化処理
//================================================================
HRESULT CManualButton::Init(void)
{
	CTexture* p = CManager::GetInstance()->GetTexture();

	// 2Dポリゴンの生成
	for (int i = 0; i < TYPE_MAX; i++)
	{
		D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_apObj[i] = CBillBoard::Create();
		m_apObj[i]->SetPosition(pos);
		m_apObj[i]->SetDraw();
		m_apObj[i]->SetSize(DEF_WIDTH, DEF_HEIGHT);
		// 種類ごとのテクスチャ設定
		m_apObj[i]->SetIdxTex(p->Regist(FILENAME[i]));
	}

	return S_OK;
}

//================================================================
// 終了処理
//================================================================
void CManualButton::Uninit(void)
{
	// ポリゴンの終了
	for (int i = 0; i < TYPE_MAX; i++)
	{
		if (m_apObj[i] != nullptr)
		{
			m_apObj[i]->Uninit();
			m_apObj[i] = nullptr;
		}
	}

	Release();
}

//================================================================
// 更新処理
//================================================================
void CManualButton::Update(void)
{
	CPlayer*p = CPlayer::GetInstance();
	
	for (int i = 0; i < TYPE_MAX; i++)
	{
		if (m_apObj[i] != nullptr)
		{
			// 位置の設定
			D3DXVECTOR3 pos = p->GetPosition();
			pos.x = LEFTRIGHT::ASPACE[i];
			pos.y = UP;
			m_apObj[i]->SetPosition(pos);

			// サイズの設定
			float width = DEF_WIDTH;
			float height = DEF_HEIGHT;
			if (m_nSelect == i)
			{
				width = BIG_WIDTH;
				height = BIG_HEIGHT;
			}

			width = m_apObj[i]->GetWidth() + (width - m_apObj[i]->GetWidth()) * 0.1f;
			height = m_apObj[i]->GetHeight() + (height - m_apObj[i]->GetHeight()) * 0.1f;

			m_apObj[i]->SetSize(width, height);
		}
	}
}


//================================================================
// 描画処理
//================================================================
void CManualButton::Draw(void)
{

}
