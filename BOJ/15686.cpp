/*
	BOJ 15686 - 치킨 배달
	Created by haejun on 2020/02/18
*/
#include<iostream>
#include<memory.h>
#include<math.h>
using namespace std;
const int MAX = 52;

int n, m;
int arr[MAX][MAX];

struct coor {
	int y;
	int x;
};
coor home[MAX * MAX];
int homeCnt;
coor chiken[15];
int chikenCnt;

bool check[15];

int ans = 987987987;

void dfs(int a, int cnt) {
	if (cnt >= m) {
		//기저조건
		int sum = 0;
		for (int i = 0; i < homeCnt; i++) {
			int homeMin = 987987987;
			for (int j = 0; j < chikenCnt; j++) {
				if (check[j] == 0) continue;
				int temp = abs(home[i].y - chiken[j].y) + abs(home[i].x - chiken[j].x);
				if (temp < homeMin) homeMin = temp;
			}

			if (homeMin == 987987987) continue;
			sum += homeMin;
		}
		if (sum < ans) ans = sum;
		return;
	}
	for (int i = a; i < chikenCnt; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			dfs(i, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				home[homeCnt] = { i,j };
				homeCnt++;
			}
			else if (arr[i][j] == 2) {
				chiken[chikenCnt] = { i,j };
				chikenCnt++;
			}
		}
	}

	dfs(0, 0);

	cout << ans << "\n";


	return 0;
}

