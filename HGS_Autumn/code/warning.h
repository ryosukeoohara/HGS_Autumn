//===========================================================
//
// �x���摜�\���w�b�_�[[warning.h]
// Author Ibuki Okusada
//
//===========================================================
#ifndef _WARNING_H_             //���̃}�N����`������ĂȂ�������
#define _WARNING_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "object.h"

//�}�N����`
#define SETTIME   (2)  //���Ԃ̌�
#define TIME      (90) //�Q�[���̐�������
#define INITTIME  (0)  //���ꂼ��̌��̏����l

// �O���錾
class CObject2D;

//�^�C���N���X
class CWarning : public CObject
{
public:

	// �x�����(�}�b�v���Ƃ�)
	enum TYPE
	{
		TYPE_WALK = 0,	// ���s
		TYPE_ROCK,		// ��
		TYPE_WIND,		// ��
		TYPE_ROPE,		// �j�n��
		TYPE_MAX
	};

	CWarning();  //�R���X�g���N�^
	~CWarning();  //�f�X�g���N�^

	HRESULT Init(void);      //�|���S���̏���������    
	void Uninit(void);    //�|���S���̏I������
	void Update(void);    //�|���S���̍X�V����
	void Draw(void);      //�|���S���̕`�揈��

	static CWarning* Create(const int nType);  //����

private:

	// �����o�ϐ�
	CObject2D* m_pObj;	// �|���S��
	int m_nType;		// ���
	int m_nTimer;
};

#endif