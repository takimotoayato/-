#include "Title.h"
#include "Sousahou.h"
#include "Game.h"
#include "GameEX.h"
Title::Title() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
	
	m_img = COPY_RESOURCE("仮タイトル画面", CImage); 
	m_img2 = COPY_RESOURCE("space", CImage);
	//m_img3 = COPY_RESOURCE("V", CImage);
	m_img3 = COPY_RESOURCE("Vキー", CImage);
	//m_img4 = COPY_RESOURCE("X", CImage);
	m_img4 = COPY_RESOURCE("Xキー", CImage);

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
	//スペースキー出力
	m_img2.Draw();
	m_img2.SetSize(400, 200);
	m_img2.SetCenter(200, 100);
	m_img2.SetPos(745, 795);
	//Vキー出力
	m_img3.Draw();
	m_img3.SetSize(80, 80);
	m_img3.SetCenter(40, 40);
	m_img3.SetPos(580, 865);
	//Xキー出力
	m_img4.Draw();
	m_img4.SetSize(80, 80);
	m_img4.SetCenter(40, 40);
	m_img4.SetPos(580, 930);
	//文字表示
	m_title_text.Draw(580, 820, 0, 0, 0, "            でゲームスタート");
	m_title_text.Draw(580, 880, 0, 0, 0, " キーで無限耐久モード");
	m_title_text.Draw(580, 940, 0, 0, 0, " キーで操作説明画面へ");
	

}