#include "Gameover.h"
#include "Game.h"
#include "Game2.h"
#include "Title.h"

Gameover::Gameover() :Base(eType_Gameclear), m_Gameover_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	m_img = COPY_RESOURCE("ゲームオーバー", CImage);

}

Gameover::~Gameover()
{

}

void Gameover::Update()
{
	//ボタン5で画面を破棄
	if (PUSH(CInput::eButton5)) 
	{
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーン
		Base::Add(new Title());
	}
}

void Gameover::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	m_Gameover_text.Draw(64, 950, 0, 0, 0, "スペースキーでタイトルに戻る");
}