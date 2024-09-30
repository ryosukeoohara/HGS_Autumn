//===========================================================
//
// マネージャ処理[manager.cpp]
// Author 大原怜将
//
//===========================================================
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "manager.h"
#include "input.h"
#include "sound.h"
#include "input.h"
#include "time.h"
#include "debugproc.h"
#include "camera.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "pause.h"
#include "title.h"
#include "light.h"
#include "result.h"
#include "tutorial.h"
#include "utility.h"
#include "InputMouse.h"
#include "InputJoyPad.h"
#include "objectX.h"
#include"field.h"

//===========================================================
//静的メンバ変数
//===========================================================
CManager *CManager::m_pManager = nullptr;
CGame  *CScene::m_Game = nullptr;
CTutorial *CScene::m_Tutorial = nullptr;
CTitle *CScene::m_Title = nullptr;
CResult *CScene::m_Result = nullptr;
CScene::MODE CScene::m_mode = CScene::MODE_TITLE;

//===========================================================
// 生成
//===========================================================
CManager * CManager::GetInstance()
{
	if (m_pManager == nullptr)
	{
		return m_pManager = new CManager;
	}
	else
	{
		return m_pManager;
	}
}

//================================================================
// 破棄
//================================================================
HRESULT CManager::Release(void)
{
	if (m_pManager != nullptr)
	{
		m_pManager->Uninit();

		delete m_pManager;

		m_pManager = nullptr;
	}

	return S_OK;
}

//================================================================
// コンストラクタ
//================================================================
CManager::CManager()
{
	m_ResetCounter = 0;
	m_nDefeat = 0;
	m_bPause = false;
	m_pUtility = nullptr;
}

//================================================================
// デストラクタ
//================================================================
CManager::~CManager()
{

}

//================================================================
// 初期化処理
//================================================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	if (m_Renderer == nullptr)
	{//使用されていなかったら

		//レンダラーの生成
		m_Renderer = new CRenderer;

		//初期化処理
		m_Renderer->Init(hWnd, TRUE);
	}

	if (m_InputKeyboard == nullptr)
	{//使用されていなかったら

		//キーボードの生成
		m_InputKeyboard = new CInputKeyboard;

		//初期化処理
		m_InputKeyboard->Init(hInstance, hWnd);
	}

	if (m_InputMouse == nullptr)
	{//使用されていなかったら

		//マウス生成
		m_InputMouse = new CInputMouse;

		//初期化処理
		m_InputMouse->Init(hInstance, hWnd);
	}

	if (m_InputJoyPad == nullptr)
	{//使用されていなかったら

		//ゲームパッドの生成
		m_InputJoyPad = new CInputJoyPad;

		//初期化処理
		m_InputJoyPad->Init();
	}

	if (m_Sound == nullptr)
	{//使用されていなかったら

		//サウンドの生成
		m_Sound = new CSound;

		//初期化処理
		m_Sound->Init(hWnd);
	}

	if (m_DebugProc == nullptr)
	{//使用されていなかったら

		//デバッグプロックの生成
		m_DebugProc = new CDebugProc;

		//初期化処理
		m_DebugProc->Init();
	}

	if (m_Light == nullptr)
	{//使用されていなかったら

	 //ライトを生成
		m_Light = new CLight;

		//初期化処理
		m_Light->Init();
	}

	if (m_Camera == nullptr)
	{//使用されていなかったら

		//カメラを生成
		m_Camera = new CCamera;

		//初期化処理
		m_Camera->Init();
	}

	if (m_Light == nullptr)
	{//使用されていなかったら

	 //ライトを生成
		m_Light = new CLight;

		//初期化処理
		m_Light->Init();
	}

	if (m_Texture == nullptr)
	{//使用されていなかったら

		//テクスチャを生成
		m_Texture = new CTexture;

		//初期化処理
		m_Texture->Load();
	}

	if (m_pScene == nullptr)
	{//使用されていなかったら

		//シーンの生成
		m_pScene = CScene::Create(CScene::MODE_TITLE);

		//初期化処理
		m_pScene->Init();
	}

	if (m_Fade == nullptr)
	{//使用されていなかったら

		//フェードを生成
		m_Fade = new CFade;

		//初期化処理
		m_Fade->Init();
	}

	return S_OK;
}

