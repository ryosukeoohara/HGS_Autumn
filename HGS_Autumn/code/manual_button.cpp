//===========================================================
//
// �x���{�^���\������[manual_button.cpp]
// Author Ibuki Okusada
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "manual_button.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "number.h"
#include "billboard.h"
#include "player.h"
#include "InputJoyPad.h"

// �萔��`
namespace
{
	// �ʒu�͂��ꂢ������
	const float SPACE = 75.0f;	// �v���C���[����̘b������
	const float UP = 50.0f;	// �v���C���[����̍���


	const float DEF_WIDTH = 15.0f;					// ��
	const float DEF_HEIGHT = 15.0f;					// �ݒu���W
	const float BIG_WIDTH = 30.0f;
	const float BIG_HEIGHT = 30.0f;
	const char* FILENAME[CManualButton::TYPE_MAX] = {	// �t�@�C����
		"data\\TEXTURE\\button\\button_lb.png",
		"data\\TEXTURE\\button\\button_rb.png",
	};

}


// ���E�p
namespace LEFTRIGHT
{
	const float ASPACE[CManualButton::TYPE_MAX] = {
		SPACE,
		-SPACE
	};
}

//================================================================
// �R���X�g���N�^
//================================================================
CManualButton::CManualButton()
{
	for (int i = 0; i < TYPE_MAX; i++)
	{
		m_apObj[i] = nullptr;
	}

	m_nSelect = TYPE_MAX;
}

//================================================================
// �f�X�g���N�^
//================================================================
CManualButton::~CManualButton()
{

}

//================================================================
// ��������
//================================================================
CManualButton* CManualButton::Create(void)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CManualButton* pManualButton = NULL;

	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	if (pManualButton == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pManualButton = new CManualButton();

		//����������
		pManualButton->Init();
	}

	return pManualButton;
}

//================================================================
// ����������
//================================================================
HRESULT CManualButton::Init(void)
{
	CTexture* p = CManager::GetInstance()->GetTexture();

	// 2D�|���S���̐���
	for (int i = 0; i < TYPE_MAX; i++)
	{
		D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_apObj[i] = CBillBoard::Create();
		m_apObj[i]->SetPosition(pos);
		m_apObj[i]->SetDraw();
		m_apObj[i]->SetSize(DEF_WIDTH, DEF_HEIGHT);
		// ��ނ��Ƃ̃e�N�X�`���ݒ�
		m_apObj[i]->SetIdxTex(p->Regist(FILENAME[i]));
	}

	return S_OK;
}

//================================================================
// �I������
//================================================================
void CManualButton::Uninit(void)
{
	// �|���S���̏I��
	for (int i = 0; i < TYPE_MAX; i++)
	{
		if (m_apObj[i] != nullptr)
		{
			m_apObj[i]->Uninit();
			m_apObj[i] = nullptr;
		}
	}

	Release();
}

//================================================================
// �X�V����
//================================================================
void CManualButton::Update(void)
{
	CPlayer*p = CPlayer::GetInstance();
	
	for (int i = 0; i < TYPE_MAX; i++)
	{
		if (m_apObj[i] != nullptr)
		{
			// �ʒu�̐ݒ�
			D3DXVECTOR3 pos = p->GetPosition();
			pos.x = LEFTRIGHT::ASPACE[i];
			pos.y = UP;
			m_apObj[i]->SetPosition(pos);

			// �T�C�Y�̐ݒ�
			float width = DEF_WIDTH;
			float height = DEF_HEIGHT;
			if (m_nSelect == i)
			{
				width = BIG_WIDTH;
				height = BIG_HEIGHT;
			}

			width = m_apObj[i]->GetWidth() + (width - m_apObj[i]->GetWidth()) * 0.1f;
			height = m_apObj[i]->GetHeight() + (height - m_apObj[i]->GetHeight()) * 0.1f;

			m_apObj[i]->SetSize(width, height);
		}
	}
}


//================================================================
// �`�揈��
//================================================================
void CManualButton::Draw(void)
{

}
