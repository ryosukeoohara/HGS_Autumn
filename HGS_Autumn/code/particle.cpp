//===========================================================
//
// �p�[�e�B�N������[particl.cpp]
// Author �匴�叫
//
//===========================================================
#include "main.h"
#include "renderer.h"
#include "object.h"
#include "manager.h"
#include "particle.h"
#include <time.h>

//===========================================================
// �萔��`
//===========================================================
namespace
{
	const int BLOOD = 1;        // ���t�̃p�[�e�B�N��
	const int GROUND = 20;      // �y���̃p�[�e�B�N��
	const int CIRCLE = 314;     // �~�`�̃p�[�e�B�N��
	const float SPEED = 10.0f;  // �ړ���
}

//===========================================================
//�ÓI�����o�ϐ��錾
//===========================================================
LPDIRECT3DTEXTURE9 CParticle::m_pTexture = nullptr;

//===========================================================
// �R���X�g���N�^
//===========================================================
CParticle::CParticle()
{
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_fRadius = 0;
	m_nLife = 0;
}

//===========================================================
// �R���X�g���N�^
//===========================================================
CParticle::CParticle(D3DXVECTOR3 pos, TYPE type)
{
	m_pos = pos;
	m_fRadius = 0;
	m_nLife = 0;
	m_type = type;
}

//===========================================================
// �f�X�g���N�^
//===========================================================
CParticle::~CParticle()
{

}

//===========================================================
// ��������
//===========================================================
CParticle *CParticle::Create(D3DXVECTOR3 pos, TYPE type)
{
	//�I�u�W�F�N�g2D�̃|�C���^
	CParticle *pParticl = NULL;

	if (pParticl == NULL)
	{
		//�I�u�W�F�N�g2D�̐���
		pParticl = new CParticle(pos, type);

		//����������
		pParticl->Init();
	}
	
	return pParticl;
}

//===========================================================
// ����������
//===========================================================
HRESULT CParticle::Init(void)
{
	

	return S_OK;
}

//===========================================================
// �I������
//===========================================================
void CParticle::Uninit(void)
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
		m_pTexture = NULL;
	}
}

//===========================================================
// �X�V����
//===========================================================
void CParticle::Update(void)
{
	
}

//===========================================================
// �`�揈��
//===========================================================
void CParticle::Draw(void)
{
	
}

//===========================================================
// �`�揈��
//===========================================================
void CParticle::Move(void)
{
	//�����̎��ݒ�
	srand((unsigned int)time(0));

	for (int nCnt = 0; nCnt < 10; nCnt++)
	{
		float fMove, fRot;

		fMove = (float)(rand() % 50) / 100.0f * 8.0f;
		fRot = (float)(rand() % 629 - 314) / 100.0f;

		m_move.x = sinf(fRot) * fMove;
		m_move.y = cosf(fRot) * fMove;
		m_move.z = cosf(fRot) * fMove;

		//CEffect::Create(pos, { m_move.x, m_move.y, m_move.z }, { 0.8f, 1.0f, 1.0f, 1.0f }, m_fRadius, 30, CEffect::TYPEEFF_NONE);
	}
}