//===========================================================
//
// サウンド処理 [sound.h]
// Author : 大原　怜将
//
//===========================================================
#ifndef _SOUND_H_
#define _SOUND_H_

//===========================================================
// インクルードファイル
//===========================================================
#include "main.h"

//===========================================================
// サウンド情報の構造体定義
//===========================================================
struct SOUNDINFO
{
	const char *pFilename;	// ファイル名
	int nCntLoop;		    // ループカウント
} ;

//===========================================================
// サウンドクラス定義
//===========================================================
class CSound
{
public:
	CSound();
	~CSound();

	// サウンド一覧
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
	// サウンドの情報
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

	IXAudio2 *m_pXAudio2 = nullptr;								// XAudio2オブジェクトへのインターフェイス
	IXAudio2MasteringVoice *m_pMasteringVoice = nullptr;			// マスターボイス
	IXAudio2SourceVoice *m_apSourceVoice[SOUND_LABEL_MAX] = {};	// ソースボイス
	BYTE *m_apDataAudio[SOUND_LABEL_MAX] = {};					// オーディオデータ
	DWORD m_aSizeAudio[SOUND_LABEL_MAX] = {};					// オーディオデータサイズ
};

#endif