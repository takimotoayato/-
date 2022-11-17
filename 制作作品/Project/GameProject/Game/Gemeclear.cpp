#include "Gameclear.h"
#include "Game.h"
#include "Title.h"

Gameclear::Gameclear() :Base(eType_Gameclear), m_Gameclear_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) 
{
	m_img = COPY_RESOURCE("ゲームクリア", CImage);
	
}

Gameclear::~Gameclear() {

}

void Gameclear::Update() {
	//ボタン１でクリア画面を破棄
	if (PUSH(CInput::eButton1)) {
		//全てのオブジェクトを破棄
		Base::KillAll();
		//タイトルシーン
		Base::Add(new Title());
	}
}

void Gameclear::Draw()
{
	m_img.Draw();
	

}