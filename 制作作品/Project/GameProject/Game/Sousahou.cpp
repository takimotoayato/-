#include "Sousahou.h"
#include "Title.h"
#include "Game.h"
Sousahou::Sousahou() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{

	m_img = COPY_RESOURCE("haikei1", CImage);
	m_img2 = COPY_RESOURCE("�㉺���E���L�[", CImage);
	m_img3 = COPY_RESOURCE("space", CImage);
	//m_img4 = COPY_RESOURCE("Z", CImage);
	m_img4 = COPY_RESOURCE("Z�L�[", CImage);
	//m_img5 = COPY_RESOURCE("C", CImage);
	m_img5 = COPY_RESOURCE("C�L�[", CImage);
	
	

}

Sousahou::~Sousahou()
{
	
	


}

void Sousahou::Update()
{
	//�{�^��3�Ń^�C�g���j��
	if (PUSH(CInput::eButton3)) 
	{
		m_kill = true;
	Base::Add(new Title());
	}



}

void Sousahou::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//���L�[�o��
	m_img2.Draw();
	m_img2.SetSize(200, 200);
	m_img2.SetCenter(100, 100);
	m_img2.SetPos(800, 300);
	//���L�[�o��
	m_img3.Draw();
	m_img3.SetSize(400, 200);
	m_img3.SetCenter(200, 100);
	m_img3.SetPos(1000, 500);
	//Z�L�[�o��
	m_img4.Draw();
	m_img4.SetSize(100, 100);
	m_img4.SetCenter(50, 50);
	m_img4.SetPos(800, 700);
	//Z�L�[�o��
	m_img5.Draw();
	m_img5.SetSize(100, 100);
	m_img5.SetCenter(50, 50);
	m_img5.SetPos(990, 900);
	//�����\��
	m_title_text.Draw(680, 120, 0, 0, 0, "     ������@");
	m_title_text.Draw(64, 320, 0, 0, 0, "���������L�[�ňړ�");
	m_title_text.Draw(64, 520, 0, 0, 0, "�X�y�[�X�L�[�Œe�̔���");
	m_title_text.Draw(64, 720, 0, 0, 0, "Z�L�[�Ńg���b�v�ݒu");
	m_title_text.Draw(64, 920, 0, 0, 0, "C�L�[�Ń^�C�g����ʂ֖߂�");

}