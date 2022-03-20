#include"AllScene.hpp"

Chain::Chain(const InitData& init)
	:IScene(init),font_value{30}
{
	for (int i = 0; i < CHAIN_NUM; i++) {
		if (i == 0) {
			chains_info << Vec3{ Random<double>(50,250), Random<double>(0_deg,359_deg), Random<int32>(0,100) };
		}
		else {
			chains_info << Vec3{ Random<double>(50,250), Random<double>(0_deg,359_deg), chains_info.back().z + Random<int32>(1,100) };
		}

		angle_rotate << Random<double>(-2_deg, 2_deg);
	}
}

void Chain::update() {
	for (int i = 0; i < CHAIN_NUM; i++) {
		chains_info[i].y += angle_rotate[i];
		if (chains_info[i].y > 360_deg) {
			chains_info[i].y -= 360_deg;
		}
		else if (chains_info[i].y < -360_deg) {
			chains_info[i].y += 360_deg;
		}
	}
}

void Chain::draw() const {
	static Vec2 pos;
	for (int i = 0; i < CHAIN_NUM; i++) {
		pos = OffsetCircular{ Scene::Center(), chains_info[i].x, chains_info[i].y };
		Circle{ Arg::center(pos),RADIUS }.draw(Palette::Red);
		font_value(chains_info[i].z).drawAt(pos);
	}
}

void Chain::debug() {

}
