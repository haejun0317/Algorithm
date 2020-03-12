/*
	BOJ 2920 - 음계
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<string>
using namespace std;

int arr[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a = 1;
	int d = 8;
	bool cA = true, cD = true;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		if (arr[i] != a) cA = false;
		if (arr[i] != d) cD = false;
		a++; d--;
	}

	if (cA == true) cout << "ascending";
	else if (cD == true) cout << "descending";
	else cout << "mixed";

	return 0;
}