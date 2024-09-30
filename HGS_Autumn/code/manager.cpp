//===========================================================
//
// �}�l�[�W������[manager.cpp]
// Author �匴�叫
//
//===========================================================
#include "renderer.h"
#include "object.h"
#include "object2D.h"
#include "manager.h"
#include "input.h"
#include "sound.h"
#include "input.h"
#include "time.h"
#include "debugproc.h"
#include "camera.h"
#include "texture.h"
#include "game.h"
#include "fade.h"
#include "pause.h"
#include "title.h"
#include "light.h"
#include "result.h"
#include "tutorial.h"
#include "utility.h"
#include "InputMouse.h"
#include "InputJoyPad.h"
#include "objectX.h"
#include"field.h"

//===========================================================
//�ÓI�����o�ϐ�
//===========================================================
CManager *CManager::m_pManager = nullptr;
CGame  *CScene::m_Game = nullptr;
CTutorial *CScene::m_Tutorial = nullptr;
CTitle *CScene::m_Title = nullptr;
CResult *CScene::m_Result = nullptr;
CScene::MODE CScene::m_mode = CScene::MODE_TITLE;

//===========================================================
// ����
//===========================================================
CManager * CManager::GetInstance()
{
	if (m_pManager == nullptr)
	{
		return m_pManager = new CManager;
	}
	else
	{
		return m_pManager;
	}
}

//================================================================
// �j��
//================================================================
HRESULT CManager::Release(void)
{
	if (m_pManager != nullptr)
	{
		m_pManager->Uninit();

		delete m_pManager;

		m_pManager = nullptr;
	}

	return S_OK;
}

//================================================================
// �R���X�g���N�^
//================================================================
CManager::CManager()
{
	m_ResetCounter = 0;
	m_nDefeat = 0;
	m_bPause = false;
	m_pUtility = nullptr;
}

//================================================================
// �f�X�g���N�^
//================================================================
CManager::~CManager()
{

}

