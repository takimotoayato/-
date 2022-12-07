#include "Title.h"
#include "Sousahou.h"
#include "Game.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("仮タイトル画面", CImage); 
	
}

Title::~Title()
{
	
	//Base::Add(new Title());


}

void Title::Update()
{
	//ボタン5でタイトル破棄
	if (PUSH(CInput::eButton5)) 
	{
		m_kill = true;
	////全てのオブジェクトを破棄
	//Base::KillAll();
	//タイトル破棄時にゲームシーンへ移行
	Base::Add(new Game());
	}

	//ボタン5でタイトル破棄
	if (PUSH(CInput::eButton2))
	{
		m_kill = true;
		////全てのオブジェクトを破棄
		//Base::KillAll();
		//タイトル破棄時にゲームシーンへ移行
		Base::Add(new Sousahou());
	}





	//m_ang += 0.02f;
	

}

void Title::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//文字表示
	m_title_text.Draw(680, 820, 0, 0, 0, "スペースキーでゲームスタート");
	m_title_text.Draw(64, 920, 0, 0, 0, "     Xキーで操作説明画面へ");
	/*m_title_text.Draw(64, 720, 0, 0, 0, "     操作方法");
	m_title_text.Draw(64, 820, 0, 0, 0, "スペースキーで攻撃");
	m_title_text.Draw(64, 920, 0, 0, 0, "Zボタンでトラップ設置");*/

}