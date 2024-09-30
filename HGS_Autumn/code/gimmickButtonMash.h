//===========================================================
//
// �M�~�b�N����[gimmcik.h]
// Author : �匴�@�叫
//
//===========================================================
#ifndef _GIMMICKBUTTONMASH_H_             //���̃}�N����`������ĂȂ�������
#define _GIMMICKBUTTONMASH_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "gimmick.h"

class CGimmick;
class CObjectX;

//===========================================================
// �M�~�b�N�N���X��`
//===========================================================
class CGimmickButtonMash : public CGimmick
{
public:
	CGimmickButtonMash(D3DXVECTOR3 pos, int nPriority = 3);  // �R���X�g���N�^
	~CGimmickButtonMash();                  // �f�X�g���N�^

	HRESULT Init(void);            // ����������    
	void Uninit(void);             // �I������
	void Update(void);             // �X�V����
	void Draw(void);               // �`�揈��

	static CGimmickButtonMash* Create(D3DXVECTOR3 pos);        // ��������

private:

	CObjectX* m_pObjectX = nullptr;
	D3DXVECTOR3 m_pos = {};
	bool m_bClear = false;

};

#endif
