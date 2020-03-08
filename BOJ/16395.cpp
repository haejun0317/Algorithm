/*
	BOJ 16395 - 파스칼의 삼각형
	Created by haejun on 2020/03/09
*/
#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
#include<math.h>
#include<algorithm>
#include<string>
using namespace std;

int arr[32][32];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	arr[0][0] = 1;
	arr[1][0] = arr[1][1] = 1;
	for (int i = 2; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			if (j == 0) arr[i][j] = 1;
			else arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
		}
	}

	cout << arr[n - 1][m - 1] << "\n";


	return 0;
}