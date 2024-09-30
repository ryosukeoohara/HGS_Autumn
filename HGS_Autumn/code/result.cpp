//===========================================================
//
// ���U���g���[result.cpp]
// Author �匴�叫
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

// ���O���
namespace
{
	const char* FILENAME[CResult::STATE::STATE_MAX] =
	{
		"data\\TEXTURE\\result\\failed.png",
		"data\\TEXTURE\\result\\success.png",
	};
}

// �ÓI�����o�ϐ�
int CResult::m_nSuccess = CResult::STATE::STATE_FAILED;
int CResult::m_nTime = 0;

//===========================================================
// �R���X�g���N�^
//===========================================================
CResult::CResult()
{
	m_pNumber = nullptr;
	m_pMap = nullptr;
	m_pUserRank = nullptr;
	m_nCounter = 0;
}

//===========================================================
// �f�X�g���N�^
//===========================================================
CResult::~CResult()
{

}

//===========================================================
// ��������
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
// ����������
//===========================================================
HRESULT CResult::Init(void)
{
	// �������s��\��
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

	// �������Ԃ�\��
	{
		CObject2D* p = new CObject2D(7);
		p->Init();
		p->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\result\\time.png"));
		p->SetPosition(D3DXVECTOR3(SCREEN_WIDTH * 0.35f, SCREEN_HEIGHT * 0.75f, 0.0f));
		p->SetSize(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.1f);
		p->SetDraw(true);

		CResultTime::Create();
	}

	// �}�b�v�ݒu
	SetMap();

	return S_OK;
}

//===========================================================
// �I������
//===========================================================
void CResult::Uninit(void)
{
	CManager::GetInstance()->GetSound()->Stop();

	CObject::ReleaseAll();

	m_nSuccess = STATE_FAILED;
	m_nTime = 0;
}

//===========================================================
// �X�V����
//===========================================================
void CResult::Update(void)
{
	//�L�[�{�[�h���擾
	CInputKeyboard *InputKeyboard = CManager::GetInstance()->GetKeyBoard();

	//�}�E�X���擾
	CInputMouse *pInputMouse = CManager::GetInstance()->GetInputMouse();

	//�Q�[���p�b�h���擾
	CInputJoyPad *pInputJoyPad = CManager::GetInstance()->GetInputJoyPad();

	//�t�F�[�h�̏����擾
	CFade *pFade = CManager::GetInstance()->GetFade();

	if (InputKeyboard->GetTrigger(DIK_RETURN) == true || pInputJoyPad->GetTrigger(CInputJoyPad::BUTTON_START, 0) == true)
	{//ENTER�L�[�����������V�[�����^�C�g���̂Ƃ�

		if (pFade->Get() != pFade->FADE_OUT)
		{
			//�V�[�����Q�[���ɑJ��
			pFade->Set(CScene::MODE_TITLE);
		}
	}
}

//===========================================================
// �`�揈��
//===========================================================
void CResult::Draw(void)
{
	
}