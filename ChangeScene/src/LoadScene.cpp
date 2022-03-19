#include"AllScene.hpp"

Load::Load(const InitData& init)
	:IScene(init)
{
	ClearPrint();

	getData().Time.start();

	// 背景の色を設定 | Set background color
	Scene::SetBackground(Palette::Black);
}

void Load::update() {
	if (getData().Time.sF() > LIMIT_TIME) {
		changeScene(State::Finish);
	}
	else {
		if (flag_loading) {
			if (400 <= install) {
				//changeScene(State::Title);
				changeScene(sceneRandom(2));
			}
			else {
				install += 1.5;
			}
		}
	}
	debug();
}

void Load::draw() const {
	if (flag_loading) {
		loading(install);
	}
}

void Load::debug() {

}
