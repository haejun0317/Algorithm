/*
	BOJ 1924 - 2007년
	Created by haejun on 2020/03/14
*/
#include<iostream>
#include<string>
using namespace std;

int arr[13][32];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a = 0;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 31; j++) {
			if ((i == 4 || i == 6 || i == 9 || i == 11) && j > 30) continue;
			if (i == 2 && j > 28) continue;
			arr[i][j] = a % 7;
			a++;
		}
	}

	int b, c;
	cin >> b >> c;
	if (arr[b][c] == 6) cout << "SUN";
	else if (arr[b][c] == 0) cout << "MON";
	else if (arr[b][c] == 1) cout << "TUE";
	else if (arr[b][c] == 2) cout << "WED";
	else if (arr[b][c] == 3) cout << "THU";
	else if (arr[b][c] == 4) cout << "FRI";
	else if (arr[b][c] == 5) cout << "SAT";

	return 0;
}