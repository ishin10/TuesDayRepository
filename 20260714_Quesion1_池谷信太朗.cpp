#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260714_QuesionHeader_name.h"
using namespace std;


//====================================
// メイン
//====================================
int main()
{
    //変数宣言
    int player;
    int cpu;
    int probability;
    
    int strike = 0;
    int ball = 0;
    int out = 0;
    int hit = 0;
	//乱数の初期化
    srand((unsigned int)time(nullptr));
    //インフォーメーション
    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;
    
    //決着までループ
    do
    {
        cout << endl;
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート" << endl;
        cout << "1:カーブ" << endl;
        cout << "2:スライダー" << endl;
        cout << "3:シンカー" << endl;

        player = InputCheck(PITCHING_MIN,PITCHING_MAX);

        PitchingType(player);
		//CPUの手をランダムで決定
        cpu = rand() % PROBABILITY;

        probability = rand() % PROBABILITY;

		//結果判定
        if (player != cpu)
        {
            if (probability == 0)
            {
                cout << "ボール！" << endl;
                ball++;
            }
            else
            {
                cout << "ストライク！！" << endl;
                strike++;
            }
        }
        else
        {
            strike = 0;
            ball = 0;

            if (probability == 1)
            {
                cout << "OUT!!" << endl;
                out++;
            }
            else
            {
                cout << "HIT!!" << endl;
                hit++;
            }
        }

        
        if (strike >= STRIKE_COUNT || ball >= BALL_COUNT)
        {
            if (strike >= STRIKE_COUNT)
            {
                cout << "三振アウト！" << endl;
                out++;
            }
            else
            {
                cout << "フォアボール！" << endl;
                hit++;
            }

            strike = 0;
            ball = 0;
        }
		//結果表示
        cout << endl;
        cout << "B : " << ball << endl;
        cout << "S : " << strike << endl;
        cout << "O : " << out << endl;
        cout << "Runner : " << hit << endl;

    } while (out < OUT_COUNT && hit < HIT_COUNT);
    
    Result(out);

    return 0;
}