#include "Gameclear.h"
#include "Game.h"
#include "Game2.h"
#include "Title.h"

Gameclear::Gameclear() :Base(eType_Gameclear), m_Gameclear_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) 
{
	m_img = COPY_RESOURCE("ゲームクリア2", CImage);
	
}

Gameclear::~Gameclear() 
{

}

void Gameclear::Update() 
{
	//ボタン5でクリア画面を破棄
	if (PUSH(CInput::eButton5))
	{
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーン
		Base::Add(new Title());
	}
}

void Gameclear::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);
	m_Gameclear_text.Draw(64, 950, 0, 0, 0, "スペースキーでタイトルに戻る");
}