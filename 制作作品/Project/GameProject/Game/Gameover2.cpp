#include "Gameover2.h"
#include "Game.h"
#include "Game2.h"
#include "Title.h"

Gameover2::Gameover2() :Base(eType_Gameclear), m_Gameover_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("�Q�[���I�[�o�[", CImage);
	m_img2 = COPY_RESOURCE("�E�C���X", CImage);
	m_img3 = COPY_RESOURCE("�E�C���X2", CImage);
	m_img4 = COPY_RESOURCE("�E�C���X2", CImage);
}

Gameover2::~Gameover2()
{

}

void Gameover2::Update()
{
	//��]
	m_ang += 0.02f;

	//�{�^��5�ŉ�ʂ�j��
	if (PUSH(CInput::eButton5))
	{
		//�S�ẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[��
		Base::Add(new Title());
	}
}

void Gameover2::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	m_Gameover_text.Draw(64, 950, 0, 0, 0, "�X�y�[�X�L�[�Ń^�C�g���ɖ߂�");
	
	//�E�C���X�o��
	m_img4.Draw();
	//�傫���ݒ�
	m_img4.SetSize(300, 300);
	//���W�ݒ�   //��   �c
	m_img4.SetPos(150, 150);
	//��]
	//m_img4.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img4.SetCenter(150, 150);

	//�E�C���X�o��
	m_img4.Draw();
	//�傫���ݒ�
	m_img4.SetSize(300, 300);
	//���W�ݒ�   //��   �c
	m_img4.SetPos(1800, 150);
	//��]
	//m_img4.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img4.SetCenter(150, 150);

	//�E�C���X�o��
	m_img3.Draw();
	//�傫���ݒ�
	m_img3.SetSize(300, 300);
	//���W�ݒ�   //��   �c
	m_img3.SetPos(1800, 900);
	//��]
	m_img3.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img3.SetCenter(150, 150);

	//�E�C���X�o��
	m_img3.Draw();
	//�傫���ݒ�
	m_img3.SetSize(100, 100);
	//���W�ݒ�   //��   �c
	m_img3.SetPos(1000, 300);
	//��]
	m_img3.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img3.SetCenter(50, 50);

	//�E�C���X�o��
	m_img3.Draw();
	//�傫���ݒ�
	m_img3.SetSize(100, 100);
	//���W�ݒ�   //��   �c
	m_img3.SetPos(200, 800);
	//��]
	m_img3.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img3.SetCenter(50, 50);

	//�E�C���X�o��
	m_img3.Draw();
	//�傫���ݒ�
	m_img3.SetSize(300, 300);
	//���W�ݒ�   //��   �c
	m_img3.SetPos(100, 400);
	//��]
	m_img3.SetAng(m_ang);
	//���S�ʒu�ݒ�
	m_img3.SetCenter(150, 150);

}