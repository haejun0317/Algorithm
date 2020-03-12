/*
	BOJ 8958 - OX퀴즈
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<string>
using namespace std;

int n;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		cin >> s;
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'O') {
				cnt++;
				sum += cnt;
			}
			else cnt = 0;
		}
		cout << sum << "\n";
	}

	return 0;
}