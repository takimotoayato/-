#include "Title.h"
#include "Sousahou.h"
#include "Game.h"
#include "GameEX.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("���^�C�g�����", CImage); 
	
}

Title::~Title()
{
	
	


}

void Title::Update()
{
	
/**/
	//�{�^��2�Ń^�C�g���j��
	if (PUSH(CInput::eButton2))
	{
		m_kill = true;
		////�S�ẴI�u�W�F�N�g��j��
		//Base::KillAll();
		//�^�C�g���j�����ɑ�����@�ڍs
		Base::Add(new Sousahou());
	}

	//�{�^��5�Ń^�C�g���j��
	if (PUSH(CInput::eButton5)) 
	{
		m_kill = true;
	////�S�ẴI�u�W�F�N�g��j��
	//Base::KillAll();
	//�^�C�g���j�����ɃQ�[���V�[���ֈڍs
	Base::Add(new Game());
	}

	//�{�^��4�Ń^�C�g���j��
	if (PUSH(CInput::eButton4))
	{
		m_kill = true;
		////�S�ẴI�u�W�F�N�g��j��
		//Base::KillAll();
		//�^�C�g���j�����ɃQ�[���V�[��EX�ֈڍs
		Base::Add(new GameEX());
	}




	//m_ang += 0.02f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//�����\��
	m_title_text.Draw(580, 820, 0, 0, 0, "�X�y�[�X�L�[�ŃQ�[���X�^�[�g");
	m_title_text.Draw(580, 870, 0, 0, 0, "V�L�[�Ŗ����ϋv���[�h");
	m_title_text.Draw(580, 920, 0, 0, 0, "X�L�[�ő��������ʂ�");
	

}