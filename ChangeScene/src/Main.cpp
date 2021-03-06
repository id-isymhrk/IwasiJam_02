#include"AllScene.hpp"

void Main()
{
	Window::SetTitle(U"Change Scenes!");

	Window::Resize(800, 600);
	Scene::SetResizeMode(ResizeMode::Keep);

	const Audio audio{ Audio::Stream, U"shatou.mp3", Loop::Yes };
	audio.play();

	App manager;
	manager
		.add<Title>(State::Title)
		.add<Password>(State::ID01_Password)
		.add<Load>(State::ID02_Load)
		.add<Default>(State::ID03_Default)
		.add<Inside>(State::ID04_Inside)
		.add<Chain>(State::ID05_Chain)
		.add<OddEven>(State::ID06_OddEven)
		.add<Finish>(State::Finish);

	while (System::Update())
	{
		if (not manager.update()) {
			break;
		}
	}
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク | Quick Links =
//
// Siv3D リファレンス
// https://zenn.dev/reputeless/books/siv3d-documentation
//
// Siv3D Reference
// https://zenn.dev/reputeless/books/siv3d-documentation-en
//
// Siv3D コミュニティへの参加
// Slack や Twitter, BBS で気軽に質問や情報交換ができます。
// https://zenn.dev/reputeless/books/siv3d-documentation/viewer/community
//
// Siv3D User Community
// https://zenn.dev/reputeless/books/siv3d-documentation-en/viewer/community
//
// 新機能の提案やバグの報告 | Feedback
// https://github.com/Siv3D/OpenSiv3D/issues
//
