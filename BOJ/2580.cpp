/*
	BOJ 2580 - 스도쿠
	Created by haejun on 2020/03/18
*/
#include<iostream>
using namespace std;

const int MAX = 9;
int arr[MAX][MAX];
//가로, 세로, 네모
int checkX[MAX][MAX], checkY[MAX][MAX], checkS[MAX][MAX];

int squ(int y, int x) {
	return (y / 3) * 3 + (x / 3);
}

void print() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void DFS(int k) {
	if (k == 81) {
		print();
		exit(0);
	}

	int y = k / 9, x = k % 9;
	if (arr[y][x] != 0) {
		DFS(k + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (checkY[y][i] == 0 && checkX[x][i] == 0 && checkS[squ(y, x)][i] == 0) {
				checkY[y][i] = 1;
				checkX[x][i] = 1;
				checkS[squ(y, x)][i] = 1;
				arr[y][x] = i;
				DFS(k + 1);
				arr[y][x] = 0;
				checkY[y][i] = 0;
				checkX[x][i] = 0;
				checkS[squ(y, x)][i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != 0) {
				checkY[i][arr[i][j]] = 1;
				checkX[j][arr[i][j]] = 1;
				checkS[squ(i, j)][arr[i][j]] = 1;
			}
		}
	}

	DFS(0);


	return 0;
}