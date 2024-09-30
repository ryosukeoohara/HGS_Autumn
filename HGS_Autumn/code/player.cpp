//===========================================================
//
// プレイヤー処理[player.cpp]
// Author 大原怜将
//
//===========================================================
#include "main.h"
#include "player.h"
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "InputKeyBoard.h"
#include "InputJoyPad.h"
#include "sound.h"
#include "debugproc.h"
#include "texture.h"
#include "motion.h"
#include "camera.h"
#include "game.h"
#include "fade.h"
#include "character.h"
#include "collision.h"
#include "camera.h"
#include "object.h"
#include "billboard.h"
#include "utility.h"
#include "particle.h"
#include "effect2D.h"
#include "gimmick.h"

//===========================================================
// 静的メンバ変数
//===========================================================
CPlayer *CPlayer::m_pPlayer = nullptr;

//===========================================================
// 定数定義
//===========================================================
namespace
{
	const int MAX_LIFE = 200;                                  // 体力の最大値
	const int DAMAGE_COUNT = 15;                               // ダメージ状態でいる時間
	const int MICROWAVE = 3600;                                // 電子レンジを使用したヒートアクションを再び使用可能になるまでの時間
	const float GRAP_MOVE_SPEED = 0.7f;                        // 掴み状態の移動の速さ
	const float MOVE_SPEED = 1.0f;                             // 通常状態の移動の速さ
	const float MAX_STAMINA = 40.0f;                           // スタミナの最大値
	const float BOOST_STAMINA = 0.1f;                          // スタミナの回復値
	const float LOST_STMINA = 10.0f;                           // 回避のスタミナ消費量
	const float GRAP_LOST_STMINA = 0.1f;                       // 敵を掴んでいる時のスタミナ消費量
	const float ATTACK_MAGNETIC_RANGE = 100.0f;                // 攻撃すると一番近くの敵に自動ですこし前進する敵との距離
	const float MY_RADIUS = 25.0f;                             // プレイヤーの横幅
	const char* PLAYER_TEXT = "data\\TEXT\\setup_player.txt";  // プレイヤーのテキストファイル

	const D3DXVECTOR3 MAP_LIMIT_MAX = D3DXVECTOR3(800.0f, 0.0f, 1000.0f);   // マップの制限
	const D3DXVECTOR3 MAP_LIMIT_MIN = D3DXVECTOR3(-850.0f, 0.0f, -670.0f);  // マップの制限
	const float TUTORIAL_MAP_LIMITZ = 30.0f;                                // チュートリアルマップのZ軸の制限

	const D3DXVECTOR3 STICK_ENEMY = D3DXVECTOR3(100.0f, 0.0f, 100.0f);      // 
	const D3DXVECTOR2 HEATACT_BUTTON_SIZE = D3DXVECTOR2(25.0f, 25.0f);      // ヒートアクション可能時に出るテクスチャのサイズ
}

//===========================================================
// コンストラクタ
//===========================================================
CPlayer::CPlayer()
{
	// 初期化
	m_Info.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	m_Info.nLife = 0;
	D3DXMatrixIdentity(&m_Info.mtxWorld);

	m_pPlayer = this;
	m_nLeg = 0;
	m_pGimmick = nullptr;
}

//===========================================================
// コンストラクタ
//===========================================================
CPlayer::CPlayer(D3DXVECTOR3 pos, int nPriority) : CObject(nPriority)
{
	// 初期化
	m_Info.pos = pos;
	m_Info.posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_Info.col = D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.0f);
	m_Info.nLife = 0;
	D3DXMatrixIdentity(&m_Info.mtxWorld);

	m_pPlayer = this;
	m_pGimmick = nullptr;
}

//===========================================================
// デストラクタ
//===========================================================
CPlayer::~CPlayer()
{

}

//===========================================================
// 生成処理
//===========================================================
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, int nPriority)
{
	// プレイヤーのポインタ
	CPlayer *pPlayer = nullptr;

	if (pPlayer == nullptr)
	{
		// 生成
		pPlayer = new CPlayer(pos, nPriority);

		// 初期化処理
		pPlayer->Init();
	}
	
	CGimmick::Create(500.0f,CGimmick::TYPEWALK);

	return pPlayer;
}

