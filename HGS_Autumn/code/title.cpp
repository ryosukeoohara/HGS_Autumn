//===========================================================
//
// タイトル処理[title.cpp]
// Author 大原怜将
//
//===========================================================
#include "title.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"
#include "camera.h"
#include "input.h"
#include "fade.h"
#include "player.h"
#include "InputKeyBoard.h"
#include "InputJoyPad.h"

//===========================================================
// 定数定義
//===========================================================
namespace
{
	const D3DXVECTOR3 TEXPOS[3] =   // 位置
	{
		D3DXVECTOR3(640.0f, 0.0f, 350.0f),
		D3DXVECTOR3(640.0f, 0.0f, 550.0f),
		D3DXVECTOR3(640.0f, 0.0f, 750.0f),
	};

	const D3DXVECTOR3 CAMERAPOS[3] =   // 位置
	{
		D3DXVECTOR3(640.0f, 0.0f, -350.0f),
		D3DXVECTOR3(640.0f, 0.0f, -550.0f),
		D3DXVECTOR3(640.0f, 0.0f, -750.0f),
	};
}

//===========================================================
//　静的メンバ変数
//===========================================================
CPlayer *CTitle::m_pPlayer = nullptr;

//===========================================================
//コンストラクタ
//===========================================================
CTitle::CTitle()
{
	m_pField = nullptr;
	m_pBg = nullptr;
	m_pMap = nullptr;
	m_pStart = nullptr;
	m_nCnt = 0;
	m_nCntPos = 0;
}

//===========================================================
//デストラクタ
//===========================================================
CTitle::~CTitle()
{

}

//===========================================================
//生成
//===========================================================
CTitle *CTitle::Create(void)
{
	CTitle *pTitle = nullptr;

	if (pTitle == nullptr)
	{
		pTitle = new CTitle;

		pTitle->Init();
	}

	return pTitle;
}

//===========================================================
//初期化処理
//===========================================================
HRESULT CTitle::Init(void)
{
	/*if (m_pStart == nullptr)
	{
		m_pStart = CObject2D::Create();
		m_pStart->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\any.png"));
		m_pStart->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.3f, SCREEN_HEIGHT * 0.7f, 0.0f));
		m_pStart->SetSize(200.0f, 50.0f);
		m_pStart->SetDraw(true);
	}*/

	// マップ設置
	SetMap();

	if (m_pBg == nullptr)
	{
		m_pBg = CObject2D::Create();
		m_pBg->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\title.png"));
		m_pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_pBg->SetSize(SCREEN_WIDTH * 0.3f, SCREEN_HEIGHT * 0.3f);
		m_pBg->SetDraw(true);
	}

	//CManager::GetInstance()->GetSound()->Play(CSound::SOUND_LABEL_BGM_TITLE);
	
	return S_OK;
}

//===========================================================
//終了処理
//===========================================================
void CTitle::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();

	if (m_pBg != nullptr)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}

	if (m_pStart != nullptr)
	{
		m_pStart->Uninit();
		m_pStart = nullptr;
	}

	// プレイヤーの破棄
	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Uninit();
		m_pPlayer = nullptr;
	}
	
	CObject::ReleaseAll();
}

//===========================================================
//更新処理
//===========================================================
void CTitle::Update(void)
{
	// キーボードを取得
	CInputKeyboard *InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	// ゲームパッドを取得
	CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	// フェードの情報を取得
	CFade *pFade = CManager::GetInstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_START, 0) == true)
	{//ENTERキーを押したかつシーンがタイトルのとき

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//シーンをゲームに遷移
			pFade->Set(CScene::MODE_TUTORIAL);
		}
	}

	CManager::GetInstance()->GetDebugProc()->Print("現在のシーン：タイトル");
}

//===========================================================
//描画処理
//===========================================================
void CTitle::Draw(void)
{
	
}