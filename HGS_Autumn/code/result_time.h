//===========================================================
//
//�|���S�����o�����[time.h]
//Author �匴�叫
//
//===========================================================
#ifndef _RESULT_TIME_H_             //���̃}�N����`������ĂȂ�������
#define _RESULT_TIME_H_             //2�d�C���N���[�h�h�~�̃}�N����`������

#include "number.h"

// �O���錾
class CObject2D;

//�^�C���N���X
class CResultTime : public CNumber
{
public:
	CResultTime();  //�R���X�g���N�^
	CResultTime(D3DXVECTOR3 pos);  //�R���X�g���N�^(�I�[�o�[���[�h)
	~CResultTime();  //�f�X�g���N�^

	HRESULT Init(void);      //�|���S���̏���������    
	void Uninit(void);    //�|���S���̏I������
	void Update(void);    //�|���S���̍X�V����
	void Draw(void);      //�|���S���̕`�揈��

	static CResultTime* Create(void);  //����
	static HRESULT Load(void);  //
	static void UnLoad(void);
	static CResultTime* GetResultTime(void) { return m_ResultTime; };
	static void SetResultTime(int nResultTime) { m_nResultTime = nResultTime; };
	static int Gettime(void) { return m_nResultTime; };
	static void ResultTimeCounter(void);

private:
	static LPDIRECT3DTEXTURE9 m_pTexture;        //�e�N�X�`���ւ̃|�C���^
	D3DXVECTOR3 m_pos;  //�ʒu
	D3DXVECTOR3 m_move; //�ړ�
	static CResultTime* m_ResultTime;
	static CNumber* m_apNumber[2];
	static int m_nResultTimerCount;
	static int m_nResultTime;  //����
	int m_nIdxTexture;
};

#endif
