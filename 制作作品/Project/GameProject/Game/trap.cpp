#include "trap.h"
#include"Effect.h"
#include "Map.h"
trap::trap(int type, const CVector2D& pos, float ang, float speed) : Base(type)
{
	if (type == eType_Player_trap)
		m_img = COPY_RESOURCE("水色ボム", CImage);
	else
		m_img = COPY_RESOURCE("Bullet3", CImage);

	m_pos = pos;
	m_img.SetCenter(16, 16);
	m_ang = ang;
	m_speed = speed;
}

void trap::Update()
{
	m_vec = CVector2D(sin(m_ang), cos(m_ang)) * m_speed;
	m_pos += m_vec;

}
void trap::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetAng(m_ang);
	m_img.Draw();
}

void trap::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		if (Map* m = dynamic_cast<Map*>(b)) 
		{
			int t = m->CollisionMap(m_pos);
			if (t != 0)
				SetKill();
			//エフェクト生成
			Base::Add(new Effect(b->m_pos));

		}
		break;
	case eType_Player:
		if (m_type == eType_Enemy_trap && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
			//エフェクト生成
			Base::Add(new Effect(b->m_pos));

		}
		break;
	case eType_Enemy:
		if (m_type == eType_Player_trap && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
			//エフェクト生成
			Base::Add(new Effect(b->m_pos));

		}
		break;
	case eType_Boss:
		if (m_type == eType_Player_trap && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
			//エフェクト生成
			Base::Add(new Effect(b->m_pos));

		}
		break;





	}

}
