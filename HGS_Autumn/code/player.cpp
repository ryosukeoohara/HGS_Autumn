//===========================================================
//
// �v���C���[����[player.cpp]
// Author �匴�叫
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
// �ÓI�����o�ϐ�
//===========================================================
CPlayer *CPlayer::m_pPlayer = nullptr;

//===========================================================
// �萔��`
//===========================================================
namespace
{
	const int MAX_LIFE = 200;                                  // �̗͂̍ő�l
	const int DAMAGE_COUNT = 15;                               // �_���[�W��Ԃł��鎞��
	const int MICROWAVE = 3600;                                // �d�q�����W���g�p�����q�[�g�A�N�V�������Ăюg�p�\�ɂȂ�܂ł̎���
	const float GRAP_MOVE_SPEED = 0.7f;                        // �͂ݏ�Ԃ̈ړ��̑���
	const float MOVE_SPEED = 1.0f;                             // �ʏ��Ԃ̈ړ��̑���
	const float MAX_STAMINA = 40.0f;                           // �X�^�~�i�̍ő�l
	const float BOOST_STAMINA = 0.1f;                          // �X�^�~�i�̉񕜒l
	const float LOST_STMINA = 10.0f;                           // ����̃X�^�~�i�����
	const float GRAP_LOST_STMINA = 0.1f;                       // �G��͂�ł��鎞�̃X�^�~�i�����
	const float ATTACK_MAGNETIC_RANGE = 100.0f;                // �U������ƈ�ԋ߂��̓G�Ɏ����ł������O�i����G�Ƃ̋���
	const float MY_RADIUS = 25.0f;                             // �v���C���[�̉���
	const char* PLAYER_TEXT = "data\\TEXT\\setup_player.txt";  // �v���C���[�̃e�L�X�g�t�@�C��

	const D3DXVECTOR3 MAP_LIMIT_MAX = D3DXVECTOR3(800.0f, 0.0f, 1000.0f);   // �}�b�v�̐���
	const D3DXVECTOR3 MAP_LIMIT_MIN = D3DXVECTOR3(-850.0f, 0.0f, -670.0f);  // �}�b�v�̐���
	const float TUTORIAL_MAP_LIMITZ = 30.0f;                                // �`���[�g���A���}�b�v��Z���̐���

	const D3DXVECTOR3 STICK_ENEMY = D3DXVECTOR3(100.0f, 0.0f, 100.0f);      // 
	const D3DXVECTOR2 HEATACT_BUTTON_SIZE = D3DXVECTOR2(25.0f, 25.0f);      // �q�[�g�A�N�V�����\���ɏo��e�N�X�`���̃T�C�Y
}

