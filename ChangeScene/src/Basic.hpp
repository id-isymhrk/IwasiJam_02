#pragma once
# include <Siv3D.hpp> // OpenSiv3D v0.6.3

constexpr int32 NUM_SCENE = 5;
constexpr double LIMIT_TIME = 30;

constexpr int32 SCORE_01 = 15;
constexpr int32 SCORE_02 = 25;
constexpr int32 SCORE_03 = 20;
constexpr int32 SCORE_04 = 30;
constexpr int32 SCORE_05 = 50;
constexpr int32 SCORE_06 = 10;

//シーン名
enum class State {
	Title,
	ID01_Password,
	ID02_Load,
	ID03_Default,
	ID04_Inside,
	ID05_Chain,
	ID06_OddEven,
	Finish
};

//ゲームデータ
struct GameData {
	int32 Score = 0;
	Stopwatch Time{ StartImmediately::No };
};

//シーン管理
using App = SceneManager<State, GameData>;



//全体用の関数
void loading(double time, double w);		//ロードの表現
State sceneRandom(int32);	//遷移するシーン名前を返す関数
