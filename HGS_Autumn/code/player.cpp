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
	const char* PLAYER_TEXT = "data\\TEXT\\motion_player.txt"; // �v���C���[�̃e�L�X�g�t�@�C��

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
	m_Info.state = STATE_NONE;
	m_Info.nLife = 0;
	D3DXMatrixIdentity(&m_Info.mtxWorld);

	m_pPlayer = this;
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
	m_Info.state = STATE_NONE;
	m_Info.nLife = 0;
	D3DXMatrixIdentity(&m_Info.mtxWorld);

	m_pPlayer = this;
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

		m_pMotion->Set(TYPE_NEUTRAL);
	}

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

	CManager::GetInstance()->GetDebugProc()->Print("\n�v���C���[�̈ʒu�F%f,%f,%f\n", m_Info.pos.x, m_Info.pos.y, m_Info.pos.z);
	CManager::GetInstance()->GetDebugProc()->Print("�v���C���[�̌����F%f,%f,%f\n", m_Info.rot.x, m_Info.rot.y, m_Info.rot.z);
	CManager::GetInstance()->GetDebugProc()->Print("�͂�ł���G�̔ԍ�:%d", m_nIdxEne);
	CManager::GetInstance()->GetDebugProc()->Print("�|�������F%d\n", m_nDefeat);
}

//================================================================
// �ړ�����
//================================================================
void CPlayer::Move(void)
{
	
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
		m_pMotion->InitPose(TYPE_NEUTRAL);
	}
}