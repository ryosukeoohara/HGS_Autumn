//===========================================================
//
// �^�C�g������[title.cpp]
// Author �匴�叫
//
//===========================================================
#include "title.h"
#include "texture.h"
#include "game.h"
#include "debugproc.h"
#include "renderer.h"
#include "sound.h"
#include "camera.h"
#include "input.h"
#include "fade.h"
#include "player.h"
#include "InputKeyBoard.h"
#include "InputJoyPad.h"

//===========================================================
// �萔��`
//===========================================================
namespace
{
	const D3DXVECTOR3 TEXPOS[3] =   // �ʒu
	{
		D3DXVECTOR3(640.0f, 0.0f, 350.0f),
		D3DXVECTOR3(640.0f, 0.0f, 550.0f),
		D3DXVECTOR3(640.0f, 0.0f, 750.0f),
	};

	const D3DXVECTOR3 CAMERAPOS[3] =   // �ʒu
	{
		D3DXVECTOR3(640.0f, 0.0f, -350.0f),
		D3DXVECTOR3(640.0f, 0.0f, -550.0f),
		D3DXVECTOR3(640.0f, 0.0f, -750.0f),
	};
}

//===========================================================
//�@�ÓI�����o�ϐ�
//===========================================================
CPlayer *CTitle::m_pPlayer = nullptr;

//===========================================================
//�R���X�g���N�^
//===========================================================
CTitle::CTitle()
{
	m_pField = nullptr;
	m_pBg = nullptr;
	m_pMap = nullptr;
	m_pStart = nullptr;
	m_nCnt = 0;
	m_nCntPos = 0;
}

//===========================================================
//�f�X�g���N�^
//===========================================================
CTitle::~CTitle()
{

}

//===========================================================
//����
//===========================================================
CTitle *CTitle::Create(void)
{
	CTitle *pTitle = nullptr;

	if (pTitle == nullptr)
	{
		pTitle = new CTitle;

		pTitle->Init();
	}

	return pTitle;
}

//===========================================================
//����������
//===========================================================
HRESULT CTitle::Init(void)
{
	/*if (m_pStart == nullptr)
	{
		m_pStart = CObject2D::Create();
		m_pStart->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\any.png"));
		m_pStart->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.3f, SCREEN_HEIGHT * 0.7f, 0.0f));
		m_pStart->SetSize(200.0f, 50.0f);
		m_pStart->SetDraw(true);
	}*/

	// �}�b�v�ݒu
	SetMap();

	if (m_pBg == nullptr)
	{
		m_pBg = CObject2D::Create();
		m_pBg->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\title.png"));
		m_pBg->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));
		m_pBg->SetSize(SCREEN_WIDTH * 0.3f, SCREEN_HEIGHT * 0.3f);
		m_pBg->SetDraw(true);
	}

	//CManager::GetInstance()->GetSound()->Play(CSound::SOUND_LABEL_BGM_TITLE);
	
	return S_OK;
}

//===========================================================
//�I������
//===========================================================
void CTitle::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();

	if (m_pBg != nullptr)
	{
		m_pBg->Uninit();
		m_pBg = nullptr;
	}

	if (m_pStart != nullptr)
	{
		m_pStart->Uninit();
		m_pStart = nullptr;
	}

	// �v���C���[�̔j��
	if (m_pPlayer != nullptr)
	{
		m_pPlayer->Uninit();
		m_pPlayer = nullptr;
	}
	
	CObject::ReleaseAll();
}

//===========================================================
//�X�V����
//===========================================================
void CTitle::Update(void)
{
	// �L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	// �Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	// �t�F�[�h�̏����擾
	CFade *pFade = CManager::GetInstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_START, 0) == true)
	{//ENTER�L�[�����������V�[�����^�C�g���̂Ƃ�

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//�V�[�����Q�[���ɑJ��
			pFade->Set(CScene::MODE_TUTORIAL);
		}
	}

	CManager::GetInstance()->GetDebugProc()->Print("���݂̃V�[���F�^�C�g��");
}

//===========================================================
//�`�揈��
//===========================================================
void CTitle::Draw(void)
{
	
}