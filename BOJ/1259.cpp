/*
	BOJ 1259 - 팰린드롬수
	Created by haejun on 2020/03/08
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> s;
		if (s == "0") break;

		bool flag = false;
		int b = s.size() - 1;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[b]) {
				flag = true;
				break;
			}
			b--;
		}
		if (flag == true) cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}