//===========================================================
//
// �M�~�b�N����[gimmcik.h]
// Author : �匴�@�叫
//
//===========================================================
#ifndef _GIMMICKTIMING_H_             //���̃}�N����`������ĂȂ�������
#define _GIMMICKTIMING_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "gimmick.h"

class CGimmick;

//===========================================================
// �M�~�b�N�N���X��`
//===========================================================
class CGimmickTiming : public CGimmick
{
public:
	CGimmickTiming(int nPriority = 3);  // �R���X�g���N�^
	~CGimmickTiming();                  // �f�X�g���N�^

	HRESULT Init(void);            // ����������    
	void Uninit(void);             // �I������
	void Update(void);             // �X�V����
	void Draw(void);               // �`�揈��

	CGimmickTiming* Create(void);        // ��������

private:

};

#endif
