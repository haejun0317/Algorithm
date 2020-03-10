/*
	BOJ 10988 - 팰린드롬인지 확인하기
	Created by haejun on 2020/03/11
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

	string s;
	cin >> s;
	int a = s.size();
	int b = a - 1;
	bool ans = false;
	for (int i = 0; i < a/2; i++) {
		if (s[i] != s[b]) {
			ans = true;
			break;
		}
		b--;
	}

	if (ans == false) cout << 1;
	else cout << 0;

	return 0;
}