//================================================================
// 終了処理
//================================================================
void CManager::Uninit(void)
{
	//サウンドを止める
	m_Sound->Stop();

	//シーンの破棄
	if (m_pScene != nullptr)
	{
		//シーンの終了処理
		m_pScene->Uninit();

		//メモリを開放
		delete m_pScene;

		//使用していない状態にする
		m_pScene = nullptr;
	}

	//レンダラーの破棄
	if (m_Renderer != nullptr)
	{
		//レンダラーの終了処理
		m_Renderer->Uninit();

		//メモリを開放
		delete m_Renderer;

		//使用していない状態にする
		m_Renderer = nullptr;
	}

	//キーボードの破棄
	if (m_InputKeyboard != nullptr)
	{
		//キーボードの終了処理
		m_InputKeyboard->Uninit();

		//メモリを開放
		delete m_InputKeyboard;

		//使用していない状態にする
		m_InputKeyboard = nullptr;
	}

	//マウスの破棄
	if (m_InputMouse != nullptr)
	{
		//マウスの終了処理
		m_InputMouse->Uninit();

		//メモリを開放
		delete m_InputMouse;

		//使用していない状態にする
		m_InputMouse = nullptr;
	}

	//ゲームパッドの破棄
	if (m_InputJoyPad != nullptr)
	{
		//ゲームパッドの終了処理
		m_InputJoyPad->Uninit();

		//メモリを開放
		delete m_InputJoyPad;

		//使用していない状態にする
		m_InputJoyPad = nullptr;
	}

	//サウンドの破棄
	if (m_Sound != nullptr)
	{
		//サウンドの終了処理
		m_Sound->Uninit();
	
		//メモリを開放
		delete m_Sound;

		//使用していない状態にする
		m_Sound = nullptr;
	}

	//デバッグプロックの破棄
	if (m_DebugProc != nullptr)
	{
		//デバッグプロックの終了処理
		m_DebugProc->Uninit();

		//メモリを開放
		delete m_DebugProc;

		//使用していない状態にする
		m_DebugProc = nullptr;
	}

	//カメラの破棄
	if (m_Camera != nullptr)
	{
		//デバッグプロックの終了処理
		m_Camera->Uninit();

		//メモリを開放
		delete m_Camera;

		//使用していない状態にする
		m_Camera = nullptr;
	}

	//ライトの破棄
	if (m_Light != nullptr)
	{
		//デバッグプロックの終了処理
		m_Light->Uninit();

		//メモリを開放
		delete m_Light;

		//使用していない状態にする
		m_Light = nullptr;
	}

	//テクスチャの破棄
	if (m_Texture != nullptr)
	{
		//テクスチャの終了処理
		m_Texture->UnLoad();

		//メモリを開放
		delete m_Texture;

		//使用していない状態にする
		m_Texture = nullptr;
	}

	//フェードの破棄
	if (m_Fade != nullptr)
	{
		//フェードの終了処理
		m_Fade->Uninit();

		//メモリを開放
		delete m_Fade;

		//使用していない状態にする
		m_Fade = nullptr;
	}
}

//================================================================
// 更新処理
//================================================================
void CManager::Update(void)
{
	// レンダラーの更新処理
	if (m_Renderer != nullptr)
		m_Renderer->Update();

	// キーボードの更新処理
	if (m_InputKeyboard != nullptr)
		m_InputKeyboard->Update();

	// マウスの更新処理
	if (m_InputMouse != nullptr)
		m_InputMouse->Update();

	// ゲームパッドの更新処理
	if (m_InputJoyPad != nullptr)
		m_InputJoyPad->Update();

	// カメラの更新
	if (m_Camera != nullptr)
		m_Camera->Update();

	// シーンの更新
	if (m_pScene != nullptr)
		m_pScene->Update();
	
	if ((m_InputKeyboard->GetTrigger(DIK_RETURN) == true || m_InputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true) && m_pScene->GetMode() == CScene::MODE_RESULT)
	{// ENTERキーを押したかつシーンがゲームのとき

		// シーンをタイトルに遷移
		if (m_Fade->Get() != m_Fade->FADE_OUT)
			m_Fade->Set(CScene::MODE_TITLE);

	}

	// 使用しているテクスチャの合計枚数
	int nTexAll = m_Texture->GetNumTexture();

	m_DebugProc->Print("\n<<テクスチャの総数 : %d>>", nTexAll);
	m_DebugProc->Print("\n<<ENTERで次のシーンに遷移>>");
}

//================================================================
//描画処理
//================================================================
void CManager::Draw(void)
{
	//レンダラーの描画処理
	m_Renderer->Draw();

	if (m_pScene != nullptr)
		m_pScene->Draw();

}

//================================================================
// コンストラクタ
//================================================================
CScene::CScene()
{
	
}

//================================================================
// コンストラクタ
//================================================================
CScene::CScene(MODE mode)
{
	m_mode = mode;
}

//================================================================
// デストラクタ
//================================================================
CScene::~CScene()
{

}

//================================================================
// 生成
//================================================================
CScene *CScene::Create(MODE mode)
{
	CScene *pScene = nullptr;

	if (pScene == nullptr)
	{
		pScene = new CScene(mode);

		pScene->Init();
	}

	return pScene;
}