//===========================================================
// �R���X�g���N�^
//===========================================================
CPlayer::CPlayer()
{
	// ������
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
// �R���X�g���N�^
//===========================================================
CPlayer::CPlayer(D3DXVECTOR3 pos, int nPriority) : CObject(nPriority)
{
	// ������
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
// �f�X�g���N�^
//===========================================================
CPlayer::~CPlayer()
{

}

//===========================================================
// ��������
//===========================================================
CPlayer *CPlayer::Create(D3DXVECTOR3 pos, int nPriority)
{
	// �v���C���[�̃|�C���^
	CPlayer *pPlayer = nullptr;

	if (pPlayer == nullptr)
	{
		// ����
		pPlayer = new CPlayer(pos, nPriority);

		// ����������
		pPlayer->Init();
	}
	
	CGimmick::Create(500.0f,CGimmick::TYPEWALK);

	return pPlayer;
}

//===========================================================
// ����������
//===========================================================
HRESULT CPlayer::Init(void)
{
	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	//�V�[���̏����擾
	CScene *pScene = CManager::GetInstance()->GetScene();

	//��ސݒ�
	SetType(TYPE_PLAYER);

	if (m_pMotion == nullptr)
	{
		m_pMotion = new CMotion;

		//����������
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
// �I������
//================================================================
void CPlayer::Uninit(void)
{
	//�T�E���h�̏����擾
	CSound *pSound = CManager::GetInstance()->GetSound();

	//�T�E���h�X�g�b�v
	pSound->Stop();
	 
	// ���[�V�����̔j��
	if (m_pMotion != nullptr)
	{
		//�I������
		m_pMotion->Uninit();
		delete m_pMotion;
		m_pMotion = nullptr;
	}

	// �p�[�c�̔j��
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
// �X�V����
//================================================================
void CPlayer::Update(void)
{
	// �p�[�c���Ƃ̍X�V
	for (int nCount = 0; nCount < m_nNumModel; nCount++)
	{
		if (m_appCharacter[nCount] != nullptr)
			m_appCharacter[nCount]->Update();

	}

	// ���[�V�����̍X�V
	if (m_pMotion != nullptr)
		m_pMotion->Update();

	if (m_pState != nullptr)
		m_pState->Update(this);

	Move();
	NextMotion();

	//Control();

	debugKey();

	CManager::GetInstance()->GetDebugProc()->Print("\n�v���C���[�̈ʒu�F%f,%f,%f\n", m_Info.pos.x, m_Info.pos.y, m_Info.pos.z);
	CManager::GetInstance()->GetDebugProc()->Print("\n�v���C���[�̌����F%f,%f,%f\n", m_Info.rot.x, m_Info.rot.y, m_Info.rot.z);
	CManager::GetInstance()->GetDebugProc()->Print("�v���C���[�̑��x�؂�ւ��F[1]2.0f, [2]1.0f, [3]0.5f\n");
	CManager::GetInstance()->GetDebugProc()->Print("�M�~�b�N�؂�ւ��F[4]�o�����X, [5]�n���}�[\n");
	CManager::GetInstance()->GetDebugProc()->Print("�v���C���[�̑��x�F%f\n", m_Info.fSpeed);
	CManager::GetInstance()->GetDebugProc()->Print("�n���}�[�A�ŁF%d\n", m_nButtonPushCounter);
	CManager::GetInstance()->GetDebugProc()->Print("�������̕ύX�F[B�{�^��]\n");
}

//================================================================
// �`�揈��
//================================================================
void CPlayer::Draw(void)
{
	CTexture *pTexture = CManager::GetInstance()->GetTexture();
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	pDevice->SetTexture(0, pTexture->GetAddress(m_nIdxTexture));

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_Info.mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_Info.rot.y, m_Info.rot.x, m_Info.rot.z);

	D3DXMatrixMultiply(&m_Info.mtxWorld, &m_Info.mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_Info.pos.x, m_Info.pos.y, m_Info.pos.z);

	D3DXMatrixMultiply(&m_Info.mtxWorld, &m_Info.mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
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
// ���䏈��
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
// ���̃��[�V�����ݒ�
//================================================================
void CPlayer::NextMotion()
{
	// �I�����Ă���Ƃ��̂�
	if (!m_pMotion->IsFinish()) { return; }

	int type = m_pMotion->GetType();

	// �����Ă���Ƃ��̂�
	if (type > MOTIONTYPE::TYPE_STAGGER_RIGHT) { return; }

	int leg = type % 2;

	// ����
	if (leg == 0) {
		m_pMotion->Set(type + 1);
	}
	else {	// �E��
		m_pMotion->Set(type - 1);
	}
}

//================================================================
// �ړ�����
//================================================================
void CPlayer::Move(void)
{
	//�Q�[���p�b�h���擾
	CInputJoyPad* pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	if (pInputJoyPad == nullptr)
		return;

	//// �^�C�~���O
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

	//	CManager::GetInstance()->GetDebugProc()->Print("���݂̃M�~�b�N�F�^�C�~���O\n");
	//}

	// �o�����X
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

		CManager::GetInstance()->GetDebugProc()->Print("���݂̃M�~�b�N�F�o�����X\n");
	}
	
	m_Info.move.z -= m_Info.fSpeed;

	// �ʒu�Ɉړ��ʉ��Z
	m_Info.pos.x += m_Info.move.x;
	m_Info.pos.z += m_Info.move.z;

	// �ړ��ʂ��X�V(����������)
	m_Info.move.x += (0.0f - m_Info.move.x) * 0.1f;
	m_Info.move.z += (0.0f - m_Info.move.z) * 0.1f;
}

//================================================================
// �n���}�[����
//================================================================
void CPlayer::Hammer(void)
{
	////�Q�[���p�b�h���擾
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

// �M�~�b�N�̃f�o�b�N
//================================================================
// ��Ԃ̐ݒ�
//================================================================
void CPlayer::SetState(STATE state)
{
	m_Info.state = state;
}

//================================================================
// �X�e�C�g�̕ύX
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
	//�L�[�{�[�h���擾
	CInputKeyboard* InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	//�Q�[���p�b�h���擾
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

	// �M�~�b�N�̐؂�ւ�
	if (InputKeyboard->GetTrigger(DIK_4) == true)
	{
		m_nDebugState = m_nDebugState ? 0 : 1;

		m_Info.rot.z = 0.0f;

		//m_pMotion->Set(TYPE_ROPEWALK);

		ChangeState(new CPlayerStateRopeWalk);
	}

	// �������̕ύX
	if (pInputJoyPad->GetTrigger(pInputJoyPad->BUTTON_B, 0) == true)
	{
		m_fWindSpeed *= -1.0f;
	}

	// �n���}�[
	if (InputKeyboard->GetTrigger(DIK_5) == true)
	{
		m_Info.state = STATE_HAMMER;

		ChangeState(new CPlayerStateHummer);
	}
}

//================================================================
// �O���t�@�C���ǂݍ���
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

	//�e�N�X�`���̏��擾
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	FILE *pFile;   //�t�@�C���|�C���^��錾

	pFile = fopen(fliename, "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ

		fscanf(pFile, "%s", &aString[0]);

		if (strcmp("SCRIPT", aString) == 0)
		{
			while (strcmp("END_SCRIPT", aString) != 0)
			{
				fscanf(pFile, "%s", &aString[0]);

				if (strcmp("NUM_MODEL", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%d", &m_nNumModel);  //���f���̑���

					m_appCharacter = new CCharacter*[m_nNumModel];

				}  //NUM_MODEL�̂�����

				if (strcmp("MODEL_FILENAME", aString) == 0)
				{
					fscanf(pFile, "%s", &aString);          //=
					fscanf(pFile, "%s", &m_filename[0]);  //���f���̖��O

					m_appCharacter[nCntModel] = CCharacter::Create(m_filename);
					nCntModel++;

					nCntParts++;

				}  //MODEL_LILENAME�̂�����

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
									fscanf(pFile, "%d", &m_nIdx);  //���f���̔ԍ�
								}

								if (strcmp("PARENT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);          //=
									fscanf(pFile, "%d", &m_nParent);  //�e���f���̔ԍ�

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
									fscanf(pFile, "%f", &m_Readpos.x);  //���f���̑���
									fscanf(pFile, "%f", &m_Readpos.y);  //���f���̑���
									fscanf(pFile, "%f", &m_Readpos.z);  //���f���̑���

									m_appCharacter[nCntParts2]->SetPositionOri(m_Readpos);

									m_appCharacter[nCntParts2]->SetPosition(m_Readpos);
								}

								if (strcmp("ROT", aString) == 0)
								{
									fscanf(pFile, "%s", &aString);      //=
									fscanf(pFile, "%f", &m_Readrot.x);  //���f���̑���
									fscanf(pFile, "%f", &m_Readrot.y);  //���f���̑���
									fscanf(pFile, "%f", &m_Readrot.z);  //���f���̑���

									m_appCharacter[nCntParts2]->SetRotOrigin(m_Readrot);

									m_appCharacter[nCntParts2]->SetRot(m_Readrot);
								}

							}//END_PARTSSET�̂�����

							nCntParts2++;

						}//PARTSSET�̂�����

					}//END_CHARACTERSET�̂����� 

				}//CHARACTERSET�̂����� 
			}
		}

		//�t�@�C�������
		fclose(pFile);
	}
	else
	{
		return;
	}

	if (m_pMotion != nullptr)
	{
		// ���f���̐ݒ�
		m_pMotion->SetModel(m_appCharacter, m_nNumModel);

		// ����������
		m_pMotion->ReadText(fliename);

		// �v���C���[�̏������[�V�����ݒ�
		m_pMotion->InitPose(TYPE_STEP_LEFT);
	}
}

//============================================================================
// �X�e�C�g
//============================================================================
CPlayerState::CPlayerState()
{

}

//================================================================
// �X�e�b�v
//================================================================
CPlayerStateStep::CPlayerStateStep()
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	//Info->fSpeed = 2.0f;

	Info->state = CPlayer::STATE_STEP;
}

void CPlayerStateStep::Update(CPlayer* pPlayer)
{
	//�Q�[���p�b�h���擾
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
// ����
//================================================================
CPlayerStateWalk::CPlayerStateWalk()
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	//Info->fSpeed = 1.0f;

	Info->state = CPlayer::STATE_WALK;
}

void CPlayerStateWalk::Update(CPlayer* pPlayer)
{
	//�Q�[���p�b�h���擾
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
// ����������
//================================================================
CPlayerStateStagger::CPlayerStateStagger()
{
	CPlayer::INFO* Info = CPlayer::GetInstance()->GetInfo();

	//Info->fSpeed = 0.5f;

	Info->state = CPlayer::STATE_STAGGER;
}

void CPlayerStateStagger::Update(CPlayer* pPlayer)
{
	//�Q�[���p�b�h���擾
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
// ���[�v����
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

	//�Q�[���p�b�h���擾
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
// �}�O���n���}�[�U���
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
	//�Q�[���p�b�h���擾
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