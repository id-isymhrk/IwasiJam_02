#pragma once
#include"Basic.hpp"

constexpr Vec2 p(400, 500);

class Title : public App::Scene
{
private:
	const Font font_title;
public:
	Title(const InitData& init);

	void update();
	void draw() const;
	void debug();
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
public:
	Inside(const InitData& init);

	void update();
	void draw() const;
	void debug();
};
