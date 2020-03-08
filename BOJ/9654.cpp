/*
	BOJ 9654 - 나부 함대 데이터
	Created by haejun on 2020/03/09
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cout << "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE" << '\n';
	cout << "N2 Bomber      Heavy Fighter  Limited    21        " << '\n';
	cout << "J-Type 327     Light Combat   Unlimited  1         " << '\n';
	cout << "NX Cruiser     Medium Fighter Limited    18        " << '\n';
	cout << "N1 Starfighter Medium Fighter Unlimited  25        " << '\n';
	cout << "Royal Cruiser  Light Combat   Limited    4         " << '\n';

	return 0;
}