//================================================================
// 初期化処理
//================================================================
HRESULT CScene::Init(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title == nullptr)
		{
			m_Title = new CTitle;

			m_Title->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FixedCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial == nullptr)
		{
			m_Tutorial = new CTutorial;

			m_Tutorial->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FollowPlayerCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;

	case MODE_GAME:

		if (m_Game == nullptr)
		{
			m_Game = new CGame;

			m_Game->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FollowPlayerCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;

	case MODE_RESULT:

		if (m_Result == nullptr)
		{
			m_Result = new CResult;

			m_Result->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FixedCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;
	}

	return S_OK;
}

//================================================================
// 終了処理
//================================================================
void CScene::Uninit(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != nullptr)
		{
			m_Title->Uninit();

			delete m_Title;

			m_Title = nullptr;
		}

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial != nullptr)
		{
			m_Tutorial->Uninit();

			delete m_Tutorial;

			m_Tutorial = nullptr;
		}

		break;

	case MODE_GAME:

		if (m_Game != nullptr)
		{
			m_Game->Uninit();

			delete m_Game;

			m_Game = nullptr;
		}

		break;

	case MODE_RESULT:

		if (m_Result != nullptr)
		{
			m_Result->Uninit();

			delete m_Result;

			m_Result = nullptr;
		}

		break;
	}
}

//================================================================
// 更新処理
//================================================================
void CScene::Update(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != nullptr)
			m_Title->Update();

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial != nullptr)
			m_Tutorial->Update();

		break;

	case MODE_GAME:

		if (m_Game != nullptr)
			m_Game->Update();

		break;

	case MODE_RESULT:

		if (m_Result != nullptr)
			m_Result->Update();

		break;
	}
}

//================================================================
// 描画
//================================================================
void CScene::Draw(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != nullptr)
			m_Title->Draw();

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial != nullptr)
			m_Tutorial->Draw();

		break;

	case MODE_GAME:

		if (m_Game != nullptr)
			m_Game->Draw();

		break;

	case MODE_RESULT:

		if (m_Result != nullptr)
			m_Result->Draw();

		break;
	}
}

//================================================================
// レンダラーの取得
//================================================================
CRenderer *CManager::GetRenderer(void)
{
	return m_Renderer;
}

//================================================================
// キーボードの取得
//================================================================
CInputKeyboard *CManager::GetKeyBoard(void)
{
	return m_InputKeyboard;
}

//================================================================
// マウス取得
//================================================================
CInputMouse *CManager::GetInputMouse(void)
{
	return m_InputMouse;
}

//================================================================
// ゲームパッド取得
//================================================================
CInputJoyPad *CManager::GetInputJoyPad(void)
{
	return m_InputJoyPad;
}

//================================================================
// サウンドの取得
//================================================================
CSound *CManager::GetSound(void)
{
	return m_Sound;
}

//================================================================
// プレイヤーの取得
//================================================================
CPlayer *CManager::GetPlayer(void)
{
	return m_Player;
}

//================================================================
// デバッグプロックの取得
//================================================================
CDebugProc *CManager::GetDebugProc(void)
{
	return m_DebugProc;
}

//================================================================
// カメラの取得
//================================================================
CCamera *CManager::GetCamera(void)
{
	return m_Camera;
}

//================================================================
// ライトの取得
//================================================================
CLight *CManager::GetLight(void)
{
	return m_Light;
}

//================================================================
// テクスチャの取得
//================================================================
CTexture *CManager::GetTexture(void)
{
	return m_Texture;
}

//================================================================
// モデルの取得
//================================================================
CModel *CManager::GetModel(void)
{
	return m_Model;
}

//================================================================
// オブジェクト3Dの取得
//================================================================
CObject3D *CManager::GetObject3D(void)
{
	return m_Object3D;
}

//================================================================
// 敵の取得
//================================================================
CEnemy *CManager::GetEnemy(void)
{
	return m_Enemy;
}
//================================================================
// 当たり判定の取得
//================================================================
CCollision *CManager::GetCollsion(void)
{
	return m_Collision;
}

//================================================================
// エディットの取得
//================================================================
CEdit *CManager::GetEdit(void)
{
	return m_Edit;
}

//================================================================
// マップの取得
//================================================================
CMap *CManager::GetMap(void)
{
	return m_Map;
}

//================================================================
// シーンの取得
//================================================================
CScene *CManager::GetScene(void)
{
	return m_pScene;
}

//================================================================
// フェードの取得
//================================================================
CFade *CManager::GetFade(void)
{
	return m_Fade;
}

//================================================================
// ポーズの取得
//================================================================
CPause *CManager::GetPause(void)
{
	return m_Pause;
}

//================================================================
// 便利関数の取得
//================================================================
CUtility * CManager::GetUtility(void)
{
	return m_pUtility;
}

//================================================================
// エフェクシアの取得
//================================================================
CMyEffekseer* CManager::GetMyEffekseer(void)
{
	return m_pMyEffekseer;
}

