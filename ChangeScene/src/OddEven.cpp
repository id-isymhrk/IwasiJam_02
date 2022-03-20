#include"AllScene.hpp"

OddEven::OddEven(const InitData& init)
	:IScene(init), font_number{ 200,Typeface::Black }, font_select{ 75,Typeface::Black },
	rect_odd(Arg::center(Scene::Width() / 4 - 75, Scene::Height() / 2), RECT_EDGE + 10, Scene::Height()),
	rect_even(Arg::center(Scene::Width() * 3 / 4 + 75, Scene::Height() / 2), RECT_EDGE + 10, Scene::Height())
{
	ClearPrint();

	getData().Time.start();

	Scene::SetBackground(Palette::Black);


	for (int i = 0; i < NUM_QUESTION; i++) {
		num_random << Random<int32>(1, 100);
	}
}

void OddEven::update() {
	if (rect_odd.leftClicked()) {

		getData().Time.pause();
		if (num_random[status] % 2 == 1) {
			getData().Score += SCORE_06;
		}
		changeScene(sceneRandom(6));
	}
	else if (rect_even.leftClicked()) {

		getData().Time.pause();
		if (num_random[status] % 2 == 0) {
			getData().Score += SCORE_06;
		}
		changeScene(sceneRandom(6));
	}
}

void OddEven::draw() const {
	ClearPrint();
	Print << U"Click ODD or EVEN !!";
	Print << U"{} seconds later"_fmt(getData().Time.s());
	Print << U"{} points"_fmt(getData().Score);

	rect_even.draw(Palette::Blue);
	rect_odd.draw(Palette::Red);

	font_number(num_random[status]).drawAt(Scene::Width() / 2, Scene::Height() / 2, Palette::White);
	font_select(U"ODD").drawAt(Scene::Width() / 4 - 75, Scene::Height() / 2);
	font_select(U"EVEN").drawAt(Scene::Width() * 3 / 4 + 75, Scene::Height() / 2);
}

void OddEven::debug() {

}
