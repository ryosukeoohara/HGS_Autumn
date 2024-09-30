//===========================================================
//
// プレイヤーの処理[player.h]
// Author 大原怜将
//
//===========================================================
#ifndef _PLAYER_H_             //このマクロ定義がされてなかったら
#define _PLAYER_H_             //2重インクルード防止のマクロ定義をする

//===========================================================
// インクルードファイル
//===========================================================
#include "object.h"

//===========================================================
// 前方宣言
//===========================================================
class CCharacter;
class CMotion;
class CPlayerState;
class CGimmick;

//===========================================================
// プレイヤークラス定義
//===========================================================
class CPlayer : public CObject
{
public:
	// 状態
	enum STATE
	{
		STATE_STEP,         // 移動
		STATE_WALK,         // 歩き
		STATE_STAGGER,      // よろけながら歩く
		STATE_ROPEWALK,     // ロープ歩き
		STATE_HAMMER,       // ハンマー
		STATE_DEATH,        // 死亡
		STATE_MAX
	};

	enum MOTIONTYPE
	{
		TYPE_STEP_LEFT = 0,       // ステップ左
		TYPE_STEP_RIGHT,          // ステップ右
		TYPE_WALK_LEFT,           // 歩き左
		TYPE_WALK_RIGHT,          // 歩き右
		TYPE_STAGGER_LEFT,        // 足ぐき左
		TYPE_STAGGER_RIGHT,       // 足ぐき右
		TYPE_ROPEWALK,            // ロープ歩き
		TYPE_HAMMER,              // ハンマー
		TYPE_MAX
	};

	enum MOBILITY
	{
		Mobile = 0,  // 動ける
		Immobile,    // 動けない
		MAX
	};

	// 情報
	struct INFO
	{
		D3DXVECTOR3 pos;          // 位置
		D3DXVECTOR3 posOld;       // 前回の位置
		D3DXVECTOR3 rot;          // 向き
		D3DXVECTOR3 move;         // 移動
		D3DXCOLOR col;            // 色
		D3DXMATRIX mtxWorld;      // ワールドマトリックス
		STATE state;              // 状態
		int nLife;                // 体力
		float fSpeed;
	};

private:

	INFO m_Info;                          // 情報
	MOBILITY m_Mobility;
	
public:
	CPlayer();  //コンストラクタ
	CPlayer(D3DXVECTOR3 pos, int nPriority = 2);  //コンストラクタ(オーバーロード)
	~CPlayer();  //デストラクタ

	HRESULT Init(void);        // 初期化処理    
	void Uninit(void);		   // 終了処理
	void Update(void);         // 更新処理
	void Draw(void);           // 描画処理

	static CPlayer *Create(D3DXVECTOR3 pos, int nPriority = 2);  // 生成

	//　設定系
	void SetPosition(D3DXVECTOR3 pos) { m_Info.pos = pos; }          // 位置設定
	void SetRotition(D3DXVECTOR3 rot) { m_Info.rot = rot; }          // 向き設定
	void SetMove(D3DXVECTOR3 move) { m_Info.move = move; }           // 移動量設定
	void SetState(STATE state);							             // 状態
	void SetLife(int nlife) { m_Info.nLife = nlife; }                // 体力
	void SetMobile(void) { m_Mobility = Mobile; }                    // 動けるようにする
	void SetImmobile(void) { m_Mobility = Immobile; }                // 動けないようにする
	void SetDefeat(int nValue) { m_nDefeat = nValue; }
	void SetUseMicroCount(int nValue) { m_nUseCounter = nValue; }
	void SetbHeatActFlag(bool bValue) { m_bHeatActFlag = bValue; }
	void ChangeState(CPlayerState* pState);