//================================================================
// ����������
//================================================================
HRESULT CManager::Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	if (m_Renderer == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�����_���[�̐���
		m_Renderer = new CRenderer;

		//����������
		m_Renderer->Init(hWnd, TRUE);
	}

	if (m_InputKeyboard == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�L�[�{�[�h�̐���
		m_InputKeyboard = new CInputKeyboard;

		//����������
		m_InputKeyboard->Init(hInstance, hWnd);
	}

	if (m_InputMouse == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�}�E�X����
		m_InputMouse = new CInputMouse;

		//����������
		m_InputMouse->Init(hInstance, hWnd);
	}

	if (m_InputJoyPad == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�Q�[���p�b�h�̐���
		m_InputJoyPad = new CInputJoyPad;

		//����������
		m_InputJoyPad->Init();
	}

	if (m_Sound == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�T�E���h�̐���
		m_Sound = new CSound;

		//����������
		m_Sound->Init(hWnd);
	}

	if (m_DebugProc == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�f�o�b�O�v���b�N�̐���
		m_DebugProc = new CDebugProc;

		//����������
		m_DebugProc->Init();
	}

	if (m_Light == nullptr)
	{//�g�p����Ă��Ȃ�������

	 //���C�g�𐶐�
		m_Light = new CLight;

		//����������
		m_Light->Init();
	}

	if (m_Camera == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�J�����𐶐�
		m_Camera = new CCamera;

		//����������
		m_Camera->Init();
	}

	if (m_Light == nullptr)
	{//�g�p����Ă��Ȃ�������

	 //���C�g�𐶐�
		m_Light = new CLight;

		//����������
		m_Light->Init();
	}

	if (m_Texture == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�e�N�X�`���𐶐�
		m_Texture = new CTexture;

		//����������
		m_Texture->Load();
	}

	if (m_pScene == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�V�[���̐���
		m_pScene = CScene::Create(CScene::MODE_TITLE);

		//����������
		m_pScene->Init();
	}

	if (m_Fade == nullptr)
	{//�g�p����Ă��Ȃ�������

		//�t�F�[�h�𐶐�
		m_Fade = new CFade;

		//����������
		m_Fade->Init();
	}

	return S_OK;
}

//================================================================
// �I������
//================================================================
void CManager::Uninit(void)
{
	//�T�E���h���~�߂�
	m_Sound->Stop();

	//�V�[���̔j��
	if (m_pScene != nullptr)
	{
		//�V�[���̏I������
		m_pScene->Uninit();

		//���������J��
		delete m_pScene;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_pScene = nullptr;
	}

	//�����_���[�̔j��
	if (m_Renderer != nullptr)
	{
		//�����_���[�̏I������
		m_Renderer->Uninit();

		//���������J��
		delete m_Renderer;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Renderer = nullptr;
	}

	//�L�[�{�[�h�̔j��
	if (m_InputKeyboard != nullptr)
	{
		//�L�[�{�[�h�̏I������
		m_InputKeyboard->Uninit();

		//���������J��
		delete m_InputKeyboard;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_InputKeyboard = nullptr;
	}

	//�}�E�X�̔j��
	if (m_InputMouse != nullptr)
	{
		//�}�E�X�̏I������
		m_InputMouse->Uninit();

		//���������J��
		delete m_InputMouse;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_InputMouse = nullptr;
	}

	//�Q�[���p�b�h�̔j��
	if (m_InputJoyPad != nullptr)
	{
		//�Q�[���p�b�h�̏I������
		m_InputJoyPad->Uninit();

		//���������J��
		delete m_InputJoyPad;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_InputJoyPad = nullptr;
	}

	//�T�E���h�̔j��
	if (m_Sound != nullptr)
	{
		//�T�E���h�̏I������
		m_Sound->Uninit();
	
		//���������J��
		delete m_Sound;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Sound = nullptr;
	}

	//�f�o�b�O�v���b�N�̔j��
	if (m_DebugProc != nullptr)
	{
		//�f�o�b�O�v���b�N�̏I������
		m_DebugProc->Uninit();

		//���������J��
		delete m_DebugProc;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_DebugProc = nullptr;
	}

	//�J�����̔j��
	if (m_Camera != nullptr)
	{
		//�f�o�b�O�v���b�N�̏I������
		m_Camera->Uninit();

		//���������J��
		delete m_Camera;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Camera = nullptr;
	}

	//���C�g�̔j��
	if (m_Light != nullptr)
	{
		//�f�o�b�O�v���b�N�̏I������
		m_Light->Uninit();

		//���������J��
		delete m_Light;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Light = nullptr;
	}

	//�e�N�X�`���̔j��
	if (m_Texture != nullptr)
	{
		//�e�N�X�`���̏I������
		m_Texture->UnLoad();

		//���������J��
		delete m_Texture;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Texture = nullptr;
	}

	//�t�F�[�h�̔j��
	if (m_Fade != nullptr)
	{
		//�t�F�[�h�̏I������
		m_Fade->Uninit();

		//���������J��
		delete m_Fade;

		//�g�p���Ă��Ȃ���Ԃɂ���
		m_Fade = nullptr;
	}
}

//================================================================
// �X�V����
//================================================================
void CManager::Update(void)
{
	// �����_���[�̍X�V����
	if (m_Renderer != nullptr)
		m_Renderer->Update();

	// �L�[�{�[�h�̍X�V����
	if (m_InputKeyboard != nullptr)
		m_InputKeyboard->Update();

	// �}�E�X�̍X�V����
	if (m_InputMouse != nullptr)
		m_InputMouse->Update();

	// �Q�[���p�b�h�̍X�V����
	if (m_InputJoyPad != nullptr)
		m_InputJoyPad->Update();

	// �J�����̍X�V
	if (m_Camera != nullptr)
		m_Camera->Update();

	// �V�[���̍X�V
	if (m_pScene != nullptr)
		m_pScene->Update();
	
	if ((m_InputKeyboard->GetTrigger(DIK_RETURN) == true || m_InputJoyPad->GetTrigger(CInputJoyPad::BUTTON_A, 0) == true) && m_pScene->GetMode() == CScene::MODE_RESULT)
	{// ENTER�L�[�����������V�[�����Q�[���̂Ƃ�

		// �V�[�����^�C�g���ɑJ��
		if (m_Fade->Get() != m_Fade->FADE_OUT)
			m_Fade->Set(CScene::MODE_TITLE);

	}

	// �g�p���Ă���e�N�X�`���̍��v����
	int nTexAll = m_Texture->GetNumTexture();

	m_DebugProc->Print("\n<<�e�N�X�`���̑��� : %d>>", nTexAll);
	m_DebugProc->Print("\n<<ENTER�Ŏ��̃V�[���ɑJ��>>");
}

//================================================================
//�`�揈��
//================================================================
void CManager::Draw(void)
{
	//�����_���[�̕`�揈��
	m_Renderer->Draw();

	if (m_pScene != nullptr)
		m_pScene->Draw();

}

//================================================================
// �R���X�g���N�^
//================================================================
CScene::CScene()
{
	
}

//================================================================
// �R���X�g���N�^
//================================================================
CScene::CScene(MODE mode)
{
	m_mode = mode;
}

//================================================================
// �f�X�g���N�^
//================================================================
CScene::~CScene()
{

}

//================================================================
// ����
//================================================================
CScene *CScene::Create(MODE mode)
{
	CScene *pScene = nullptr;

	if (pScene == nullptr)
	{
		pScene = new CScene(mode);

		pScene->Init();
	}

	return pScene;
}

//================================================================
// ����������
//================================================================
HRESULT CScene::Init(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title == nullptr)
		{
			m_Title = new CTitle;

			m_Title->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FixedCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial == nullptr)
		{
			m_Tutorial = new CTutorial;

			m_Tutorial->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FollowPlayerCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;

	case MODE_GAME:

		if (m_Game == nullptr)
		{
			m_Game = new CGame;

			m_Game->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FollowPlayerCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;

	case MODE_RESULT:

		if (m_Result == nullptr)
		{
			m_Result = new CResult;

			m_Result->Init();

			CManager::GetInstance()->GetCamera()->ChangeState(new FixedCamera);
			CManager::GetInstance()->GetCamera()->Reset();
		}

		break;
	}

	return S_OK;
}

//================================================================
// �I������
//================================================================
void CScene::Uninit(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != nullptr)
		{
			m_Title->Uninit();

			delete m_Title;

			m_Title = nullptr;
		}

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial != nullptr)
		{
			m_Tutorial->Uninit();

			delete m_Tutorial;

			m_Tutorial = nullptr;
		}

		break;

	case MODE_GAME:

		if (m_Game != nullptr)
		{
			m_Game->Uninit();

			delete m_Game;

			m_Game = nullptr;
		}

		break;

	case MODE_RESULT:

		if (m_Result != nullptr)
		{
			m_Result->Uninit();

			delete m_Result;

			m_Result = nullptr;
		}

		break;
	}
}

//================================================================
// �X�V����
//================================================================
void CScene::Update(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != nullptr)
			m_Title->Update();

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial != nullptr)
			m_Tutorial->Update();

		break;

	case MODE_GAME:

		if (m_Game != nullptr)
			m_Game->Update();

		break;

	case MODE_RESULT:

		if (m_Result != nullptr)
			m_Result->Update();

		break;
	}
}

