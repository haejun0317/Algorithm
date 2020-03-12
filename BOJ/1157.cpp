/*
	BOJ 1157 - 단어 공부
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<string>
using namespace std;

string s;
int arr[30];
int maximum;
int maximumIdx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int a = s[i] - 'A';
		if (a >= 32) a -= 32;
		arr[a]++;
		if (maximum < arr[a]) {
			maximum = arr[a];
			maximumIdx = a;
		}
	}

	bool flag = false;
	for (int i = 0; i < 26; i++) if (i != maximumIdx && arr[i] == maximum) flag = true;

	char ans = maximumIdx + 'A';
	if (flag == true) cout << "?";
	else cout << ans;

	return 0;
}