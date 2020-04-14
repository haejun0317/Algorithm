﻿﻿/*
	BOJ 11403 - 경로 찾기
	Created by haejun on 2020/04/14
*/
#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

const int MAX = 101;
int arr[MAX][MAX];
int map[MAX][MAX];
int check[MAX];
vector <int> v[MAX];

int n;

void DFS(int node, int temp) {
	map[node][temp] = 1;

	if (check[temp] == 0) {
		check[temp] = 1;
		for (int i = 0; i < v[temp].size(); i++) {
			DFS(node, v[temp][i]);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				v[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && check[i] == 0) {
				check[i] = 1;
				DFS(i, j);
				memset(check, 0, sizeof(check));
			}
		}
	}

	//테스트 출력

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}




	return 0;
}