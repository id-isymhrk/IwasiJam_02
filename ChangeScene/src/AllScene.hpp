#pragma once
#include"Basic.hpp"

//title
constexpr int32 NUM_ARK = 4;
//password
constexpr Vec2 p(400, 500);
//inside
constexpr int32 RECT_EDGE = 240;

class Title : public App::Scene
{
private:

	Array<double> angle;
	Array<double> angle_speed;
	Array<Circle> ark;

	const Font font_title;
public:
	Title(const InitData& init);

	void update();
	void draw() const;
	void debug();

	void drawTitle() const;
};

class Password : public App::Scene
{
private:
	const Font font_guide;
	const Font font_input;
	const Font font_hide;

	const Rect box_text;

	String text_input;

	bool flag_hide = true;

public:
	Password(const InitData& init);

	void update();
	void draw() const;
	void debug();

	void hidePassword();
};

class Load : public App::Scene
{
private:
	const Font font;

	String text;

	int32 TestNum = 0;

	double time = 0;

	int length = 0;

	bool flag_loading = true;
	double install = 0;

public:
	Load(const InitData& init);

	void update();
	void draw() const;
	void debug();
};

class Default : public App::Scene
{
private:
	// 通常のフォントを作成 | Create a new font60
	const Font font60;
	// 絵文字用フォントを作成 | Create a new emoji font60
	const Font emojiFont;

	// 画像ファイルからテクスチャを作成 | Create a texture from an image file
	const Texture texture;
	// 絵文字からテクスチャを作成 | Create a texture from an emoji
	const Texture emoji;

	// 絵文字を描画する座標 | Coordinates of the emoji
	Vec2 emojiPos{ 300, 150 };

	int32 count_button = 0;

public:
	Default(const InitData& init);

	void update();
	void draw() const;
	void debug();
};

class Inside : public App::Scene
{
private:
	Circle circle_mouse;
	RectF rect_hit;

	double time_hit = 0;

public:
	Inside(const InitData& init);

	void update();
	void draw() const;
	void debug();
};

constexpr int32 CHAIN_NUM = 5;
constexpr int32 RADIUS = 40;
constexpr double ANGLE_ROTATE = 2_deg;

class Chain :public App::Scene
{
private:
	int32 num_check = 0;

	Array<Vec2> chains_info;	//x:中心からの距離 y:角度
	Array<Vec2> pos_chain;
	Array<double> angle_rotate;
	Array<int32> chains_id;

	Array<Circle> chains;

	const Font font_value;

public:
	Chain(const InitData& init);

	void update();
	void draw() const;
	void debug();
};

constexpr int32 NUM_QUESTION = 4;

class OddEven :public App::Scene
{
private:
	const Font font_number;
	const Font font_select;

	Array<int32> num_random;

	int32 status = 0;

	const RectF rect_odd;
	const RectF rect_even;

public:
	OddEven(const InitData& init);

	void update();
	void draw() const;
	void debug();
};

class Finish:public App::Scene
{
private:

	Array<double> angle;
	Array<double> angle_speed;
	Array<Circle> ark;

	String score;

	const Font font_title;
	const Font font_score;

public:
	Finish(const InitData& init);

	void update();
	void draw() const;
	void debug();

	void drawTitle() const;
	void drawScore() const;
};
