//===========================================================
//
// �x���{�^���\���w�b�_�[[manual_button.h]
// Author Ibuki Okusada
//
//===========================================================
#ifndef _MANUAL_BUTTON_H_             //���̃}�N����`������ĂȂ�������
#define _MANUAL_BUTTON_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "object.h"

// �O���錾
class CBillBoard;

//�^�C���N���X
class CManualButton : public CObject
{
public:

	// �x�����(�}�b�v���Ƃ�)
	enum TYPE
	{
		TYPE_LEFT = 0,	// L�{�^��
		TYPE_RIGHT,		// R�{�^��
		TYPE_MAX
	};

	CManualButton();  //�R���X�g���N�^
	~CManualButton();  //�f�X�g���N�^

	HRESULT Init(void);      //�|���S���̏���������    
	void Uninit(void);    //�|���S���̏I������
	void Update(void);    //�|���S���̍X�V����
	void Draw(void);      //�|���S���̕`�揈��
	void Select(const int nSelect) { m_nSelect = nSelect; }	// ���͕����ݒ�
	static CManualButton* Create();

private:

	// �����o�ϐ�
	CBillBoard* m_apObj[TYPE_MAX];	// �|���S��
	int m_nSelect;
};

#endif