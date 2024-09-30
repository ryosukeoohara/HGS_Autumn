//===========================================================
//
// リザルト画面[result.cpp]
// Author 大原怜将
//
//===========================================================
#include "result.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"
#include "score.h"
#include "camera.h"
#include "input.h"
#include "InputKeyBoard.h"
#include "InputJoyPad.h"
#include "fade.h"
#include "player.h"
#include "result_time.h"

// 名前空間
namespace
{
	const char* FILENAME[CResult::STATE::STATE_MAX] =
	{
		"data\\TEXTURE\\result\\failed.png",
		"data\\TEXTURE\\result\\success.png",
	};
}

// 静的メンバ変数
int CResult::m_nSuccess = CResult::STATE::STATE_FAILED;
int CResult::m_nTime = 0;

//===========================================================
// コンストラクタ
//===========================================================
CResult::CResult()
{
	m_pNumber = nullptr;
	m_pMap = nullptr;
	m_pUserRank = nullptr;
	m_nCounter = 0;
}

//===========================================================
// デストラクタ
//===========================================================
CResult::~CResult()
{

}

//===========================================================
// 生成処理
//===========================================================
CResult *CResult::Create(void)
{
	CResult *pTitle = NULL;

	if (pTitle == NULL)
	{
		pTitle = new CResult;

		pTitle->Init();
	}

	return pTitle;
}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CResult::Init(void)
{
	// 成功失敗を表示
	{
		CObject2D* pBg = new CObject2D(7);

		if (pBg != nullptr)
		{
			pBg->Init();
			pBg->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist(FILENAME[m_nSuccess]));
			pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.25f, 0.0f));
			pBg->SetSize(SCREEN_WIDTH * 0.3f, SCREEN_HEIGHT * 0.2f);
			pBg->SetDraw(true);
		}
	}

	// 制限時間を表示
	{
		CObject2D* p = new CObject2D(7);
		p->Init();
		p->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\result\\time.png"));
		p->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.35f, SCREEN_HEIGHT * 0.75f, 0.0f));
		p->SetSize(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.1f);
		p->SetDraw(true);

		CResultTime::Create();
	}

	// マップ設置
	SetMap();

	return S_OK;
}

//===========================================================
// 終了処理
//===========================================================
void CResult::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();

	CObject::ReleaseAll();

	m_nSuccess = STATE_FAILED;
	m_nTime = 0;
}

//===========================================================
// 更新処理
//===========================================================
void CResult::Update(void)
{
	//キーボードを取得
	CInputKeyboard *InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	//マウスを取得
	CInputMouse *pInputMouse = CManager::GetInstance()->GetInputMouse();

	//ゲームパッドを取得
	CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	//フェードの情報を取得
	CFade *pFade = CManager::GetInstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_START, 0) == true)
	{//ENTERキーを押したかつシーンがタイトルのとき

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//シーンをゲームに遷移
			pFade->Set(CScene::MODE_TITLE);
		}
	}
}

//===========================================================
// 描画処理
//===========================================================
void CResult::Draw(void)
{
	
}