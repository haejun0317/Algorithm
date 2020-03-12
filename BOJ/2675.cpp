/*
	BOJ 2675 - 문자열 반복
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<string>
using namespace std;

string s;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < a; j++) {
				cout << s[i];
			}
		}
		cout << "\n";
	}

	return 0;
}