/*
	BOJ 1152 - 단어의 개수
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<string>
using namespace std;

string s;
int sum;
int flag;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (i == 0 && s[i] == ' ') continue;
		if (s[i] != ' ' && flag == false) {
			sum++;
			flag = true;
		}
		else if (s[i] == ' ') flag = false;
	}
	cout <<sum<<"\n";

	return 0;
}