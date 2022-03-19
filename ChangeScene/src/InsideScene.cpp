#include"AllScene.hpp"

Inside::Inside(const InitData& init)
	:IScene(init)
{
	Scene::SetBackground(Palette::Black);

	rect_hit = RectF(Arg::center(Random<double>(RECT_EDGE / 2, Scene::Width() - RECT_EDGE / 2), Random<double>(RECT_EDGE / 2, Scene::Height() - RECT_EDGE / 2)), RECT_EDGE);
	circle_mouse = Circle{ Cursor::Pos(),40 };
}

void Inside::update() {

	circle_mouse = Circle{ Cursor::Pos(),40 };

	if (rect_hit.contains(circle_mouse) and time_hit < 255) {
		time_hit += 2;
	}
	if (time_hit > 255) {
		time_hit = 255;
		changeScene(sceneRandom(4));
	}
	debug();
}

void Inside::draw() const {
	Scene::SetBackground(Color(time_hit));

	circle_mouse.draw(Palette::Red);

	rect_hit.draw(Color(0, 100));
}

void Inside::debug() {
	ClearPrint();
	Print << time_hit;
}
