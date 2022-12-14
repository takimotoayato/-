#include "Title.h"
#include "Sousahou.h"
#include "Game.h"
#include "GameEX.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("仮タイトル画面", CImage); 
	
}

Title::~Title()
{
	
	


}

void Title::Update()
{
	
/**/
	//ボタン2でタイトル破棄
	if (PUSH(CInput::eButton2))
	{
		m_kill = true;
		////全てのオブジェクトを破棄
		//Base::KillAll();
		//タイトル破棄時に操作方法移行
		Base::Add(new Sousahou());
	}

	//ボタン5でタイトル破棄
	if (PUSH(CInput::eButton5)) 
	{
		m_kill = true;
	////全てのオブジェクトを破棄
	//Base::KillAll();
	//タイトル破棄時にゲームシーンへ移行
	Base::Add(new Game());
	}

	//ボタン4でタイトル破棄
	if (PUSH(CInput::eButton4))
	{
		m_kill = true;
		////全てのオブジェクトを破棄
		//Base::KillAll();
		//タイトル破棄時にゲームシーンEXへ移行
		Base::Add(new GameEX());
	}




	//m_ang += 0.02f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//文字表示
	m_title_text.Draw(580, 820, 0, 0, 0, "スペースキーでゲームスタート");
	m_title_text.Draw(580, 870, 0, 0, 0, "Vキーで無限耐久モード");
	m_title_text.Draw(580, 920, 0, 0, 0, "Xキーで操作説明画面へ");
	

}