	// 取得系
	D3DXVECTOR3 GetPosition(void) { return m_Info.pos; }       // 位置取得
	D3DXVECTOR3 GetRotition(void) { return m_Info.rot; }       // 向き取得
	D3DXVECTOR3 GetMove(void) { return m_Info.move; }          // 移動量取得
	STATE GetState(void) { return m_Info.state; }              // 状態
	int GetLife(void) { return m_Info.nLife; }                 // 体力
	D3DXMATRIX *GetMatrix(void) { return &m_Info.mtxWorld; }   // マトリックス
	bool GetbAttack(void) { return m_bAttack; }                // 攻撃中かどうか
	static CPlayer *GetInstance(void) { return m_pPlayer; }
	int GetDefeat(void) { return m_nDefeat; }
	bool GetHeatActFlag(void) { return m_bHeatActFlag; }
	MOBILITY GetMobility(void) { return m_Mobility; }
	CMotion* GetMotion(void) { return m_pMotion; }
	CPlayer::INFO *GetInfo(void) { return &m_Info; }


private:

	// メンバ関数
	void Control(void);                   // 制御
	void ReadText(const char *filename);
	void Move(void);
	void Hammer(void);
	void NextMotion();

	void debugKey(void);

	float m_fWindSpeed = 0.0f;
	float m_fRot = 0.0f;
	
	// メンバ変数
	int m_nNumModel;                    //モデル(パーツ)の総数
	int m_nIdxTexture;
	int m_nIdxShaadow;
	int m_nIdx;
	int m_nParent;
	int m_nCntColi;
	int m_nDamegeCounter;
	int m_nUseCounter;
	int m_nDebugState = 0;
	char m_filename[128] = {};
	int m_nButtonPushCounter = 0;
	int m_nLeg;

	D3DXVECTOR3 m_Readpos;
	D3DXVECTOR3 m_Readrot;
	D3DXVECTOR3 m_posOrigin;   
	
	CCharacter** m_appCharacter;
	CMotion* m_pMotion;
	CGimmick* m_pGimmick;		// ギミック
	CPlayerState* m_pState;
	static CPlayer *m_pPlayer;
	int m_nDefeat;  // 敵を倒した数
	int m_nIdxEne;
	int m_nIdxItem;
	int m_nDamageCounter;
	int m_nCntSound;
	float m_fDest;
	float m_fDestOld;
	float m_fDiff;
	float m_fGrapRot;
	float m_fStamina;                     // スタミナ
	bool m_bDesh;                         // ダッシュ
	bool m_bAttack;                       // 攻撃
	bool m_bEvasion;                      // 回避
	bool m_bLift;                         // 持ち上げる
	bool m_bGrap;                         // 投げ
	bool m_bInvi;                         // 無敵かどうか
	bool m_bHeatActFlag;                  // ヒートアクションしているかどうか

	//チュートリアルで使う関数,変数
	void ControlTutorial(void);          // チュートリアルのプレイヤーの制御
	bool m_bPushW;                       // Wキーを押した
	bool m_bPushA;                       // Aキーを押した
	bool m_bPushS;                       // Sキーを押した
	bool m_bPushD;                       // Dキーを押した
	bool m_bAvoi;                        // 回避した
	bool m_bWhee;                        // ホイールを回転した
};

//===========================================================
// プレイヤーステイト
//===========================================================
class CPlayerState
{
public:
	CPlayerState();
	~CPlayerState() {};

	virtual void Update(CPlayer* pPlayer) = 0;

private:

};

// ステップ
class CPlayerStateStep : public CPlayerState
{
public:
	CPlayerStateStep();
	~CPlayerStateStep() {};

	void Update(CPlayer* pPlayer) override;

private:

};

// 歩き
class CPlayerStateWalk : public CPlayerState
{
public:
	CPlayerStateWalk();
	~CPlayerStateWalk() {};

	void Update(CPlayer* pPlayer) override;

private:

};

// 足ぐき
class CPlayerStateStagger : public CPlayerState
{
public:
	CPlayerStateStagger();
	~CPlayerStateStagger() {};

	void Update(CPlayer* pPlayer) override;

private:

};

// ロープ歩き
class CPlayerStateRopeWalk : public CPlayerState
{
public:
	CPlayerStateRopeWalk();
	~CPlayerStateRopeWalk() {};

	void Update(CPlayer* pPlayer) override;

private:

	float m_fTiltAngle = 0.0f;

};

// ハンマー
class CPlayerStateHummer : public CPlayerState
{
public:
	CPlayerStateHummer();
	~CPlayerStateHummer() {};

	void Update(CPlayer* pPlayer) override;

private:

	int m_nButtonPushCounter = 0;
};

#endif