//===========================================================
// 初期化処理
//===========================================================
HRESULT CPlayer::Init(void)
{
	//テクスチャの情報取得
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	//シーンの情報を取得
	CScene *pScene = CManager::GetInstance()->GetScene();

	//種類設定
	SetType(TYPE_PLAYER);

	if (m_pMotion == nullptr)
	{
		m_pMotion = new CMotion;

		//初期化処理
		m_pMotion->Init();

		m_pMotion->Set(TYPE_STEP_RIGHT);
	}

	m_Info.fSpeed = 1.0f;
	m_fWindSpeed = 0.03f;
	m_pState = new CPlayerStateWalk;

	ReadText(PLAYER_TEXT);

	return S_OK;
}

//================================================================
// 終了処理
//================================================================
void CPlayer::Uninit(void)
{
	//サウンドの情報を取得
	CSound *pSound = CManager::GetInstance()->GetSound();

	//サウンドストップ
	pSound->Stop();
	 
	// モーションの破棄
	if (m_pMotion != nullptr)
	{
		//終了処理
		m_pMotion->Uninit();
		delete m_pMotion;
		m_pMotion = nullptr;
	}

	// パーツの破棄
	if (m_appCharacter != nullptr)
	{
		for (int nCount = 0; nCount < m_nNumModel; nCount++)
		{
			if (m_appCharacter[nCount] != nullptr)
			{
				m_appCharacter[nCount]->Uninit();
				m_appCharacter[nCount] = nullptr;
			}
		}

		delete m_appCharacter;
		m_appCharacter = nullptr;
	}

	CObject::Release();
}

//================================================================
// 更新処理
//================================================================
void CPlayer::Update(void)
{
	// パーツごとの更新
	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_appCharacter[nCount] != nullptr)
			m_appCharacter[nCount]->Update();

	}

	// モーションの更新
	if (m_pMotion != nullptr)
		m_pMotion->Update();

	if (m_pState != nullptr)
		m_pState->Update(this);

	Move();
	NextMotion();

	//Control();

	debugKey();

	CManager::GetInstance()->GetDebugProc()->Print("\nプレイヤーの位置：%f,%f,%f\n", m_Info.pos.x, m_Info.pos.y, m_Info.pos.z);
	CManager::GetInstance()->GetDebugProc()->Print("\nプレイヤーの向き：%f,%f,%f\n", m_Info.rot.x, m_Info.rot.y, m_Info.rot.z);
	CManager::GetInstance()->GetDebugProc()->Print("プレイヤーの速度切り替え：[1]2.0f, [2]1.0f, [3]0.5f\n");
	CManager::GetInstance()->GetDebugProc()->Print("ギミック切り替え：[4]バランス, [5]ハンマー\n");
	CManager::GetInstance()->GetDebugProc()->Print("プレイヤーの速度：%f\n", m_Info.fSpeed);
	CManager::GetInstance()->GetDebugProc()->Print("ハンマー連打：%d\n", m_nButtonPushCounter);
	CManager::GetInstance()->GetDebugProc()->Print("風向きの変更：[Bボタン]\n");
}

//================================================================
// 描画処理
//================================================================
void CPlayer::Draw(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_Info.mtxWorld);

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Info.rot.y, m_Info.rot.x, m_Info.rot.z);

	D3DXMatrixMultiply(&m_Info.mtxWorld, &m_Info.mtxWorld, &mtxRot);

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_Info.pos.x, m_Info.pos.y, m_Info.pos.z);

	D3DXMatrixMultiply(&m_Info.mtxWorld, &m_Info.mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_Info.mtxWorld);

	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_appCharacter[nCount] != nullptr)
		{
			m_appCharacter[nCount]->Draw();
		}
	}
}

//================================================================
// 制御処理
//================================================================
void CPlayer::Control(void)
{
	if (m_Info.state == STATE_HAMMER)
	{
		Hammer();
	}
	else
	{
		Move();
	}

	if (m_Info.state == STATE_WALK && STATE_STAGGER && STATE_STEP)
	{
		Move();
	}


}

//================================================================
// 次のモーション設定
//================================================================
void CPlayer::NextMotion()
{
	// 終了しているときのみ
	if (!m_pMotion->IsFinish()) { return; }

	int type = m_pMotion->GetType();

	// 動いているときのみ
	if (type > MOTIONTYPE::TYPE_STAGGER_RIGHT) { return; }

	int leg = type % 2;

	// 左足
	if (leg == 0) {
		m_pMotion->Set(type + 1);
	}
	else {	// 右足
		m_pMotion->Set(type - 1);
	}
}

