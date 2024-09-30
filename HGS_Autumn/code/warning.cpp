//===========================================================
//
// �x���摜�\������[warning.cpp]
// Author Ibuki Okusada
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "warning.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "number.h"
#include "sound.h"

// �萔��`
namespace
{
	const D3DXVECTOR3 POS = D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.3f, 0.0f);
	const float WIDTH = 150.0f;						// ��
	const float HEIGHT = 200.0f;					// �ݒu���W
	const char* FILENAME[CWarning::TYPE_MAX] = {	// �t�@�C����
		"data\\TEXTURE\\warning\\walk.png",
		"data\\TEXTURE\\warning\\rock.png",
		"data\\TEXTURE\\warning\\wind.png",
		"data\\TEXTURE\\warning\\rope.png",
	};
	const D3DXVECTOR2 ADDSIZE = D3DXVECTOR2(4.0f, 2.0f);
	const int TIMER = 300;
}

//================================================================
// �R���X�g���N�^
//================================================================
CWarning::CWarning()
{
	m_pObj = nullptr;
}

//================================================================
// �f�X�g���N�^
//================================================================
CWarning::~CWarning()
{

}

//================================================================
// ��������
//================================================================
CWarning* CWarning::Create(const int nType)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CWarning* pWarning = NULL;

	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	if (pWarning == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pWarning = new CWarning();
		
		// ��ސݒ�
		pWarning->m_nType = nType;

		//����������
		pWarning->Init();
	}

	return pWarning;
}

//================================================================
// ����������
//================================================================
HRESULT CWarning::Init(void)
{
	// 2D�|���S���̐���
	CTexture* p = CManager::GetInstance()->GetTexture();
	m_pObj = CObject2D::Create();
	m_pObj->SetPosition(POS);
	m_pObj->SetDraw();
	m_pObj->SetSize(0.0f, 0.0f);

	// ��ނ��Ƃ̃e�N�X�`���ݒ�
	m_pObj->SetIdxTex(p->Regist(FILENAME[m_nType]));
	m_nTimer = TIMER;
	CManager::GetInstance()->GetSound()->Play(CSound::SOUND_LABEL_SE_WARNING);

	return S_OK;
}

//================================================================
// �I������
//================================================================
void CWarning::Uninit(void)
{
	// �|���S���̏I��
	if (m_pObj != nullptr)
	{
		m_pObj->Uninit();
		m_pObj = nullptr;
	}

	Release();
}

//================================================================
// �X�V����
//================================================================
void CWarning::Update(void)
{
	m_nTimer--;

	// �|���S���̃T�C�Y�ύX
	if (m_nTimer >= TIMER * 0.9f)
	{
		float width = m_pObj->GetWidth() + ADDSIZE.x * 2;
		float height = m_pObj->GetHeight() + ADDSIZE.y * 2;
		m_pObj->SetSize(width, height);
	}

	if (m_nTimer <= TIMER * 0.2f)
	{
		float width = m_pObj->GetWidth() - ADDSIZE.x;
		float height = m_pObj->GetHeight() - ADDSIZE.y;
		m_pObj->SetSize(width, height);
	}

	// �^�C�}�[0�ŏ���
	if (m_nTimer <= 0) { Uninit(); }
}


//================================================================
// �`�揈��
//================================================================
void CWarning::Draw(void)
{
	
}
