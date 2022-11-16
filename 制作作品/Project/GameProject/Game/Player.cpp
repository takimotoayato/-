#include "Player.h"
#include "Bullet.h"
#include "trap.h"
#include "Map.h"
Player::Player(const CVector2D& pos)
	:Base(eType_Player)
{
	m_img = COPY_RESOURCE("�퓬�@", CImage);
	m_pos = pos;
	//���S��ݒ�
	//m_img.SetCenter(16, 16);
	 m_img.SetCenter(25, 25);
	//��`��ݒ�
	//m_rect = CRect(-16, -16, 16, 16);
	//m_rect = CRect(-32, -32, 32, 32);
	m_rect = CRect(-25, -25, 25, 25);
	//���a
	//m_rad = 16;
	 m_rad = 25;
	m_ang;
}
void Player::Update()
{
	m_pos_old = m_pos;
	const float speed = 4;
	//���Ɉړ�
	if (HOLD(CInput::eLeft))
		m_pos.x -= speed;
	//�E�Ɉړ�
	if (HOLD(CInput::eRight))
		m_pos.x += speed;
	//��Ɉړ�
	if (HOLD(CInput::eUp))
		m_pos.y -= speed;
	//���Ɉړ�
	if (HOLD(CInput::eDown))
		m_pos.y += speed;

	//�}�E�X�ւ̃x�N�g��
	//CVector2D vec = CInput::GetMousePoint() - m_pos;
	//��]�l���t�Z
	//m_ang = atan2(vec.x, vec.y);
	//�X�y�[�X�L�[�Œe�𔭎�
	if (PUSH(CInput::eButton5))
	{
		Base::Add(new Bullet(eType_Player_Bullet, m_pos, m_ang, 6));
	}
	
	if (PUSH(CInput::eButton1))
	{
		Base::Add(new trap(eType_Player_trap, m_pos, m_ang, 0));
	}


}
void Player::Collision(Base* b)
{
	switch (b->m_type) 
	{
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) 
		{
			int t = m->CollisionMap(CVector2D(m_pos.x, m_pos_old.y)),m_rect;

			if (t != 0)
				m_pos.x = m_pos_old.x;
			t = m->CollisionMap(CVector2D(m_pos_old.x, m_pos.y)), m_rect;
			if (t != 0)
				m_pos.y = m_pos_old.y;

		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
		}
		break;
	}


}
void Player::Draw() 
{
	m_img.SetPos(m_pos);
	//m_img.SetSize(32,32);
	m_img.SetSize(50, 50);
	m_img.SetAng(m_ang);
	m_img.Draw();
}
