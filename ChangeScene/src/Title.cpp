#include"AllScene.hpp"

Title::Title(const InitData& init)
	:IScene(init), font_title{ FontMethod::MSDF, 40, Typeface::Bold }
{
	Scene::SetBackground(Color{ 0, 34, 49 });

	font_title.setBufferThickness(4);
}

void Title::update() {

	debug();
}

void Title::draw() const {
	static const String text = U"Change Scenes!";
	static const double outlineScale = 0.4;
	static const ColorF outlineColor{ 0.0, 0.3, 0.6 };
	static const double fontSize = 100;

	//font_title(text).drawAt(TextStyle::OutlineShadow(outlineScale, outlineColor, shadowOffset, shadowColor), fontSize, Scene::Width() / 2, Scene::Height() / 2 - 100);
	font_title(text).drawAt(TextStyle::Outline(outlineScale, outlineColor), fontSize, Scene::Width() / 2, Scene::Height() / 2 - 100);
}

void Title::debug() {

}
