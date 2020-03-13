/*
	BOJ 10808 - 알파벳 개수
	Created by haejun on 2020/03/14
*/
#include<iostream>
#include<string>
using namespace std;

int check[27];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char a = s[i];
		check[a - 'a']++;
	}
	for (int i = 0; i < 26; i++) cout << check[i] << " ";

	return 0;
}