#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
Enemy::Enemy(const CVector2D& pos)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("ウイルス", CImage);
	m_pos = pos;
	//中心を設定
	m_img.SetCenter(16, 16);
	//半径
	m_rad = 16;
	//矩形を設定
	m_rect = CRect(-16, -16, 16, 16);

}

void Enemy::Update()
{

	//敵を下に動かす
	const int move_speed = 12;
	//カウントアップ
	m_cnt++;
	//60カウント(1秒)以上なら
	/*if (m_cnt >= 60)
	{
		
	}*/

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
		if (m_cnt >= 100)
		{
		//移動
		//m_pos.x += move_speed;
		m_pos.y += move_speed;
		//m_pos.x -= move_speed;
		//m_pos.y -= move_speed;
		//カウンターリセット
		m_cnt = 0;

			Base::Add(new Bullet(eType_Enemy_Bullet, m_pos, m_ang, 1));
			m_cnt = 0;
		}
	}

}

void Enemy::Collision(Base* b)
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

void Enemy::Draw() 
{
	m_img.SetPos(m_pos);
	m_img.SetSize(32, 32);
	m_img.Draw();


	



}