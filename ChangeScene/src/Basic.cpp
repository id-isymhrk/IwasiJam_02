#include"Basic.hpp"


//ロード描画用の関数
void loading(double time, double w = 400) {
	Rect(200, 500, w, 30).drawFrame(1, 1, Palette::White);
	Rect(200, 500, time, 30).draw(Palette::White);
}

State sceneRandom(int32 num) {
	static int32 n = 0;

	while (true) {
		n = Random<int32>(1, NUM_SCENE);
		if (num != n) {
			break;
		}
	}

	switch (n)
	{
	case 1:
		return State::ID01_Password;
		break;
	case 2:
		return State::ID02_Load;
		break;
	case 3:
		return State::ID03_Default;
		break;
	case 4:
		return State::ID04_Inside;
		break;
	default:
		break;
	}
}
