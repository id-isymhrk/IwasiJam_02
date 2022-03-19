﻿#include"AllScene.hpp"

Password::Password(const InitData& init)
	:IScene(init), font15(15), font25(25), box_text(Arg::center(400, 500), 400, 30)
{

}

void Password::update() {
	if (KeyEnter.down()) {
		//シーン移動
		changeScene(sceneRandom(1));
	}
	else {
		//パスワード入力
		TextInput::UpdateText(text_input);
	}

	hidePassword();

	debug();
}

void Password::draw() const {
	box_text.draw(Color(255, 255, 255));
	font15(U"password:").drawAt(p.movedBy(-220, -30), Palette::White);
	font15(U"[delete]:show / delete").draw(p.movedBy(50, 20), Palette::White);
	font15(U"[Enter]:finish").draw(p.movedBy(50, 40), Palette::White);

	//パスワードを 隠す/隠さない 処理
	if (not flag_hide) {
		font25(text_input).draw(205, 482, Color(0, 0, 0));
	}
	else {
		for (size_t i = 0; i < text_input.size(); i++) {
			font25(U"●").draw(205 + 25 * i, 482, Color(0, 0, 0));
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
