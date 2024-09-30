//===========================================================
//
// �M�~�b�N����[gimmcik.h]
// Author : �匴�@�叫
//
//===========================================================
#ifndef _GIMMICK_H_             //���̃}�N����`������ĂȂ�������
#define _GIMMICK_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

//===========================================================
// �C���N���[�h�t�@�C��
//===========================================================
#include "billboard.h"
//===========================================================
// �M�~�b�N�N���X��`
//===========================================================
class CGimmick : public CBillBoard
{
public:
	enum TYPE
	{
		TYPEWALK = 0,		// ���s
		TYPEROPE,			// �j�n��
		TYPEMAX
	};

	CGimmick(int nPriority = 3);  // �R���X�g���N�^
	~CGimmick();                  // �f�X�g���N�^

	HRESULT Init(void);            // ����������    
	void Uninit(void);             // �I������
	void Update(void);             // �X�V����
	void Draw(void);               // �`�揈��

	static CGimmick* Create(float fDestDistance, TYPE type);        // ��������

private:
	TYPE m_GimmickType;			// ���
	static float m_fDestPos;		// �ڕW�n�_

	bool m_bStart;		// �M�~�b�N�J�n������
	
};

#endif