//================================================================
// 移動処理
//================================================================
void CPlayer::Move(void)
{
	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	if (pInputJoyPad == nullptr)
		return;

	//// タイミング
	//if (m_nDebugState == 0)
	//{
	//	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_LB, 0) == true)
	//	{
	//		m_Info.move.z -= m_Info.fSpeed;

	//		if (m_Info.state == STATE_STEP)
	//		{
	//			m_pMotion->Set(TYPE_STEP_RIGHT);
	//		}

	//		if (m_Info.state == STATE_WALK)
	//		{
	//			m_pMotion->Set(TYPE_WALK_RIGHT);
	//		}

	//		if (m_Info.state == STATE_STAGGER)
	//		{
	//			m_pMotion->Set(TYPE_WALK_RIGHT);
	//		}
	//	}

	//	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_RB, 0) == true)
	//	{
	//		m_Info.move.z -= m_Info.fSpeed;
	//		
	//		if (m_Info.state == STATE_STEP)
	//		{
	//			m_pMotion->Set(TYPE_STEP_LEFT);
	//		}

	//		if (m_Info.state == STATE_WALK)
	//		{
	//			m_pMotion->Set(TYPE_WALK_LEFT);
	//		}

	//		if (m_Info.state == STATE_STAGGER)
	//		{
	//			m_pMotion->Set(TYPE_WALK_LEFT);
	//		}
	//	}

	//	CManager::GetInstance()->GetDebugProc()->Print("現在のギミック：タイミング\n");
	//}

	// バランス
	if (m_nDebugState == 1)
	{
		m_Info.fSpeed = 0.5f;

		if (pInputJoyPad->GetPress(pInputJoyPad->BUTTON_RB, 0) == true)
		{
			if(m_fRot > -0.1f)
			   m_fRot -= 0.007f;
		}
		else if (pInputJoyPad->GetPress(pInputJoyPad->BUTTON_LB, 0) == true)
		{
			if (m_fRot < 0.1f)
				m_fRot += 0.007f;
		}
		else
		{
			m_fRot = 0.0f;
		}

		m_Info.rot.z += (m_fWindSpeed - m_fRot);

		CManager::GetInstance()->GetDebugProc()->Print("現在のギミック：バランス\n");
	}
	
	m_Info.move.z -= m_Info.fSpeed;

	// 位置に移動量加算
	m_Info.pos.x += m_Info.move.x;
	m_Info.pos.z += m_Info.move.z;

	// 移動量を更新(減衰させる)
	m_Info.move.x += (0.0f - m_Info.move.x) * 0.1f;
	m_Info.move.z += (0.0f - m_Info.move.z) * 0.1f;
}

//================================================================
// ハンマー処理
//================================================================
void CPlayer::Hammer(void)
{
	////ゲームパッドを取得
	//CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	//if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_RB, 0) == true)
	//{
	//	m_nButtonPushCounter++;
	//}
	//else if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_LB, 0) == true)
	//{
	//	m_nButtonPushCounter++;
	//}

	//if (m_nButtonPushCounter >= 50)
	//{
	//	m_nButtonPushCounter = 0;

	//	m_pMotion->Set(TYPE_HAMMER);
	//}

	//if (m_pMotion->IsFinish() == true)
	//{
	//	m_Info.state = STATE_STEP;
	//}
}

// ギミックのデバック
//================================================================
// 状態の設定
//================================================================
void CPlayer::SetState(STATE state)
{
	m_Info.state = state;
}

//================================================================
// ステイトの変更
//================================================================
void CPlayer::ChangeState(CPlayerState* pState)
{
	if (m_pState != nullptr)
	{
		delete m_pState;
		m_pState = nullptr;
	}

	m_pState = pState;
}

