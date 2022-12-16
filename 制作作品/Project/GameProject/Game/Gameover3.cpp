#include "Gameover3.h"
#include "Game.h"
#include "Game2.h"
#include "Title.h"

Gameover3::Gameover3() :Base(eType_Gameclear), m_Gameover_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("ゲームオーバー", CImage);
	m_img2 = COPY_RESOURCE("ウイルス", CImage);
	m_img3 = COPY_RESOURCE("ウイルス2", CImage);
	m_img4 = COPY_RESOURCE("ウイルス3", CImage);
}

Gameover3::~Gameover3()
{

}

void Gameover3::Update()
{
	//回転
	m_ang += 0.02f;

	//ボタン5で画面を破棄
	if (PUSH(CInput::eButton5))
	{
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーン
		Base::Add(new Title());
	}
}

void Gameover3::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	m_Gameover_text.Draw(64, 950, 0, 0, 0, "スペースキーでタイトルに戻る");
	//ウイルス出力
	m_img2.Draw();
	//大きさ設定
	m_img2.SetSize(100, 100);
	//座標設定
	m_img2.SetPos(1000, 300);
	//回転
	m_img2.SetAng(m_ang);
	//中心位置設定
	m_img2.SetCenter(50, 50);


	//ウイルス出力
	m_img2.Draw();
	//大きさ設定
	m_img2.SetSize(100, 100);
	//座標設定
	m_img2.SetPos(200, 800);
	//回転
	m_img2.SetAng(m_ang);
	//中心位置設定
	m_img2.SetCenter(50, 50);

}