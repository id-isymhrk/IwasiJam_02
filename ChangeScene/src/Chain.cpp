#include"AllScene.hpp"

Chain::Chain(const InitData& init)
	:IScene(init), font_value{ 30,Typeface::Bold }
{
	ClearPrint();

	getData().Time.start();

	num_check = 0;

	for (int i = 0; i < CHAIN_NUM; i++) {
		if (i == 0) {
			chains_id << Random<int32>(0, 100);
		}
		else {
			chains_id << chains_id.back() + Random<int32>(1,100);
		}

		chains_info << Vec2{ Random<double>(50,250), Random<double>(0_deg,359_deg) };
		pos_chain << OffsetCircular{ Scene::Center(), chains_info[i].x, chains_info[i].y };

		chains << Circle{ Arg::center(pos_chain[i]),RADIUS };

		if (RandomBool(0.5)) {
			angle_rotate << Random<double>(1_deg / 2, 2_deg);
		}
		else {
			angle_rotate << Random<double>(-2_deg, -1_deg / 2);
		}
	}
}

void Chain::update() {
	if (getData().Time.sF() > LIMIT_TIME) {
		changeScene(State::Finish);
	}
	else {
		//update chain position
		for (int i = 0; i < CHAIN_NUM; i++) {
			chains_info[i].y += angle_rotate[i];
			if (chains_info[i].y > 360_deg) {
				chains_info[i].y -= 360_deg;
			}
			else if (chains_info[i].y < -360_deg) {
				chains_info[i].y += 360_deg;
			}

			pos_chain[i] = OffsetCircular{ Scene::Center(), chains_info[i].x, chains_info[i].y };

			chains[i].setCenter(pos_chain[i]);

			if (chains[i].leftClicked() and i == num_check) {
				num_check++;
			}

			//Game Clear
			if (num_check == CHAIN_NUM) {

				getData().Time.pause();
				getData().Score += SCORE_05;
				changeScene(sceneRandom(5));
			}
		}
	}

	//debug();
}

void Chain::draw() const {
	ClearPrint();
	Print << U"Click circles (minimum number is first) !!";
	Print << U"{} seconds later"_fmt(getData().Time.s());
	Print << U"{} points"_fmt(getData().Score);

	for (int i = 0; i < CHAIN_NUM; i++) {
		if (0 < i and i < num_check) {
			Line(pos_chain[i - 1], pos_chain[i]).draw(5, Palette::Yellow);
		}

		if (i < num_check) {
			chains[i].draw(Palette::Red);
			font_value(chains_id[i]).drawAt(pos_chain[i], Palette::White);
		}
		else {
			chains[i].draw(Palette::White);
			font_value(chains_id[i]).drawAt(pos_chain[i], Palette::Black);
		}
	}
}

void Chain::debug() {
	ClearPrint();
	Print << num_check;
}
