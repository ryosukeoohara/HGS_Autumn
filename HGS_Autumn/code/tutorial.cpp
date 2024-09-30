//===========================================================
//
// �`���[�g���A������[tutorial.cpp]
// Author �匴�叫
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
// �ÓI�����o�ϐ�
//===========================================================
CPlayer *CTutorial::m_pPlayer = nullptr;
CEnemyManager *CTutorial::m_pEnemyManager = nullptr;
CItemManager* CTutorial::m_pItemManager = nullptr;
CMap *CTutorial::m_pMap = nullptr;
CTutorialUI *CTutorial::m_pUI = nullptr;

//===========================================================
// �R���X�g���N�^
//===========================================================
CTutorial::CTutorial()
{
	m_pField = nullptr;
	m_pEnemy = nullptr;
	m_pItemManager = nullptr;
	m_pStart = nullptr;
}

//===========================================================
// �f�X�g���N�^
//===========================================================
CTutorial::~CTutorial()
{
	
}

//===========================================================
// ��������
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
// ����������
//===========================================================
HRESULT CTutorial::Init(void)
{

	// �}�b�v�ݒu
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
// �I������
//===========================================================
void CTutorial::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();

	// �j��
	
	// �w�i
	if (m_pBg != nullptr)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}

	CObject::ReleaseAll();
}

//===========================================================
// �X�V����
//===========================================================
void CTutorial::Update(void)
{
	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::GetInstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true)
	{//ENTER�L�[�����������V�[�����^�C�g���̂Ƃ�

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//�V�[�����Q�[���ɑJ��
			pFade->Set(CScene::MODE_GAME);
		}
	}
	
	// ���ׂčX�V
	CObject::UpdateAll();
}

//===========================================================
// �`�揈��
//===========================================================
void CTutorial::Draw(void)
{
	
}