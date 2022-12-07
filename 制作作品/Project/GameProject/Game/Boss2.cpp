#include "Boss2.h"
#include "Bullet.h"
Boss2::Boss2(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("ウイルス3", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(50, 50);
	//半径
	m_rad = 50;

}

void Boss2::Update()
{
	//カウントアップ
	m_cnt++;
	//プレイヤーを取得
	Base* b = Base::FindObject(eType_Player);
	//プレイヤーが居れば
	if (b)
	{
		//ターゲットへのベクトル
		CVector2D vec = b->m_pos - m_pos;
		m_ang = atan2(vec.x, vec.y);
		if (m_cnt >= 180)
		{
			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 20));
			m_cnt = 0;
		}
	}

}

void Boss2::Collision(Base* b)
{
	switch (b->m_type)
	{

	case eType_Player:
		if (m_type == eType_Enemy_Bullet && Base::CollisionCircle(this, b))
		{
			SetKill();
			b->SetKill();
		}
		break;


	}

}

void Boss2::Draw()
{
	m_img.SetPos(m_pos);
	m_img.SetSize(100, 100);
	m_img.Draw();
}