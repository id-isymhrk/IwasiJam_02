#include"AllScene.hpp"

Password::Password(const InitData& init)
	:IScene(init), font_guide(15), font_input(30),font_hide(25), box_text(Arg::center(400, 500), 400, 30)
{
	ClearPrint();

	getData().Time.start();

	// 背景の色を設定 | Set background color
	Scene::SetBackground(Palette::Black);
}

void Password::update() {
	static int32 miss_count = 0;
	if (getData().Time.sF() > LIMIT_TIME) {
		changeScene(State::Finish);
	}
	else {
		if (KeyEnter.down()) {
			if (text_input.size() > 4) {
				//シーン移動
				changeScene(sceneRandom(1));
				//changeScene(State::ID03_Default);
			}
			else {
				if (text_input) {
					text_input.clear();
				}
				Print << U"You missed password (total:{})"_fmt(++miss_count);
			}
		}
		else {
			//パスワード入力
			TextInput::UpdateText(text_input);
		}

		hidePassword();
	}

	debug();
}

void Password::draw() const {
	box_text.draw(Palette::White);
	font_guide(U"password:").drawAt(p.movedBy(-220, -30), Palette::White);
	font_guide(U"[delete]:show / hide").draw(p.movedBy(50, 20), Palette::White);
	font_guide(U"[Enter] : finish").draw(p.movedBy(50, 40), Palette::White);

	//パスワードを 隠す/隠さない 処理
	if (not flag_hide) {
		font_input(text_input).draw(205, box_text.pos.y-10, Color(0, 0, 0));
	}
	else {
		for (size_t i = 0; i < text_input.size(); i++) {
			font_hide(U"●").draw(205 + 25 * i, 482, Color(0, 0, 0));
		}
	}
}

void Password::debug() {

}

void Password::hidePassword() {
	if (KeyDelete.down()) {
		if (flag_hide) {
			flag_hide = false;
		}
		else {
			flag_hide = true;
		}
	}
}
