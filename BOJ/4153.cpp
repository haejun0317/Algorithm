/*
	BOJ 4153 - 직각삼각형
	Created by haejun on 2020/03/12
*/
#include<iostream>
#include<memory.h>
using namespace std;

int arr[3];
bool check[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		memset(check, 0, sizeof(check));
		int max = 0;
		int idx = 0;
		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
			if (arr[i] > max) {
				max = arr[i];
				idx = i;
			}
		}

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) break;

		check[idx] = true;
		int sum = 0;
		for (int i = 0; i < 3; i++) {
			if (check[i] == false) {
				sum += arr[i] * arr[i];
			}
		}

		if (max * max == sum) cout << "right\n";
		else cout << "wrong\n";
	}

	return 0;
}