//================================================================
// モード設定
//================================================================
void CManager::SetMode(CScene::MODE mode)
{
	if (m_pScene != nullptr)
	{
		m_pScene->Uninit();

		delete m_pScene;

		m_pScene = nullptr;
	}

	if (m_pScene == nullptr)
	{
		m_pScene = new CScene(mode);

		m_pScene->Init();
	}
}

//================================================================
// マップ用オブジェクトファイル名
//================================================================
namespace MAPFILENAME
{
	// 木のモデル
	const char* MAP_TREE = "data\\MODEL\\Field\\tree0.x";

	// 岩のモデル
	const char* MAP_ROCK = "data\\MODEL\\Field\\rock.x";

	// 岩の欠片モデル
	const char* MAP_ROCK_PIECE = "data\\MODEL\\Field\\rock_piece.x";

	// ロープのモデル
	const char* MAP_ROPE = "data\\MODEL\\Field\\rope.x";

	// 草のモデル
	const char* MAP_GRASS = "data\\MODEL\\Field\\grass.x";

	// 城のモデル
	const char* MAP_CASTLE = "data\\MODEL\\Field\\castle.x";

	// 城のドアのフレームモデル
	const char* MAP_CASTLE_FRAME = "data\\MODEL\\Field\\castle_door_frame.x";

	// 城のドア右モデル
	const char* MAP_CASTLE_DOOR_R = "data\\MODEL\\Field\\castle_door_r.x";

	// 城のドア左モデル
	const char* MAP_CASTLE_DOOR_L = "data\\MODEL\\Field\\castle_door_l.x";

	const char* MAP_SKY = "data\\MODEL\\Field\\sky.x";
}

//================================================================
// マップ設定
//================================================================
void CScene::SetMap(void)
{
	// ここに配置物書いていって
	MAPFILENAME::MAP_TREE;
	MAPFILENAME::MAP_ROCK;
	MAPFILENAME::MAP_ROCK_PIECE;
	MAPFILENAME::MAP_ROPE;
	MAPFILENAME::MAP_GRASS;
	MAPFILENAME::MAP_CASTLE;
	MAPFILENAME::MAP_CASTLE_FRAME;
	MAPFILENAME::MAP_CASTLE_DOOR_R;
	MAPFILENAME::MAP_CASTLE_DOOR_L;

	CField* pRoad = new CField;

	if (pRoad != nullptr)
	{
		pRoad->Init();
		pRoad->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\field_soil.png"));
		pRoad->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		pRoad->SetSize(400.0f, 50000.0f);
		pRoad->SetDraw(true);
	}

	CField* pGrassR = new CField;

	if (pGrassR != nullptr)
	{
		pGrassR->Init();
		pGrassR->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\field_grass.jpg"));
		pGrassR->SetPosition(D3DXVECTOR3(600.0f, 0.0f, 0.0f));
		pGrassR->SetSize(800.0f, 50000.0f);
		pGrassR->SetDraw(true);
	}

	CField* pGrassL = new CField;

	if (pGrassL != nullptr)
	{
		pGrassL->Init();
		pGrassL->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\field_grass.jpg"));
		pGrassL->SetPosition(D3DXVECTOR3(-600.0f, 0.0f, 0.0f));
		pGrassL->SetSize(800.0f, 50000.0f);
		pGrassL->SetDraw(true);
	}

	for (int i = 0; i <130; i++)
	{
		CObjectX::Create(MAPFILENAME::MAP_TREE, D3DXVECTOR3(1000.0f, -100.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_TREE, D3DXVECTOR3(-1200.0f, -100.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_GRASS, D3DXVECTOR3(400.0f, 0.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_GRASS, D3DXVECTOR3(-400.0f, 0.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_ROCK_PIECE, D3DXVECTOR3(500.0f, 0.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_ROCK_PIECE, D3DXVECTOR3(-500.0f, 0.0f, -2500.0f - (500 * i)));
	}

	CObjectX::Create(MAPFILENAME::MAP_CASTLE, D3DXVECTOR3(0.0f, 0.0f, -71000));
	CObjectX::Create(MAPFILENAME::MAP_CASTLE_FRAME, D3DXVECTOR3(0.0f, 0.0f, -70000.0f));
	CObjectX::Create(MAPFILENAME::MAP_CASTLE_DOOR_R, D3DXVECTOR3(55.0f, 0.0f, -70000.0f));
	CObjectX::Create(MAPFILENAME::MAP_CASTLE_DOOR_L, D3DXVECTOR3(-60.0f, 0.0f, -70000.0f));
	CObjectX::Create(MAPFILENAME::MAP_SKY, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

//================================================================
// モードの取得
//================================================================
CScene::MODE CScene::GetMode(void)
{
	return m_mode;
}