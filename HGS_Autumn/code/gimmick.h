//===========================================================
//
// �M�~�b�N����[gimmcik.h]
// Author : �匴�@�叫
//
//===========================================================
#ifndef _GIMMICK_H_             //���̃}�N����`������ĂȂ�������
#define _GIMMICK_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

//===========================================================
// �M�~�b�N�N���X��`
//===========================================================
class CGimmick
{
public:
	CGimmick(int nPriority = 3);  // �R���X�g���N�^
	~CGimmick();                  // �f�X�g���N�^

	HRESULT Init(void);            // ����������    
	void Uninit(void);             // �I������
	void Update(void);             // �X�V����
	void Draw(void);               // �`�揈��

	CGimmick* Create(void);        // ��������

private:
	
};

#endif