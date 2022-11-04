#include "GameData.h"
#include "Player.h"
#include "Enemy.h"
#include "UI.h"
UI::UI() :Base(eType_UI) {
	m_img.Load("Image/UI.png");
}
void UI::Draw()
{
	int score = GameData::s_score;
	for (int i = 0; i < 8; i++, score /= 10) {
		int s = score % 10;
		m_img.SetRect(16 * s, 16, 16 * s + 16, 32);
		m_img.SetSize(16, 16);
		m_img.SetPos(200 - 16 * i, 0);
		m_img.Draw();
	}
	Base* enemy = Base::FindObject(eType_Enemy);

	//敵がいなければ
	//if (enemy == nullptr) {
	//	//ゲームクリアの表示
	//	m_img.SetRect(0, 64, 0 + 160, 64 + 32);
	//	m_img.SetSize(160, 32);
	//	m_img.SetPos(100, 200);
	//	m_img.Draw();
	//}
	Base* player = Base::FindObject(eType_Player);

	//敵がいなければ
	if (player == nullptr) {
		//ゲームクリアの表示
		m_img.SetRect(0, 96, 160, 128);
		m_img.SetSize(160, 32);
		m_img.SetPos(200, 200);
		m_img.Draw();
	}

	/*
	Base* goal = Base::FindObject(eType_Goal);

	//敵がいなければ
	if (goal == nullptr) {
		//ゲームクリアの表示
		m_img.SetRect(0, 64, 0 + 160, 64 + 32);
		m_img.SetSize(160, 32);
		m_img.SetPos(100, 200);
		m_img.Draw();
	}
	*/


}