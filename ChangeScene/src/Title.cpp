#include"AllScene.hpp"

Title::Title(const InitData& init)
	:IScene(init), font_title{ FontMethod::MSDF, 40, Typeface::Bold }
{
	Scene::SetBackground(Color{ 0, 34, 49 });

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

void Title::update() {
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

	if (SimpleGUI::ButtonAt(U"Game Start",Vec2(Scene::Width()/2,Scene::Height()/2+100))) {
		changeScene(sceneRandom(0));
	}

	//debug();
}

void Title::draw() const {
	for (int32 i = 0; i < NUM_ARK; i++) {
		if (i % 2 == 0) {
			ark[i].drawArc(angle[i * 2], angle[i * 2 + 1], 30, 0);
		}
		else {
			ark[i].drawArc(angle[i * 2], angle[i * 2 + 1], 0, 30);
		}
	}
	drawTitle();
}

void Title::debug() {
	ClearPrint();
	for (int32 i = 0; i < NUM_ARK; i++) {
		Print << U"No{}:{}"_fmt(i * 2, angle[i * 2] / 1_deg);
		Print << U"No{}:{}"_fmt(i * 2 + 1, angle[i * 2 + 1] / 1_deg);
		Print << U"No{}speed:{}"_fmt(i, angle_speed[i] / 1_deg);
	}

}

void Title::drawTitle() const {
	static const String text = U"Change Scenes!";
	static const double outlineScale = 0.4;
	static const ColorF outlineColor{ 0.0, 0.3, 0.6 };
	static const double fontSize = 100;

	//font_title(text).drawAt(TextStyle::OutlineShadow(outlineScale, outlineColor, shadowOffset, shadowColor), fontSize, Scene::Width() / 2, Scene::Height() / 2 - 100);
	font_title(text).drawAt(TextStyle::Outline(outlineScale, outlineColor), fontSize, Scene::Width() / 2, Scene::Height() / 2 - 100);
}
