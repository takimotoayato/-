#include "Title.h"
#include "Sousahou.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("���^�C�g�����", CImage); 
	
}

Title::~Title()
{
	
	//Base::Add(new Title());


}

void Title::Update()
{
	//�{�^��5�Ń^�C�g���j��
	if (PUSH(CInput::eButton5)) 
	{
		m_kill = true;
	////�S�ẴI�u�W�F�N�g��j��
	//Base::KillAll();
	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	Base::Add(new Game());
	}

	//�{�^��5�Ń^�C�g���j��
	if (PUSH(CInput::eButton2))
	{
		m_kill = true;
		////�S�ẴI�u�W�F�N�g��j��
		//Base::KillAll();
		//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
		Base::Add(new Sousahou());
	}





	//m_ang += 0.02f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//�����\��
	m_title_text.Draw(680, 820, 0, 0, 0, "�X�y�[�X�L�[�ŃQ�[���X�^�[�g");
	m_title_text.Draw(64, 920, 0, 0, 0, "     X�L�[�ő��������ʂ�");
	/*m_title_text.Draw(64, 720, 0, 0, 0, "     ������@");
	m_title_text.Draw(64, 820, 0, 0, 0, "�X�y�[�X�L�[�ōU��");
	m_title_text.Draw(64, 920, 0, 0, 0, "Z�{�^���Ńg���b�v�ݒu");*/

}