#include<iostream>
#include<cstdlib>
#include<ctime>
#include"20260714_QuesionHeader_name.h"
using namespace std;

//投球の種類を表示
void PitchingType(int pitching)
{
    switch (pitching)
    {
    case Straight:
        cout << "ストレート" << endl;
        break;

    case Curve:
        cout << "カーブ" << endl;
        break;

    case Slider:
        cout << "スライダー" << endl;
        break;

    case Sinker:
        cout << "シンカー" << endl;
        break;
    }
}
//結果判定
void Result(int out)
{
    if (out >= OUT_COUNT)
    {
        cout << "PLAYER WINNER!!" << endl;
    }
    else
    {
        cout << "CPU WINNER!!" << endl;
    }
}
//入力チェック
int InputCheck(int min, int max)
{
    int player;
	//入力チェック
    while (true)
    {
        cin >> player;
        
        if (player < PITCHING_MIN || player > PITCHING_MAX)
        {
            cout << "入力に誤りがあります。再入力してください。" << endl;
        }
        else
        {
            break;
        }
    }
    return player;
}