//================================================================
// �`��
//================================================================
void CScene::Draw(void)
{
	switch (m_mode)
	{
	case MODE_TITLE:

		if (m_Title != nullptr)
			m_Title->Draw();

		break;

	case MODE_TUTORIAL:

		if (m_Tutorial != nullptr)
			m_Tutorial->Draw();

		break;

	case MODE_GAME:

		if (m_Game != nullptr)
			m_Game->Draw();

		break;

	case MODE_RESULT:

		if (m_Result != nullptr)
			m_Result->Draw();

		break;
	}
}

//================================================================
// �����_���[�̎擾
//================================================================
CRenderer *CManager::GetRenderer(void)
{
	return m_Renderer;
}

//================================================================
// �L�[�{�[�h�̎擾
//================================================================
CInputKeyboard *CManager::GetKeyBoard(void)
{
	return m_InputKeyboard;
}

//================================================================
// �}�E�X�擾
//================================================================
CInputMouse *CManager::GetInputMouse(void)
{
	return m_InputMouse;
}

//================================================================
// �Q�[���p�b�h�擾
//================================================================
CInputJoyPad *CManager::GetInputJoyPad(void)
{
	return m_InputJoyPad;
}

//================================================================
// �T�E���h�̎擾
//================================================================
CSound *CManager::GetSound(void)
{
	return m_Sound;
}

