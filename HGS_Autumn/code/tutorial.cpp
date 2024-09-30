//===========================================================
//
// チュートリアル処理[tutorial.cpp]
// Author 大原怜将
//
//===========================================================
#include "tutorial.h"
#include "input.h"
#include "InputKeyBoard.h"
#include "InputJoyPad.h"
#include "sound.h"
#include "fade.h"
#include "texture.h"
#include "debugproc.h"
#include "renderer.h"
#include "camera.h"
#include "player.h"
#include "collision.h"

//===========================================================
// 静的メンバ変数
//===========================================================
CPlayer *CTutorial::m_pPlayer = nullptr;
CEnemyManager *CTutorial::m_pEnemyManager = nullptr;
CItemManager* CTutorial::m_pItemManager = nullptr;
CMap *CTutorial::m_pMap = nullptr;
CTutorialUI *CTutorial::m_pUI = nullptr;

//===========================================================
// コンストラクタ
//===========================================================
CTutorial::CTutorial()
{
	m_pField = nullptr;
	m_pEnemy = nullptr;
	m_pItemManager = nullptr;
	m_pStart = nullptr;
}

//===========================================================
// デストラクタ
//===========================================================
CTutorial::~CTutorial()
{
	
}

//===========================================================
// 生成処理
//===========================================================
CTutorial * CTutorial::Create(void)
{
	CTutorial *pTutorial = NULL;

	if (pTutorial == NULL)
	{
		pTutorial = new CTutorial;

		pTutorial->Init();
	}

	return pTutorial;
}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CTutorial::Init(void)
{

	// マップ設置
	//SetMap();

	if (m_pBg == nullptr)
	{
		m_pBg = CObject2D::Create();
		m_pBg->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\tutorial.png"));
		m_pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_pBg->SetSize(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
		m_pBg->SetDraw(true);
	}

	CManager::GetInstance()->GetSound()->Play(CSound::SOUND_LABEL_BGM_TUTORIAL);

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CTutorial::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();

	// 破棄
	
	// 背景
	if (m_pBg != nullptr)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}

	CObject::ReleaseAll();
}

//===========================================================
// 更新処理
//===========================================================
void CTutorial::Update(void)
{
	//キーボードを取得
	CInputKeyboard *InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	//ゲームパッドを取得
	CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	//フェードの情報を取得
	CFade *pFade = CManager::GetInstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true)
	{//ENTERキーを押したかつシーンがタイトルのとき

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//シーンをゲームに遷移
			pFade->Set(CScene::MODE_GAME);
		}
	}
	
	// すべて更新
	CObject::UpdateAll();
}

//===========================================================
// 描画処理
//===========================================================
void CTutorial::Draw(void)
{
	
}