//===========================================================
//
// 警告画像表示処理[warning.cpp]
// Author Ibuki Okusada
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "warning.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "number.h"
#include "sound.h"

// 定数定義
namespace
{
	const D3DXVECTOR3 POS = D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3f, 0.0f);
	const float WIDTH = 150.0f;						// 幅
	const float HEIGHT = 200.0f;					// 設置座標
	const char* FILENAME[CWarning::TYPE_MAX] = {	// ファイル名
		"data\\TEXTURE\\warning\\walk.png",
		"data\\TEXTURE\\warning\\rock.png",
		"data\\TEXTURE\\warning\\wind.png",
		"data\\TEXTURE\\warning\\rope.png",
	};
	const D3DXVECTOR2 ADDSIZE = D3DXVECTOR2(4.0f, 2.0f);
	const int TIMER = 300;
}

//================================================================
// コンストラクタ
//================================================================
CWarning::CWarning()
{
	m_pObj = nullptr;
}

//================================================================
// デストラクタ
//================================================================
CWarning::~CWarning()
{

}

//================================================================
// 生成処理
//================================================================
CWarning* CWarning::Create(const int nType)
{
	//オブジェクト2Dのポインタ
	CWarning* pWarning = NULL;

	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	if (pWarning == NULL)
	{
		//オブジェクト2Dの生成
		pWarning = new CWarning();
		
		// 種類設定
		pWarning->m_nType = nType;

		//初期化処理
		pWarning->Init();
	}

	return pWarning;
}

//================================================================
// 初期化処理
//================================================================
HRESULT CWarning::Init(void)
{
	// 2Dポリゴンの生成
	CTexture* p = CManager::GetInstance()->GetTexture();
	m_pObj = CObject2D::Create();
	m_pObj->SetPosition(POS);
	m_pObj->SetDraw();
	m_pObj->SetSize(0.0f, 0.0f);

	// 種類ごとのテクスチャ設定
	m_pObj->SetIdxTex(p->Regist(FILENAME[m_nType]));
	m_nTimer = TIMER;
	CManager::GetInstance()->GetSound()->Play(CSound::SOUND_LABEL_SE_WARNING);

	return S_OK;
}

//================================================================
// 終了処理
//================================================================
void CWarning::Uninit(void)
{
	// ポリゴンの終了
	if (m_pObj != nullptr)
	{
		m_pObj->Uninit();
		m_pObj = nullptr;
	}

	Release();
}

//================================================================
// 更新処理
//================================================================
void CWarning::Update(void)
{
	m_nTimer--;

	// ポリゴンのサイズ変更
	if (m_nTimer >= TIMER * 0.9f)
	{
		float width = m_pObj->GetWidth() + ADDSIZE.x * 2;
		float height = m_pObj->GetHeight() + ADDSIZE.y * 2;
		m_pObj->SetSize(width, height);
	}

	if (m_nTimer <= TIMER * 0.2f)
	{
		float width = m_pObj->GetWidth() - ADDSIZE.x;
		float height = m_pObj->GetHeight() - ADDSIZE.y;
		m_pObj->SetSize(width, height);
	}

	// タイマー0で消す
	if (m_nTimer <= 0) { Uninit(); }
}


//================================================================
// 描画処理
//================================================================
void CWarning::Draw(void)
{
	
}
