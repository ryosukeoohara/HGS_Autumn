//===========================================================
//
// ���U���g�^�C��[time.cpp]
// Author Ibuki Okusada
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "manager.h"
#include "result_time.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "number.h"
#include "time.h"

// �萔��`
namespace
{
	const D3DXVECTOR3 FISHPOS = D3DXVECTOR3(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.75f, 0.0f);
	const float WIDTH = 40.0f;
	const float HEIGHT = 80.0f;
}

//================================================================
//�ÓI�����o�ϐ��錾
//================================================================
LPDIRECT3DTEXTURE9 CResultTime::m_pTexture = NULL;
CNumber* CResultTime::m_apNumber[2] = {};
int CResultTime::m_nResultTime = 0;
int CResultTime::m_nResultTimerCount = 0;

//================================================================
//�R���X�g���N�^
//================================================================
CResultTime::CResultTime()
{
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
}

//================================================================
//�R���X�g���N�^(�I�[�o�[���[�h)
//================================================================
CResultTime::CResultTime(D3DXVECTOR3 pos)
{
	m_pos = pos;  //�ʒu
	SetPosition(pos);
	m_move = { 0.0f, 0.0f, 0.0f };  //�ړ���
}

//================================================================
//�f�X�g���N�^
//================================================================
CResultTime::~CResultTime()
{

}

//================================================================
//��������
//================================================================
CResultTime* CResultTime::Create(void)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CResultTime* pResultTime = NULL;

	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	if (pResultTime == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pResultTime = new CResultTime();

		//����������
		pResultTime->Init();
	}

	return pResultTime;
}

//================================================================
// ����������
//================================================================
HRESULT CResultTime::Init(void)
{
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		if (m_apNumber[nCount] == NULL)
		{
			m_apNumber[nCount] = CNumber::Create({ FISHPOS.x + 50.0f * nCount, FISHPOS.y, 0.0f });

			//�e�N�X�`�����o�C���h
			//m_apNumber[nCount]->BindTexture(pTexture->GetAddress(m_nIdxTexture));

			m_apNumber[nCount]->SetNumberType(TYPENUMBER_TIME);

			//����������
			m_apNumber[nCount]->Init();

			m_apNumber[nCount]->m_Number = 0;
			D3DXVECTOR3 pos = D3DXVECTOR3(FISHPOS.x + 80.0f * nCount, FISHPOS.y, 0.0f);
			m_apNumber[nCount]->SetVtxCounter(pos, WIDTH, HEIGHT);
		}
	}

	m_apNumber[0]->m_Number = m_nResultTime % 100 / 10;
	m_apNumber[1]->m_Number = m_nResultTime % 10 / 1;

	ResultTimeCounter();

	return S_OK;
}

//================================================================
// �I������
//================================================================
void CResultTime::Uninit(void)
{
	for (int nCount = 0; nCount < 2; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//�I������
			m_apNumber[nCount]->Uninit();

			m_apNumber[nCount] = NULL;
		}
	}

	Release();

	m_nResultTime = 0;
}

//================================================================
// �X�V����
//================================================================
void CResultTime::Update(void)
{
	
}

//================================================================
// �`�揈��
//================================================================
void CResultTime::Draw(void)
{
	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		if (m_apNumber[nCount] != NULL)
		{
			//�`�揈��
			m_apNumber[nCount]->Draw();
		}
	}
}

//================================================================
//�^�C��
//================================================================
void CResultTime::ResultTimeCounter(void)
{
	//�t�F�[�h�̏����擾
	CFade* pFade = CManager::GetInstance()->GetFade();

	m_nResultTimerCount++;

	if (m_nResultTimerCount % 60 == 0)
	{
		m_nResultTime--;

		m_apNumber[0]->m_Number = m_nResultTime % 100 / 10;
		m_apNumber[1]->m_Number = m_nResultTime % 10 / 1;
	}

	for (int nCount = 0; nCount < SETTIME; nCount++)
	{
		m_apNumber[nCount]->SetNumber(m_apNumber[nCount]->m_Number);
	}
}