//===========================================================
//
// �v���C���[�̏���[player.h]
// Author �匴�叫
//
//===========================================================
#ifndef _PLAYER_H_             //���̃}�N����`������ĂȂ�������
#define _PLAYER_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

//===========================================================
// �C���N���[�h�t�@�C��
//===========================================================
#include "object.h"

//===========================================================
// �O���錾
//===========================================================
class CCharacter;
class CMotion;
class CPlayerState;
class CGimmick;

//===========================================================
// �v���C���[�N���X��`
//===========================================================
class CPlayer : public CObject
{
public:
	// ���
	enum STATE
	{
		STATE_STEP,         // �ړ�
		STATE_WALK,         // ����
		STATE_STAGGER,      // ��낯�Ȃ������
		STATE_ROPEWALK,     // ���[�v����
		STATE_HAMMER,       // �n���}�[
		STATE_DEATH,        // ���S
		STATE_MAX
	};

	enum MOTIONTYPE
	{
		TYPE_STEP_LEFT = 0,       // �X�e�b�v��
		TYPE_STEP_RIGHT,          // �X�e�b�v�E
		TYPE_WALK_LEFT,           // ������
		TYPE_WALK_RIGHT,          // �����E
		TYPE_STAGGER_LEFT,        // ��������
		TYPE_STAGGER_RIGHT,       // �������E
		TYPE_ROPEWALK,            // ���[�v����
		TYPE_HAMMER,              // �n���}�[
		TYPE_MAX
	};

	enum MOBILITY
	{
		Mobile = 0,  // ������
		Immobile,    // �����Ȃ�
		MAX
	};

	// ���
	struct INFO
	{
		D3DXVECTOR3 pos;          // �ʒu
		D3DXVECTOR3 posOld;       // �O��̈ʒu
		D3DXVECTOR3 rot;          // ����
		D3DXVECTOR3 move;         // �ړ�
		D3DXCOLOR col;            // �F
		D3DXMATRIX mtxWorld;      // ���[���h�}�g���b�N�X
		STATE state;              // ���
		int nLife;                // �̗�
		float fSpeed;
	};

private:

	INFO m_Info;                          // ���
	MOBILITY m_Mobility;
	
public:
	CPlayer();  //�R���X�g���N�^
	CPlayer(D3DXVECTOR3 pos, int nPriority = 2);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CPlayer();  //�f�X�g���N�^

	HRESULT Init(void);        // ����������    
	void Uninit(void);		   // �I������
	void Update(void);         // �X�V����
	void Draw(void);           // �`�揈��

	static CPlayer *Create(D3DXVECTOR3 pos, int nPriority = 2);  // ����

	//�@�ݒ�n
	void SetPosition(D3DXVECTOR3 pos) { m_Info.pos = pos; }          // �ʒu�ݒ�
	void SetRotition(D3DXVECTOR3 rot) { m_Info.rot = rot; }          // �����ݒ�
	void SetMove(D3DXVECTOR3 move) { m_Info.move = move; }           // �ړ��ʐݒ�
	void SetState(STATE state);							             // ���
	void SetLife(int nlife) { m_Info.nLife = nlife; }                // �̗�
	void SetMobile(void) { m_Mobility = Mobile; }                    // ������悤�ɂ���
	void SetImmobile(void) { m_Mobility = Immobile; }                // �����Ȃ��悤�ɂ���
	void SetDefeat(int nValue) { m_nDefeat = nValue; }
	void SetUseMicroCount(int nValue) { m_nUseCounter = nValue; }
	void SetbHeatActFlag(bool bValue) { m_bHeatActFlag = bValue; }
	void ChangeState(CPlayerState* pState);

	// �擾�n
	D3DXVECTOR3 GetPosition(void) { return m_Info.pos; }       // �ʒu�擾
	D3DXVECTOR3 GetRotition(void) { return m_Info.rot; }       // �����擾
	D3DXVECTOR3 GetMove(void) { return m_Info.move; }          // �ړ��ʎ擾
	STATE GetState(void) { return m_Info.state; }              // ���
	int GetLife(void) { return m_Info.nLife; }                 // �̗�
	D3DXMATRIX *GetMatrix(void) { return &m_Info.mtxWorld; }   // �}�g���b�N�X
	bool GetbAttack(void) { return m_bAttack; }                // �U�������ǂ���
	static CPlayer *GetInstance(void) { return m_pPlayer; }
	int GetDefeat(void) { return m_nDefeat; }
	bool GetHeatActFlag(void) { return m_bHeatActFlag; }
	MOBILITY GetMobility(void) { return m_Mobility; }
	CMotion* GetMotion(void) { return m_pMotion; }
	CPlayer::INFO *GetInfo(void) { return &m_Info; }


private:

	// �����o�֐�
	void Control(void);                   // ����
	void ReadText(const char *filename);
	void Move(void);
	void Hammer(void);
	void NextMotion();

	void debugKey(void);

	float m_fWindSpeed = 0.0f;
	float m_fRot = 0.0f;
	
	// �����o�ϐ�
	int m_nNumModel;                    //���f��(�p�[�c)�̑���
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
	CGimmick* m_pGimmick;		// �M�~�b�N
	CPlayerState* m_pState;
	static CPlayer *m_pPlayer;
	int m_nDefeat;  // �G��|������
	int m_nIdxEne;
	int m_nIdxItem;
	int m_nDamageCounter;
	int m_nCntSound;
	float m_fDest;
	float m_fDestOld;
	float m_fDiff;
	float m_fGrapRot;
	float m_fStamina;                     // �X�^�~�i
	bool m_bDesh;                         // �_�b�V��
	bool m_bAttack;                       // �U��
	bool m_bEvasion;                      // ���
	bool m_bLift;                         // �����グ��
	bool m_bGrap;                         // ����
	bool m_bInvi;                         // ���G���ǂ���
	bool m_bHeatActFlag;                  // �q�[�g�A�N�V�������Ă��邩�ǂ���

	//�`���[�g���A���Ŏg���֐�,�ϐ�
	void ControlTutorial(void);          // �`���[�g���A���̃v���C���[�̐���
	bool m_bPushW;                       // W�L�[��������
	bool m_bPushA;                       // A�L�[��������
	bool m_bPushS;                       // S�L�[��������
	bool m_bPushD;                       // D�L�[��������
	bool m_bAvoi;                        // �������
	bool m_bWhee;                        // �z�C�[������]����
};

//===========================================================
// �v���C���[�X�e�C�g
//===========================================================
class CPlayerState
{
public:
	CPlayerState();
	~CPlayerState() {};

	virtual void Update(CPlayer* pPlayer) = 0;

private:

};

// �X�e�b�v
class CPlayerStateStep : public CPlayerState
{
public:
	CPlayerStateStep();
	~CPlayerStateStep() {};

	void Update(CPlayer* pPlayer) override;

private:

};

// ����
class CPlayerStateWalk : public CPlayerState
{
public:
	CPlayerStateWalk();
	~CPlayerStateWalk() {};

	void Update(CPlayer* pPlayer) override;

private:

};

// ������
class CPlayerStateStagger : public CPlayerState
{
public:
	CPlayerStateStagger();
	~CPlayerStateStagger() {};

	void Update(CPlayer* pPlayer) override;

private:

};

// ���[�v����
class CPlayerStateRopeWalk : public CPlayerState
{
public:
	CPlayerStateRopeWalk();
	~CPlayerStateRopeWalk() {};

	void Update(CPlayer* pPlayer) override;

private:

	float m_fTiltAngle = 0.0f;

};

// �n���}�[
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