//===========================================================
//
// �M�~�b�N����[gimmcik.h]
// Author : �匴�@�叫
//
//===========================================================
#ifndef _GIMMICKBALANCE_H_             //���̃}�N����`������ĂȂ�������
#define _GIMMICKBALANCE_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "gimmick.h"

class CGimmick;

//===========================================================
// �M�~�b�N�N���X��`
//===========================================================
class CGimmickBalance : public CGimmick
{
public:
	CGimmickBalance(int nPriority = 3);  // �R���X�g���N�^
	~CGimmickBalance();                  // �f�X�g���N�^

	HRESULT Init(void);            // ����������    
	void Uninit(void);             // �I������
	void Update(void);             // �X�V����
	void Draw(void);               // �`�揈��

	CGimmickBalance* Create(void);        // ��������

private:

};

#endif