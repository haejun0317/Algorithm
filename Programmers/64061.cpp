/*
	Programmers 64061 - 크레인 인형뽑기 게임
	2019 카카오 겨울인턴 1번 문제
	Created by haejun on 2020/04/03
*/
#include<iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	stack <int> s;
	int answer = 0;

	int n = board.size();
	int m = board[0].size();

	int move = moves.size();

	vector <int> ans;

	for (int i = 0; i < move; i++) {
		// 꺼낼 순서
		int temp = 0;
		int outDoll = moves[i] - 1;

		// 인형이 있는지 확인
		bool flag = false;
		for (int j = 0; j < m; j++) {
			if (flag == true) break;
			if (board[j][outDoll] == 0) continue;

			flag = true;

			if (!s.empty()) {
				if (s.top() == board[j][outDoll]) {
					answer += 2;
					s.pop();
				}
				else {
					s.push(board[j][outDoll]);
				}
			}
			else {
				s.push(board[j][outDoll]);
			}

			board[j][outDoll] = 0;
		}
	}

	return answer;
}