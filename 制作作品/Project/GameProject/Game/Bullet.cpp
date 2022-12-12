#include "Bullet.h"
#include "kabe.h"
#include"Effect.h"
#include "Map.h"
Bullet::Bullet(int type, const CVector2D& pos, float ang, float speed) : Base(type)
{
	if (type == eType_Player_Bullet)
		m_img = COPY_RESOURCE("Bullet4", CImage);
	else
		m_img = COPY_RESOURCE("Bullet3", CImage);

	m_pos = pos;
	m_img.SetCenter(15, 15);
	m_ang = ang;
	m_speed = speed;
	
}

void Bullet::Update() 
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;

}

void Bullet::Draw() 
{
	m_img.SetSize(30, 30);
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void Bullet::Collision(Base* b)
{
	switch (b->m_type) 
	{
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) 
		{
			int t = m->CollisionMap(m_pos);
			if (t != 0)
			{
			SetKill();
			//�G�t�F�N�g����
			//Base::Add(new Effect(m_pos));
			}
				

		}
		break;
	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b)) 
		{
			SetKill();
			b->SetKill();
			//�G�t�F�N�g����
			Base::Add(new Effect(b->m_pos));

		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_Bullet && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
			//�G�t�F�N�g����
			Base::Add(new Effect(b->m_pos));

		}
		break;
	
	



	}

}
