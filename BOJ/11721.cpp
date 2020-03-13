/*
	BOJ 11721 - 열 개씩 끊어 출력하기
	Created by haejun on 2020/03/14
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	int a = 0;
	for (int i = 0; i < s.size(); i++) {
		cout << s[i];
		a++;
		if (a % 10 == 0) cout << "\n";
	}

	return 0;
}