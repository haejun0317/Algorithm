/*
	BOJ 10820 - 문자열 분석
	Created by haejun on 2020/03/14
*/
#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 100; i++) {
		string s;
		getline(cin, s);

		if (s.size() == 0) break;

		int a = 0, b = 0, c = 0, d = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] >= 'A' && s[j] <= 'Z') a++;
			else if (s[j] >= 'a' && s[j] <= 'z') b++;
			else if (s[j] >= '0' && s[j] <= '9') c++;
			else if (s[j] == ' ') d++;
		}
		cout << b <<" "<< a << " " << c << " " << d<<"\n";
	}

	return 0;
}