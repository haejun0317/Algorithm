/*
	BOJ 10039 - 평균 점수
	Created by haejun on 2020/03/13
*/
#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a;
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		if (a < 40) a = 40;
		sum += a;
	}

	cout<< sum / 5;
	

	return 0;
}