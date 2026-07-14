#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260714_Header_池谷信太朗.h"

using namespace std;

////問3　CPUと対戦する数字ゲームを作成しよう
//CPUと対戦するゲーム「どっちの数字が大きいか」を作成してください。
//
//ゲームルール
//ゲーム開始時に、0～50までのランダムな数字を10個用意します。
//プレイヤーとCPUは、その中から1つの数字を選択します。
//数字の大きさを比較し、大きい数字を出した方に3点加算します。
//同じ数字だった場合は、プレイヤーとCPUの両方に1点加算します。
//この勝負を7回繰り返します。
//7回終了後、得点の高い方を勝者とします。
//プログラミングの仕様
//プレイヤーは、1～10番の中から番号を入力して数字を選択してください。
//CPUは、ランダムに番号を選択してください。
//一度選択した番号は、プレイヤー・CPUともに再度選択できません。
//毎回、選択した数字・勝敗・現在の得点を表示してください。
//7回の勝負が終了したら、最終得点と勝者を表示してください。

int main()
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		PlayerCardNumbers[i] = rand() % 51;
		CPUCardNumbers[i] = rand() % 51;
	}

	for (int i = 0; i < GAME_MATCH_COUNT; i++)
	{
		cout << "=========================" << i + 1 << "回目=========================" << endl;
		int PlayerChoice = -1;
		int CPUChoice;
		//CPUの手を表示する
		cout << "テスト:CPUの手は" << "\n1:" << CPUCardNumbers[1] << "\n2:" << CPUCardNumbers[2] << "\n3:" << CPUCardNumbers[3] << "\n4:"
			 << CPUCardNumbers[4]<< "\n5:" << CPUCardNumbers[5] << "\n6:" << CPUCardNumbers[6] << "\n7:" << CPUCardNumbers[7] << "\n8:"
			 << CPUCardNumbers[8]<< "\n9:" << CPUCardNumbers[9] << endl;
		//プレイヤーの手を表示する
		cout << "1から10の数字を選択してください" << endl;
		cout << "1:" << PlayerCardNumbers[0] << "\n2:" << PlayerCardNumbers[1] << "\n3:" << PlayerCardNumbers[2] << "\n4:" << PlayerCardNumbers[3]
			 << "\n5:" << PlayerCardNumbers[4] << "\n6:" << PlayerCardNumbers[5] << "\n7:" << PlayerCardNumbers[6] << "\n8:" << PlayerCardNumbers[7]
			 << "\n9:" << PlayerCardNumbers[8] << "\n10:" << PlayerCardNumbers[9] << endl;
		//プレイヤーの選択を取得する
		cin >> PlayerChoice;
		CPUChoice = rand() % 10 + 1;

		if (PlayerCardNumbers[PlayerChoice] > CPUCardNumbers[CPUChoice])
		{
			PlayerScore += 3;
		}
		else if (PlayerCardNumbers[PlayerChoice] < CPUCardNumbers[CPUChoice])
		{
			CPUScore += 3;
		}
		else
		{
			PlayerScore += 1;
			CPUScore += 1;
		}

		if (PlayerScore > CPUScore)
		{
			PlayerWINCount++;
		}
		else if (PlayerScore < CPUScore)
		{
			CPUWINCount++;
		}
		else
		{
			DrawCount++;
		}

	cout << "現在の得点" << endl;
	cout << "プレイヤー: " << PlayerScore << "点" << endl;
	cout << "CPU: " << CPUScore << "点" << endl;
	cout << "------------------------" << endl;
	}

	cout << "最終結果" << endl;
	cout << "プレイヤーの勝利回数: " << PlayerWINCount << endl;
	cout << "CPUの勝利回数: " << CPUWINCount << endl;
	cout << "引き分け回数: " << DrawCount << endl;
	return 0;
}