void CPlayer::debugKey(void)
{
	//キーボードを取得
	CInputKeyboard* InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	if (InputKeyboard->GetTrigger(DIK_1) == true)
	{
		m_Info.state = STATE_STEP;

		ChangeState(new CPlayerStateStep);
	}

	if (InputKeyboard->GetTrigger(DIK_2) == true)
	{
		m_Info.state = STATE_WALK;

		ChangeState(new CPlayerStateWalk);
	}

	if (InputKeyboard->GetTrigger(DIK_3) == true)
	{
		m_Info.state = STATE_STAGGER;

		ChangeState(new CPlayerStateStagger);
	}

	// ギミックの切り替え
	if (InputKeyboard->GetTrigger(DIK_4) == true)
	{
		m_nDebugState = m_nDebugState ? 0 : 1;

		m_Info.rot.z = 0.0f;

		//m_pMotion->Set(TYPE_ROPEWALK);

		ChangeState(new CPlayerStateRopeWalk);
	}

	// 風向きの変更
	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_B, 0) == true)
	{
		m_fWindSpeed *= -1.0f;
	}

	// ハンマー
	if (InputKeyboard->GetTrigger(DIK_5) == true)
	{
		m_Info.state = STATE_HAMMER;

		ChangeState(new CPlayerStateHummer);
	}
}

//================================================================
// 外部ファイル読み込み
//================================================================
void CPlayer::ReadText(const char *fliename)
{
	char aString[128] = {};
	char aComment[128] = {};
	int nCntParts = 0, nCntParts2 = 0, nCntParts3 = 0;
	int nCntMotion = 0;
	int nCntKeySet = 0;
	int nCntKey = 0;
	int nCntModel = 0;
	int nCntMotionIdx = 0;

	//テクスチャの情報取得
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	FILE *pFile;   //ファイルポインタを宣言

	pFile = fopen(fliename, "r");

	if (pFile != NULL)
	{//ファイルを開けた場合

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("NUM_MODEL", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%d", &m_nNumModel);  //モデルの総数

					m_appCharacter = new CCharacter*[m_nNumModel];

				}  //NUM_MODELのかっこ

				if (strcmp("MODEL_FILENAME", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%s", &m_filename[0]);  //モデルの名前

					m_appCharacter[nCntModel] = CCharacter::Create(m_filename);
					nCntModel++;

					nCntParts++;

				}  //MODEL_LILENAMEのかっこ

				if (strcmp("CHARACTERSET", aString) == 0)
				{
					while (strcmp("END_CHARACTERSET", aString) != 0)
					{
						fscanf(pFile, "%s", &aString);

						if (strcmp("PARTSSET", aString) == 0)
						{
							while (strcmp("END_PARTSSET", aString) != 0)
							{
								fscanf(pFile, "%s", &aString);

								if (strcmp("INDEX", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nIdx);  //モデルの番号
								}

								if (strcmp("PARENT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nParent);  //親モデルの番号

									if (m_nParent > -1 && m_nNumModel > m_nParent)
									{
										m_appCharacter[nCntParts2]->SetParent(m_appCharacter[m_nParent]);
									}
									else
									{
										m_appCharacter[nCntParts2]->SetParent(NULL);
									}
								}

								if (strcmp("POS", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readpos.x);  //モデルの総数
									fscanf(pFile, "%f", &m_Readpos.y);  //モデルの総数
									fscanf(pFile, "%f", &m_Readpos.z);  //モデルの総数

									m_appCharacter[nCntParts2]->SetPositionOri(m_Readpos);

									m_appCharacter[nCntParts2]->SetPosition(m_Readpos);
								}

								if (strcmp("ROT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readrot.x);  //モデルの総数
									fscanf(pFile, "%f", &m_Readrot.y);  //モデルの総数
									fscanf(pFile, "%f", &m_Readrot.z);  //モデルの総数

									m_appCharacter[nCntParts2]->SetRotOrigin(m_Readrot);

									m_appCharacter[nCntParts2]->SetRot(m_Readrot);
								}

							}//END_PARTSSETのかっこ

							nCntParts2++;

						}//PARTSSETのかっこ

					}//END_CHARACTERSETのかっこ 

				}//CHARACTERSETのかっこ 
			}
		}

		//ファイルを閉じる
		fclose(pFile);
	}
	else
	{
		return;
	}

	if (m_pMotion != nullptr)
	{
		// モデルの設定
		m_pMotion->SetModel(m_appCharacter, m_nNumModel);

		// 初期化処理
		m_pMotion->ReadText(fliename);

		// プレイヤーの初期モーション設定
		m_pMotion->InitPose(TYPE_STEP_LEFT);
	}
}

//============================================================================
// ステイト
//============================================================================
CPlayerState::CPlayerState()
{

}

//================================================================
// ステップ
//================================================================
CPlayerStateStep::CPlayerStateStep()
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	//Info->fSpeed = 2.0f;

	Info->state = CPlayer::STATE_STEP;
}

