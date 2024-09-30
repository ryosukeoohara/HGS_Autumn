//===========================================================
//
// �j�n�菈��[gimmcik.h]
// Author : �匴�@�叫
//
//===========================================================
#ifndef _GIMMICKROPE_H_             //���̃}�N����`������ĂȂ�������
#define _GIMMICKROPE_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "gimmick.h"

class CGimmick;
class CPlayer;
class CObject3D;

//===========================================================
// �M�~�b�N�N���X��`
//===========================================================
class CGimmickRope : public CGimmick
{
public:

	CGimmickRope(int nPriority = 3);  // �R���X�g���N�^
	~CGimmickRope();                  // �f�X�g���N�^

	HRESULT Init(void);            // ����������    
	void Uninit(void);             // �I������
	void Update(void);             // �X�V����
	void Draw(void);               // �`�揈��

	static CGimmickRope* Create(D3DXVECTOR3 pos);        // ��������

private:
	CObject3D* m_pObject3D;
	float m_fMove;		// �ړ���

};

#endif
