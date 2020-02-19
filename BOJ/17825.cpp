/*
	BOJ 17825 - 주사위 윷놀이
	Created by haejun on 2020/02/19
*/
#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int arr[10];

int pan[34];
int span[34];
int score[34];

bool check[34];
int ans;

//말 현재위치
int mal[5];


void dfs(int cnt, int sum) {
	if (cnt == 10) {
		if (sum > ans) ans = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int prev = mal[i];
		int now = prev;
		int move = arr[cnt];

		if (span[now] > 0) {
			now = span[now];
			move -= 1;
		}
		while (move--) {
			now = pan[now];
		}
		if (now != 32 && check[now] == true) continue;
		check[prev] = false;
		check[now] = true;
		mal[i] = now;
 		dfs(cnt + 1, sum + score[now]);
		mal[i] = prev;
		check[prev] = true;
		check[now] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 판 초기화
	for (int i = 0; i < 20; i++) pan[i] = i + 1;
	pan[20] = 32; pan[32] = 32;
	pan[21] = 22; pan[22] = 23; pan[23] = 26;
	pan[24] = 25; pan[25] = 26;
	pan[27] = 28; pan[28] = 29; pan[29] = 26;
	pan[26] = 30; pan[30] = 31; pan[31] = 20;

	span[5] = 21;
	span[10] = 24;
	span[15] = 27;

	for (int i = 0; i < 20; i++) score[i] = i * 2;
	score[21] = 13; score[22] = 16; score[23] = 19;
	score[24] = 22; score[25] = 24;
	score[27] = 28; score[28] = 27; score[29] = 26;
	score[26] = 25; score[30] = 30; score[31] = 35;
	score[20] = 40; score[32] = 0;
 
	for (int i = 0; i < 10; i++) cin >> arr[i];

	dfs(0,0);

	cout << ans << "\n";

	return 0;
}