void CPlayerStateStep::Update(CPlayer* pPlayer)
{
	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	CMotion* pMotion = pPlayer->GetMotion();

	if (pMotion == nullptr)
		return;

	CPlayer::INFO* Info = pPlayer->GetInfo();

	if (Info->fSpeed < 2.0f)
		Info->fSpeed += 0.03f;

	Info->move.z -= Info->fSpeed;

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_LB, 0) == true)
		pMotion->Set(pPlayer->TYPE_STEP_RIGHT);

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_RB, 0) == true)
		pMotion->Set(pPlayer->TYPE_STEP_LEFT);
}

//================================================================
// 歩き
//================================================================
CPlayerStateWalk::CPlayerStateWalk()
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	//Info->fSpeed = 1.0f;

	Info->state = CPlayer::STATE_WALK;
}

void CPlayerStateWalk::Update(CPlayer* pPlayer)
{
	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	CMotion* pMotion = pPlayer->GetMotion();

	if (pMotion == nullptr)
		return;

	CPlayer::INFO* Info = pPlayer->GetInfo();

	if (Info->fSpeed < 1.0f)
		Info->fSpeed += 0.03f;

	if (Info->fSpeed > 1.0f)
		Info->fSpeed -= 0.03f;

	Info->move.z -= Info->fSpeed;

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_LB, 0) == true)
		pMotion->Set(pPlayer->TYPE_WALK_RIGHT);

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_RB, 0) == true)
		pMotion->Set(pPlayer->TYPE_WALK_LEFT);
}

//================================================================
// 足ぐき歩き
//================================================================
CPlayerStateStagger::CPlayerStateStagger()
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	//Info->fSpeed = 0.5f;

	Info->state = CPlayer::STATE_STAGGER;
}

void CPlayerStateStagger::Update(CPlayer* pPlayer)
{
	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	CMotion* pMotion = pPlayer->GetMotion();

	if (pMotion == nullptr)
		return;

	CPlayer::INFO* Info = pPlayer->GetInfo();

	Info->move.z -= Info->fSpeed;

	if (Info->fSpeed > 0.5f)
		Info->fSpeed -= 0.03f;

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_LB, 0) == true)
		pMotion->Set(pPlayer->TYPE_STAGGER_RIGHT);

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_RB, 0) == true)
		pMotion->Set(pPlayer->TYPE_STAGGER_LEFT);
}

//================================================================
// ロープ歩き
//================================================================
CPlayerStateRopeWalk::CPlayerStateRopeWalk()
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	Info->fSpeed = 0.5f;

	CPlayer* pPlayer = CPlayer::GetInstance();

	pPlayer->GetMotion()->Set(pPlayer->TYPE_ROPEWALK);

	Info->state = CPlayer::STATE_ROPEWALK;
}

void CPlayerStateRopeWalk::Update(CPlayer* pPlayer)
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	if (pInputJoyPad->GetPress(pInputJoyPad->BUTTON_RB, 0) == true)
	{
		if (m_fTiltAngle > -0.1f)
			m_fTiltAngle -= 0.007f;
	}
	else if (pInputJoyPad->GetPress(pInputJoyPad->BUTTON_LB, 0) == true)
	{
		if (m_fTiltAngle < 0.1f)
			m_fTiltAngle += 0.007f;
	}
	else
	{
		m_fTiltAngle = 0.0f;
	}

	Info->rot.z += (0.03f - m_fTiltAngle);
}

//================================================================
// マグロハンマー振り回し
//================================================================
CPlayerStateHummer::CPlayerStateHummer()
{
	CPlayer* pPlayer = CPlayer::GetInstance();

	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	pPlayer->GetMotion()->Set(pPlayer->TYPE_HAMMER);

	Info->state = CPlayer::STATE_HAMMER;

	Info->fSpeed = 0.0f;
}

void CPlayerStateHummer::Update(CPlayer* pPlayer)
{
	//ゲームパッドを取得
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_RB, 0) == true)
	{
		m_nButtonPushCounter++;
	}
	else if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_LB, 0) == true)
	{
		m_nButtonPushCounter++;
	}

	pPlayer->SetButtonPush(m_nButtonPushCounter);

	if (m_nButtonPushCounter >= 50)
	{
		//m_nButtonPushCounter = 0;

		pPlayer->ChangeState(new CPlayerStateWalk);
	}
}