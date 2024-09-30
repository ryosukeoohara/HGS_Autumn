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
		TYPEMAX
	};

	CGimmick(int nPriority = 3);  // �R���X�g���N�^
	~CGimmick();                  // �f�X�g���N�^

	HRESULT Init(void);            // ����������    
	void Uninit(void);             // �I������
	void Update(void);             // �X�V����
	void Draw(void);               // �`�揈��

	static CGimmick* Create(TYPE type);        // ��������

private:
	TYPE m_GimmickType;			// ���
	
};

#endif