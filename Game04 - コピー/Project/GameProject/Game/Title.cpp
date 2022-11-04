#include "Title.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("Title", CImage); 
	
}

Title::~Title()
{
	//全てのオブジェクトを破棄
	//Base::KillAll();
	




	//タイトル破棄時にゲームシーンへ移行
	//Base::Add(new Game());
	Base::Add(new Title());


}

void Title::Update()
{
	//ボタン１でタイトル破棄
	if (PUSH(CInput::eButton1)) {
		m_kill = true;
	}

	//m_ang += 0.02f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

}