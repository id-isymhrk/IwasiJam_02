#include"AllScene.hpp"

Finish::Finish(const InitData& init)
	:IScene(init),
	font_title{ FontMethod::MSDF, 40, Typeface::Bold },font_score{ FontMethod::MSDF, 40, Typeface::Bold }
{
	ClearPrint();

	getData().Time.reset();

	Scene::SetBackground(Color{ 220 });

	font_title.setBufferThickness(4);

	for (int i = 0; i < NUM_ARK; i++) {
		ark << Circle{ Scene::Width() / 2,Scene::Height() / 2,75 * (1 + i) };
		angle << Random<double>(90_deg, 180_deg);

		if (RandomBool(0.5)) {
			angle << angle.back() + Random<double>(10_deg, 20_deg);
			angle_speed << Random<double>(1_deg, 5_deg);
		}
		else {
			angle << angle.back() - Random<double>(10_deg, 20_deg);
			angle_speed << Random<double>(-5_deg, -1_deg);
		}
	}
}

void Finish::update() {
	if (not KeySpace.pressed()) {
		for (int32 i = 0; i < NUM_ARK; i++) {
			angle[i * 2] += angle_speed[i];
			angle[i * 2 + 1] += angle_speed[i];
		}
	}
	for (int32 i = 0; i < NUM_ARK * 2; i++) {
		if (angle[i] > 360_deg) {
			angle[i] -= 360_deg;
		}
		else if (angle[i] < -360_deg) {
			angle[i] += 360_deg;
		}
	}

	if (SimpleGUI::ButtonAt(U"Back Title", Vec2(Scene::Width() / 2, Scene::Height() / 2 + 100))) {
		changeScene(State::Title);
	}

	//debug();
}

void Finish::draw() const {
	for (int32 i = 0; i < NUM_ARK; i++) {
		if (i % 2 == 0) {
			ark[i].drawArc(angle[i * 2], angle[i * 2 + 1], 30, 0, Palette::Indigo);
		}
		else {
			ark[i].drawArc(angle[i * 2], angle[i * 2 + 1], 0, 30, Palette::Indigo);
		}
	}
	drawTitle();

	drawScore();
}

void Finish::debug() {

}

void Finish::drawTitle() const{
	static const String text = U"Finish!";
	static const double outlineScale = 0.4;
	static const ColorF outlineColor{ 0.0, 0.3, 0.6 };
	static const double fontSize = 100;

	//font_title(text).drawAt(TextStyle::OutlineShadow(outlineScale, outlineColor, shadowOffset, shadowColor), fontSize, Scene::Width() / 2, Scene::Height() / 2 - 100);
	font_title(text).drawAt(TextStyle::Outline(outlineScale, outlineColor), fontSize, Scene::Width() / 2, Scene::Height() / 2 - 100);
}

void Finish::drawScore() const {
	static const String score = U"Score : {}"_fmt(getData().Score);
	static const double outlineScale = 0.4;
	static const ColorF outlineColor{ 0.0, 0.3, 0.6 };

	font_title(score).drawAt(TextStyle::Outline(outlineScale, outlineColor), Scene::Width() / 2, Scene::Height() / 2);
}
