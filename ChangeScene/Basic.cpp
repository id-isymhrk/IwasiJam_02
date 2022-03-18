#include"Basic.hpp"


//ロード描画用の関数
void loading(double t) {
	Rect(200, 550, 400, 30).drawFrame(1, 1, Palette::White);
	Rect(200, 550, t, 30).draw(Palette::White);
}

State nameScene(int32 num) {
	static int32 n = 0;

	while (true) {
		n = Random<int32>(1, NUM_SCENE);
		if (num != n) {
			break;
		}
	}

	switch (num)
	{
	case 1:
		return State::ID01_Password;
		break;
	default:
		break;
	}
}
