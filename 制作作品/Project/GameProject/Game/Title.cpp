#include "Title.h"
#include "Sousahou.h"
#include "Game.h"
#include "GameEX.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("���^�C�g�����", CImage); 
	m_img2 = COPY_RESOURCE("space", CImage);
	//m_img3 = COPY_RESOURCE("V", CImage);
	m_img3 = COPY_RESOURCE("V�L�[", CImage);
	//m_img4 = COPY_RESOURCE("X", CImage);
	m_img4 = COPY_RESOURCE("X�L�[", CImage);

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
	//�X�y�[�X�L�[�o��
	m_img2.Draw();
	m_img2.SetSize(400, 200);
	m_img2.SetCenter(200, 100);
	m_img2.SetPos(745, 795);
	//V�L�[�o��
	m_img3.Draw();
	m_img3.SetSize(80, 80);
	m_img3.SetCenter(40, 40);
	m_img3.SetPos(580, 865);
	//X�L�[�o��
	m_img4.Draw();
	m_img4.SetSize(80, 80);
	m_img4.SetCenter(40, 40);
	m_img4.SetPos(580, 930);
	//�����\��
	m_title_text.Draw(580, 820, 0, 0, 0, "            �ŃQ�[���X�^�[�g");
	m_title_text.Draw(580, 880, 0, 0, 0, " �L�[�Ŗ����ϋv���[�h");
	m_title_text.Draw(580, 940, 0, 0, 0, " �L�[�ő��������ʂ�");
	

}