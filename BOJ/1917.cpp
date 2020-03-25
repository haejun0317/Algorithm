/*
	BOJ 1917 - 정육면체 전개도
	Created by haejun on 2020/03/25
*/
#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<vector>
using namespace std;
const int n = 6;

int arr[6][6];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);


	for (int t = 0; t < 3; t++) {

		bool ans = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		// row == 가로, col == 세로
		vector <int> row[n];
		vector <int> col[n];
		int rowCnt = 0;
		int rowCheck;
		for (int i = 0; i < n; i++) {
			rowCheck = 0;
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1) {
					rowCheck = 1;
					row[rowCnt].push_back(j);
				}
			}
			if (rowCheck == 1) rowCnt += 1;
		}
		int colCnt = 0;
		int colCheck;
		for (int i = 0; i < n; i++) {
			colCheck = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j][i] == 1) {
					colCheck = 1;
					col[colCnt].push_back(j);
				}
			}
			if (colCheck == 1) colCnt += 1;
		}

		//가로 기준
		if (rowCnt == 3) {
			// 141, 222, 132, 231;
			if (row[0].size() == 1 && row[1].size() == 4 && row[2].size() == 1) ans = true;
			if (row[0].size() == 2 && row[1].size() == 2 && row[2].size() == 2) {
				if (row[0][0] == row[1][1] && row[1][0] == row[2][1]) ans = true;
				if (row[0][1] == row[1][0] && row[1][1] == row[2][0]) ans = true;
			}

			if (row[0].size() == 1 && row[1].size() == 3 && row[2].size() == 2) {
				if (row[2][1] == row[1][0] || row[2][0] == row[1][2]) ans = true;
			}
			if (row[0].size() == 2 && row[1].size() == 3 && row[2].size() == 1) {
				if (row[0][0] == row[1][2] || row[0][1] == row[1][0]) ans = true;
			}
		}
		else if (rowCnt == 2) {
			// 33
			if (row[0].size() == 3 && row[1].size() == 3) {
				if (row[0][0] == row[1][2] || row[0][2] == row[1][0]) ans = true;
			}
		}

		//세로 기준
		if (colCnt == 3) {
			// 141, 222, 132, 231;
			if (col[0].size() == 1 && col[1].size() == 4 && col[2].size() == 1) ans = true;
			if (col[0].size() == 2 && col[1].size() == 2 && col[2].size() == 2) {
				if (col[0][0] == col[1][1] && col[1][0] == col[2][1]) ans = true;
				if (col[0][1] == col[1][0] && col[1][1] == col[2][0]) ans = true;
			}

			if (col[0].size() == 1 && col[1].size() == 3 && col[2].size() == 2) {
				if (col[2][1] == col[1][0] || col[2][0] == col[1][2]) ans = true;
			}
			if (col[0].size() == 2 && col[1].size() == 3 && col[2].size() == 1) {
				if (col[0][0] == col[1][2] || col[0][1] == col[1][0]) ans = true;
			}
		}
		else if (colCnt == 2) {
			// 33
			if (col[0].size() == 3 && col[1].size() == 3) {
				if (col[0][0] == col[1][2] || col[0][2] == col[1][0]) ans = true;
			}
		}

		if (ans == true) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}