//===========================================================
//
//�|���S�����o�����[game.h]
//Author �匴�叫
//
//===========================================================
#ifndef _GAME_H_
#define _GAME_H_

//===========================================================
// �C���N���[�h�t�@�C��
//===========================================================
#include "manager.h"

//===========================================================
// �O���錾
//===========================================================
class CPause;
class CObject2D;
class CPlayer;

//===========================================================
// �Q�[���N���X��`
//===========================================================
class CGame : public CScene
{
public:
	CGame();
	CGame(CScene::MODE mode);
	~CGame();

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);

	static CGame *Create(void);

	// �ݒ�n
	static void SetbPause(bool bpause) { m_bPause = bpause; }

	// �擾�n
	static bool GetbPause(void) { return m_bPause; }

private:

	static CPause *m_pPause;
	static bool m_bPause;
	CObject2D* m_pBg;
	CPlayer* m_pPlayer;

};

#endif // !_GAME_H_