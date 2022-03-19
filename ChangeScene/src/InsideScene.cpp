#include"AllScene.hpp"

Inside::Inside(const InitData& init)
	:IScene(init)
{
	ClearPrint();

	getData().Time.start();

	Scene::SetBackground(Palette::Black);

	rect_hit = RectF(Arg::center(Random<double>(RECT_EDGE / 2, Scene::Width() - RECT_EDGE / 2), Random<double>(RECT_EDGE / 2, Scene::Height() - RECT_EDGE / 2)), RECT_EDGE);
	circle_mouse = Circle{ Cursor::Pos(),40 };
}

void Inside::update() {
	if (getData().Time.sF() > LIMIT_TIME) {
		changeScene(State::Finish);
	}
	else {
		circle_mouse = Circle{ Cursor::Pos(),40 };

		
		if (time_hit >= 255) {
			time_hit = 255;
			getData().Time.pause();
			getData().Score += SCORE_04;
			changeScene(sceneRandom(4));
		}
		else if (rect_hit.contains(circle_mouse)) {
			time_hit += 1.5;
		}
	}
	//debug();
}

void Inside::draw() const {
	ClearPrint();
	Print << U"Seek Inside Rectangle !!";
	Print << U"{} seconds later"_fmt(getData().Time.s());
	Print << U"{} points"_fmt(getData().Score);

	Scene::SetBackground(Color(time_hit));

	circle_mouse.draw(Palette::Red);

	rect_hit.draw(Color(0, 100));
}

void Inside::debug() {
	ClearPrint();
	Print << time_hit;
}
