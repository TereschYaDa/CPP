#pragma once
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Point {
	public:
	int x, y, turns, time;
	Point(int _x, int _y, int _turns, int _time)
		: x(_x), y(_y), turns(_turns), time(_time) {}
};

int bfs(vector<vector<int>>& net, int startX, int startY, int endX, int endY, int maxTurns) {
	int n = net.size(), m = net[0].size();
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(maxTurns + 1, false)));
	queue<Point> q;
	q.push(Point(startX, startY, 0, 0));
	visited[startX][startY][0] = true;

	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	while (!q.empty()) {
		Point p = q.front();
		q.pop();

		if (p.x == endX && p.y == endY) {
			return p.time;
		}

		for (int i = 0; i < 4; ++i) {
			int newX = p.x + dx[i];
			int newY = p.y + dy[i];
			int newTurns = p.turns;
			int newTime = p.time + 1;

			if (i != 0) {
				newTurns++;
			}

			if (newX >= 0 && newX < n && newY >= 0 && newY < m &&
				net[newX][newY] != 1 && newTurns <= maxTurns) {
				if (!visited[newX][newY][newTurns]) {
					visited[newX][newY][newTurns] = true;
					q.push(Point(newX, newY, newTurns, newTime));
				}
			}
		}
	}

	return -1;
}