//================================================================
// �v���C���[�̎擾
//================================================================
CPlayer *CManager::GetPlayer(void)
{
	return m_Player;
}

//================================================================
// �f�o�b�O�v���b�N�̎擾
//================================================================
CDebugProc *CManager::GetDebugProc(void)
{
	return m_DebugProc;
}

//================================================================
// �J�����̎擾
//================================================================
CCamera *CManager::GetCamera(void)
{
	return m_Camera;
}

//================================================================
// ���C�g�̎擾
//================================================================
CLight *CManager::GetLight(void)
{
	return m_Light;
}

//================================================================
// �e�N�X�`���̎擾
//================================================================
CTexture *CManager::GetTexture(void)
{
	return m_Texture;
}

//================================================================
// ���f���̎擾
//================================================================
CModel *CManager::GetModel(void)
{
	return m_Model;
}

//================================================================
// �I�u�W�F�N�g3D�̎擾
//================================================================
CObject3D *CManager::GetObject3D(void)
{
	return m_Object3D;
}

//================================================================
// �G�̎擾
//================================================================
CEnemy *CManager::GetEnemy(void)
{
	return m_Enemy;
}
//================================================================
// �����蔻��̎擾
//================================================================
CCollision *CManager::GetCollsion(void)
{
	return m_Collision;
}

//================================================================
// �G�f�B�b�g�̎擾
//================================================================
CEdit *CManager::GetEdit(void)
{
	return m_Edit;
}

//================================================================
// �}�b�v�̎擾
//================================================================
CMap *CManager::GetMap(void)
{
	return m_Map;
}

//================================================================
// �V�[���̎擾
//================================================================
CScene *CManager::GetScene(void)
{
	return m_pScene;
}

//================================================================
// �t�F�[�h�̎擾
//================================================================
CFade *CManager::GetFade(void)
{
	return m_Fade;
}

//================================================================
// �|�[�Y�̎擾
//================================================================
CPause *CManager::GetPause(void)
{
	return m_Pause;
}

//================================================================
// �֗��֐��̎擾
//================================================================
CUtility * CManager::GetUtility(void)
{
	return m_pUtility;
}

//================================================================
// �G�t�F�N�V�A�̎擾
//================================================================
CMyEffekseer* CManager::GetMyEffekseer(void)
{
	return m_pMyEffekseer;
}

//================================================================
// ���[�h�ݒ�
//================================================================
void CManager::SetMode(CScene::MODE mode)
{
	if (m_pScene != nullptr)
	{
		m_pScene->Uninit();

		delete m_pScene;

		m_pScene = nullptr;
	}

	if (m_pScene == nullptr)
	{
		m_pScene = new CScene(mode);

		m_pScene->Init();
	}
}

//================================================================
// �}�b�v�p�I�u�W�F�N�g�t�@�C����
//================================================================
namespace MAPFILENAME
{
	// �؂̃��f��
	const char* MAP_TREE = "data\\MODEL\\Field\\tree0.x";

	// ��̃��f��
	const char* MAP_ROCK = "data\\MODEL\\Field\\rock.x";

	// ��̌��Ѓ��f��
	const char* MAP_ROCK_PIECE = "data\\MODEL\\Field\\rock_piece.x";

	// ���[�v�̃��f��
	const char* MAP_ROPE = "data\\MODEL\\Field\\rope.x";

