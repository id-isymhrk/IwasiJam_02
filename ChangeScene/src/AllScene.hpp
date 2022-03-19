#pragma once
#include"Basic.hpp"

constexpr Vec2 p(400, 500);

class Password : public App::Scene
{
private:
	const Font font15;
	const Font font25;

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
