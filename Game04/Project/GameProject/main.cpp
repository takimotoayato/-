//�Q�[���W�@�\�̃C���N���[�h
#include <GLLibrary.h>
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
//���̃X�N���[���̑傫��
//#define SCREEN_WIDTH 1280
//#define SCREEN_HEIGHT 720

#include "Base/Base.h"
#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/Bullet.h"
#include "Game/Map.h"
#include "Game/Boss.h"
#include "Game/Title.h"
#include "Game/Game.h"
#include "Game/UI.h"
////////
//#include "Game/GameData.h"
//#include "Game/UI.h"
//--------------------------------------------
//�O���[�o���ϐ��̈�
//--------------------------------------------




void MainLoop(void) {
	//--------------------------------------------------------------
	//�Q�[�����̓����͂����ɏ���
	//�Q�[�����͂��̊֐�_��1�b�Ԃ�60��Ăяo���Ă���
	//--------------------------------------------------------------
	Base::CheckKillAll();
	Base::UpdateAll();
	Base::CollisionAll();
	Base::DrawAll();


}
void Init(void)
{

	CFPS::SetFPS(60);
	//�t���[�����䏉����
	CFPS::Init();
	//�{�^���̐ݒ�
	CInput::Init();
	CInput::SetButton(0, CInput::eButton1, 'Z');
	CInput::SetButton(0, CInput::eButton2, 'X');
	CInput::SetButton(0, CInput::eButton3, 'C');
	CInput::SetButton(0, CInput::eButton4, 'V');
	CInput::SetButton(0, CInput::eButton5, VK_SPACE);
	CInput::SetButton(0, CInput::eButton10, VK_RETURN);
	CInput::SetButton(0, CInput::eUp, 'W');
	CInput::SetButton(0, CInput::eDown, 'S');
	CInput::SetButton(0, CInput::eLeft, 'A');
	CInput::SetButton(0, CInput::eRight, 'D');
	CInput::SetButton(0, CInput::eMouseL, VK_LBUTTON);
	CInput::SetButton(0, CInput::eMouseR, VK_RBUTTON);
	CInput::SetButton(0, CInput::eMouseC, VK_MBUTTON);
	CInput::SetButton(0, CInput::eUp, VK_UP);
	CInput::SetButton(0, CInput::eDown, VK_DOWN);
	CInput::SetButton(0, CInput::eLeft, VK_LEFT);
	CInput::SetButton(0, CInput::eRight, VK_RIGHT);




	//	CInput::SetMouseInside(true);
	//	CInput::ShowCursor(false);
	CInput::Update();
	CInput::Update();



	SetCurrentDirectory("data");
	CSound::GetInstance();

	//-----------------------------------------------------
	//�������̖��߂�����
	//�Q�[���N�����Ɉ�x�����Ă΂��
	//-----------------------------------------------------
	// �摜�ǂݍ���
		ADD_RESOURCE("Player", CImage::CreateImage("Image/Player.png"));
		ADD_RESOURCE("Player2", CImage::CreateImage("Image/Player2.png"));
		ADD_RESOURCE("Enemy", CImage::CreateImage("Image/Enemy.png"));
		ADD_RESOURCE("Enemy2", CImage::CreateImage("Image/Enemy2.png"));
		ADD_RESOURCE("Enemy3", CImage::CreateImage("Image/Enemy3.png"));
		ADD_RESOURCE("Bullet", CImage::CreateImage("Image/Bullet.png"));
		ADD_RESOURCE("Bullet2", CImage::CreateImage("Image/Bullet2.png"));
		ADD_RESOURCE("Bullet3", CImage::CreateImage("Image/Bullet3.png"));
		ADD_RESOURCE("MapTip", CImage::CreateImage("Image/MapTip.png"));
		ADD_RESOURCE("Title", CImage::CreateImage("Image/Title.png"));


		ADD_RESOURCE("MapTipB", CImage::CreateImage("Image/MapTipB.png"));




	//�v���C���[�̐���
	//Base::Add(new Player(CVector2D(100,580)));
	Base::Add(new Player(CVector2D(930, 940)));
	//�G�̐���
	Base::Add(new Enemy(CVector2D(500,500)));
	Base::Add(new Enemy(CVector2D(32 * 17, 32 * 14)));
	Base::Add(new Enemy(CVector2D(32 * 37, 32 * 10)));

	//Base::Add(new Boss(CVector2D(600, 600)));
	//�}�b�v�̐���
	Base::Add(new Map());
//
	Base::Add(new UI());
	








}


