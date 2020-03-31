/*
	Programmers 42587 - 프린터
	Created by haejun on 2020/03/31
*/
#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	priority_queue <int> pq;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push(make_pair(priorities[i], i));
	}

	while (true) {
		// a == 중요도, b == 순서
		int a = q.front().first;
		int b = q.front().second;
		q.pop();

		if (a == pq.top()) {
			pq.pop();
			answer++;
			if (b == location) break;
		}
		else {
			q.push(make_pair(a, b));
		}

	}
	return answer;
}
