#include "Sousahou.h"
#include "Title.h"
#include "Game.h"
Sousahou::Sousahou() :Base(eType_Scene),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{

	m_img = COPY_RESOURCE("haikei1", CImage);

}

Sousahou::~Sousahou()
{
	////全てのオブジェクトを破棄
	//Base::KillAll();
	//タイトル破棄時にゲームシーンへ移行
	//Base::Add(new Game());
	Base::Add(new Title());


}

void Sousahou::Update()
{
	//ボタン１でタイトル破棄
	if (PUSH(CInput::eButton3)) {
		m_kill = true;
	}

	//m_ang += 0.02f;


}

void Sousahou::Draw()
{
	m_img.Draw();
	m_img.SetSize(1920, 1080);

	//文字表示
	m_title_text.Draw(680, 120, 0, 0, 0, "     操作方法");
	m_title_text.Draw(64, 320, 0, 0, 0, "スペースキーで攻撃");
	m_title_text.Draw(64, 520, 0, 0, 0, "Zボタンでトラップ設置");
	m_title_text.Draw(64, 920, 0, 0, 0, "Cボタンでタイトル画面へ戻る");

}