void Release()
{
	CLoadThread::ClearInstance();
	CSound::ClearInstance();
	CResourceManager::ClearInstance();
}

static void ResizeCallback(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);

	//��ʉ𑜓x�ϓ�
	CCamera::GetCamera()->SetSize((float)w, (float)h);
	//��ʉ𑜓x�Œ�
	//CCamera::GetCamera()->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	CCamera::GetCamera()->Viewport(0, 0, w, h);
	CCamera::GetCurrent()->Perspective(DtoR(60.0), (float)w / (float)h, 1.0, 1000.0);

	glfwGetWindowPos(window, &GL::window_x, &GL::window_y);
	GL::UpdateWindowRect(GL::window_x, GL::window_y, w, h);
	CInput::UpdateClipCursor(true);

}
static void WheelCallback(GLFWwindow* _window, double _offsetx, double _offsety) {
	CInput::AddMouseWheel((int)_offsety);

}
static void PosCallback(GLFWwindow* _window, int x, int y) {
	GL::window_x = x;
	GL::window_y = y;
	GL::UpdateWindosRect(x, y, GL::window_width, GL::window_height);
	CInput::UpdateClipCursor(true);

}
static void FocusCallback(GLFWwindow* _window, int f) {
	CInput::UpdateClipCursor(f);
	GL::focus = f;
}

static void error_callback(int error, const char* description)
{
	printf("Error: %s\n", description);
}

//�t���X�N���[��?�E�C���h�E���[�h�̐؂�ւ�
//Alt+Enter�Ő؂�ւ���
void CheckFullScreen() {
	static int key_enter = 0;
	int key_enter_buf = key_enter;
	if (key_enter_buf ^ (key_enter = glfwGetKey(GL::window, GLFW_KEY_ENTER)) && key_enter && (glfwGetKey(GL::window, GLFW_KEY_LEFT_ALT) || glfwGetKey(GL::window, GLFW_KEY_RIGHT_ALT))) {
		GL::ChangeFullScreen(!GL::full_screen);
	}
}

int __main(int* argcp, char** argv) {
	// ���������[�N���o
	//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//OpenGL4.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	glfwSetErrorCallback(error_callback);
	if (!glfwInit()) return -1;
	//	glutInit(argcp, argv);

	GL::window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Simple", nullptr, nullptr);
	glfwGetWindowSize(GL::window, &GL::window_width, &GL::window_height);
	glfwGetWindowPos(GL::window, &GL::window_x, &GL::window_y);

	glfwSetFramebufferSizeCallback(GL::window, ResizeCallback);
	glfwSetScrollCallback(GL::window, WheelCallback);
	glfwSetWindowFocusCallback(GL::window, FocusCallback);
	glfwSetWindowPosCallback(GL::window, PosCallback);
	if (!GL::window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(GL::window);
	glfwSwapInterval(1);
	ResizeCallback(GL::window, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLenum err = glewInit();
	if (err == GLEW_OK) {
		printf("%s\n", glewGetString(GLEW_VERSION));
	}
	else {
		printf("%s\n", glewGetErrorString(err));
		getchar();
		return -1;
	}
	HDC glDc = wglGetCurrentDC();
	GL::hWnd = WindowFromDC(glDc);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);//�u�����h�̗L����
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	//�Œ�V�F�[�_�[�p
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_ALPHA_TEST);

	Init();
	while (!glfwWindowShouldClose(GL::window)) {
		CheckFullScreen();


		CInput::Update();
		//�e�o�b�t�@�[���N���A
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainLoop();


		glfwSwapBuffers(GL::window);


		CFPS::Wait();

		char title[32];
		sprintf_s(title, "math fps:%d dt:%.3f", CFPS::GetFPS(), CFPS::GetDeltaTime());
		glfwSetWindowTitle(GL::window, title);

		glfwPollEvents();
		if (glfwGetKey(GL::window, GLFW_KEY_ESCAPE)) {
			glfwSetWindowShouldClose(GL::window, GL_TRUE);
		}

	}

	glfwTerminate();




	Release();
	return 0;
}

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR argv, INT argc)
{
	return __main(&__argc, __argv);
}

int main(int argc, char** argv)
{
	return __main(&argc, argv);
}