	// ���̃��f��
	const char* MAP_GRASS = "data\\MODEL\\Field\\grass.x";

	// ��̃��f��
	const char* MAP_CASTLE = "data\\MODEL\\Field\\castle.x";

	// ��̃h�A�̃t���[�����f��
	const char* MAP_CASTLE_FRAME = "data\\MODEL\\Field\\castle_door_frame.x";

	// ��̃h�A�E���f��
	const char* MAP_CASTLE_DOOR_R = "data\\MODEL\\Field\\castle_door_r.x";

	// ��̃h�A�����f��
	const char* MAP_CASTLE_DOOR_L = "data\\MODEL\\Field\\castle_door_l.x";

	const char* MAP_SKY = "data\\MODEL\\Field\\sky.x";
}

//================================================================
// �}�b�v�ݒ�
//================================================================
void CScene::SetMap(void)
{
	// �����ɔz�u�������Ă�����
	MAPFILENAME::MAP_TREE;
	MAPFILENAME::MAP_ROCK;
	MAPFILENAME::MAP_ROCK_PIECE;
	MAPFILENAME::MAP_ROPE;
	MAPFILENAME::MAP_GRASS;
	MAPFILENAME::MAP_CASTLE;
	MAPFILENAME::MAP_CASTLE_FRAME;
	MAPFILENAME::MAP_CASTLE_DOOR_R;
	MAPFILENAME::MAP_CASTLE_DOOR_L;

	CField* pRoad = new CField;

	if (pRoad != nullptr)
	{
		pRoad->Init();
		pRoad->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\field_soil.png"));
		pRoad->SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
		pRoad->SetSize(400.0f, 50000.0f);
		pRoad->SetDraw(true);
	}

	CField* pGrassR = new CField;

	if (pGrassR != nullptr)
	{
		pGrassR->Init();
		pGrassR->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\field_grass.jpg"));
		pGrassR->SetPosition(D3DXVECTOR3(600.0f, 0.0f, 0.0f));
		pGrassR->SetSize(800.0f, 50000.0f);
		pGrassR->SetDraw(true);
	}

	CField* pGrassL = new CField;

	if (pGrassL != nullptr)
	{
		pGrassL->Init();
		pGrassL->SetIdxTex(CManager::GetInstance()->GetTexture()->Regist("data\\TEXTURE\\field_grass.jpg"));
		pGrassL->SetPosition(D3DXVECTOR3(-600.0f, 0.0f, 0.0f));
		pGrassL->SetSize(800.0f, 50000.0f);
		pGrassL->SetDraw(true);
	}

	for (int i = 0; i <130; i++)
	{
		CObjectX::Create(MAPFILENAME::MAP_TREE, D3DXVECTOR3(1000.0f, -100.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_TREE, D3DXVECTOR3(-1200.0f, -100.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_GRASS, D3DXVECTOR3(400.0f, 0.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_GRASS, D3DXVECTOR3(-400.0f, 0.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_ROCK_PIECE, D3DXVECTOR3(500.0f, 0.0f, -2500.0f - (500 * i)));
		CObjectX::Create(MAPFILENAME::MAP_ROCK_PIECE, D3DXVECTOR3(-500.0f, 0.0f, -2500.0f - (500 * i)));
	}

	CObjectX::Create(MAPFILENAME::MAP_CASTLE, D3DXVECTOR3(0.0f, 0.0f, -71000));
	CObjectX::Create(MAPFILENAME::MAP_CASTLE_FRAME, D3DXVECTOR3(0.0f, 0.0f, -70000.0f));
	CObjectX::Create(MAPFILENAME::MAP_CASTLE_DOOR_R, D3DXVECTOR3(55.0f, 0.0f, -70000.0f));
	CObjectX::Create(MAPFILENAME::MAP_CASTLE_DOOR_L, D3DXVECTOR3(-60.0f, 0.0f, -70000.0f));
	CObjectX::Create(MAPFILENAME::MAP_SKY, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
}

//================================================================
// ���[�h�̎擾
//================================================================
CScene::MODE CScene::GetMode(void)
{
	return m_mode;
}