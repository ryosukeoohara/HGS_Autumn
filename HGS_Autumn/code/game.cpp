//===========================================================
//
// �Q�[���Ǘ�[game.cpp]
// Author �匴�叫
//
//===========================================================
#include "game.h"
#include "input.h"
#include "sound.h"
#include "camera.h"
#include "object.h"
#include "debugproc.h"
#include "fade.h"
#include "time.h"
#include "score.h"
#include "pause.h"
#include "player.h"
#include "texture.h"
#include "collision.h"
#include "player.h"
#include "field.h"
#include "InputKeyBoard.h"
#include "InputJoyPad.h"
#include "warning.h"
#include "gimmickButtonMash.h"

//================================================================
// �ÓI�����o�ϐ�
//================================================================
CPause *CGame::m_pPause = nullptr;
bool CGame::m_bPause = false;

//===========================================================
// �R���X�g���N�^
//===========================================================
CGame::CGame()
{
	m_bPause = false;
	m_pPause = nullptr;
	m_pBg = nullptr;
	m_pTimer = nullptr;
}

//===========================================================
// �R���X�g���N�^
//===========================================================
CGame::CGame(CScene::MODE mode)
{
	m_bPause = false;
	m_pPause = nullptr;
	m_pBg = nullptr;
	m_pPlayer = nullptr;
	m_pTimer = nullptr;
}

//===========================================================
//�@�f�X�g���N�^
//===========================================================
CGame::~CGame()
{

}

//===========================================================
// ����
//===========================================================
CGame *CGame::Create(void)
{
	CGame *pGame = nullptr;

	if (pGame == nullptr)
	{
		pGame = new CGame;

		pGame->Init();
	}

	return pGame;
}

//===========================================================
//�@����������
//===========================================================
HRESULT CGame::Init(void)
{
	// �|�[�Y�̐���
	if (m_pPause == nullptr)
		m_pPause = CPause::Create();

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

	if (m_pCollision == nullptr)
	{
		m_pCollision = new CCollision;
	}

	CGimmickButtonMash* pRock = CGimmickButtonMash::Create(D3DXVECTOR3(0.0f, 0.0f, -10000.0f));

	// �}�b�v�ݒu
	SetMap();

	// �x���̐���
	CWarning::Create(CWarning::TYPE_ROCK);

	// �v���C���[�̐���
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = CPlayer::Create(D3DXVECTOR3(0.0f, 0.0f, 500.0f));
	}

	// �^�C�}�[�̐���
	m_pTimer = CTime::Create();
	
	//CManager::GetInstance()->GetSound()->Play(CSound::SOUND_LABEL_BGM_GAME);

	return S_OK;
}

//===========================================================
//�@�I������
//===========================================================
void CGame::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();

	// �|�[�Y�̔j��
	if (m_pPause != nullptr)
	{
		m_pPause->Uninit();
		m_pPause = nullptr;
	}

	CObject::ReleaseAll();
}

//===========================================================
//�@�X�V����
//===========================================================
void CGame::Update(void)
{
	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	//�}�E�X���擾
	CInputMouse *pInputMouse = CManager::GetInstance()->GetInputMouse();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::GetInstance()->GetFade();

	if (CManager::GetInstance()->GetKeyBoard()->GetTrigger(DIK_P) == true || CManager::GetInstance()->GetInputJoyPad()->GetTrigger(CInputJoyPad::BUTTON_START, 0) == true)
	{
		m_bPause = m_bPause ? false : true;

		if (m_pPause != nullptr)
			m_pPause->SetDraw(m_bPause);

	}

	if (m_bPause == true)
	{
		if (m_pPause != nullptr)
		{
			m_pPause->Update();
			m_pPause->SetDraw(m_bPause);
		}

		return;
	}

	//if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_START, 0) == true)
	//{//ENTER�L�[�����������V�[�����^�C�g���̂Ƃ�

	//	if (pFade->Get() != pFade->FADE_OUT)
	//	{
	//		//�V�[�����Q�[���ɑJ��
	//		pFade->Set(CScene::MODE_RESULT);
	//	}
	//}

	//���ׂĂ̍X�V����
	CObject::UpdateAll();
	
	CDebugProc *pDebugProc = CManager::GetInstance()->GetDebugProc();

	pDebugProc->Print("\n�V�[���F�Q�[��");
}

//===========================================================
//�@�`�揈��
//===========================================================
void CGame::Draw(void)
{
	
}