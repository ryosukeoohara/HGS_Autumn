//===========================================================
//
// �T�E���h���� [sound.h]
// Author : �匴�@�叫
//
//===========================================================
#ifndef _SOUND_H_
#define _SOUND_H_

//===========================================================
// �C���N���[�h�t�@�C��
//===========================================================
#include "main.h"

//===========================================================
// �T�E���h���̍\���̒�`
//===========================================================
struct SOUNDINFO
{
	const char *pFilename;	// �t�@�C����
	int nCntLoop;		    // ���[�v�J�E���g
} ;

//===========================================================
// �T�E���h�N���X��`
//===========================================================
class CSound
{
public:
	CSound();
	~CSound();

	// �T�E���h�ꗗ
	enum SOUND_LABEL
	{
		SOUND_LABEL_BGM_TITLE = 0,
		SOUND_LABEL_BGM_TUTORIAL,
		SOUND_LABEL_BGM_GAME,
		SOUND_LABEL_BGM_RESULT,
		SOUND_LABEL_SE_WARNING,
		SOUND_LABEL_SE_PANIC,
		SOUND_LABEL_SE_NORMAL,
		SOUND_LABEL_SE_HANMMER,
		SOUND_LABEL_SE_GOOD,
		SOUND_LABEL_SE_BAD,
		SOUND_LABEL_MAX
	} ;

	HRESULT Init(HWND hWnd);
	void Uninit(void);
	HRESULT Play(SOUND_LABEL label);
	void Stop(SOUND_LABEL label);
	void Stop(void);

	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
	HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);

private:
	// �T�E���h�̏��
	SOUNDINFO m_aSoundInfo[SOUND_LABEL_MAX] =
	{
		{ "data/SOUND/BGM/title.wav", -1 },
		{ "data/SOUND/BGM/tutorial.wav", -1 },
		{ "data/SOUND/BGM/game.wav", -1 },
		{ "data/SOUND/BGM/result.wav", -1 },
		{ "data/SOUND/SE/warning.wav", 0 },
		{ "data/SOUND/SE/panic.wav", 0 },
		{ "data/SOUND/SE/normal_hit.wav", 0 },
		{ "data/SOUND/SE/hanmmer.wav", 0 },
		{ "data/SOUND/SE/good.wav", 0 },
		{ "data/SOUND/SE/bad_hit.wav", 0 },
	}; 

	IXAudio2 *m_pXAudio2 = nullptr;								// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice *m_pMasteringVoice = nullptr;			// �}�X�^�[�{�C�X
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// �\�[�X�{�C�X
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// �I�[�f�B�I�f�[�^�T�C�Y
};

#endif