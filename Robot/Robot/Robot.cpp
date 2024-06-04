#include "Robot.h"

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> net(n, vector<int>(m));
	int startX, startY, endX, endY;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> net[i][j];
			if (net[i][j] == 2) {
				startX = i;
				startY = j;
			} else if (net[i][j] == 3) {
				endX = i;
				endY = j;
			}
		}
	}

	int maxTurns;
	cin >> maxTurns;
	int minTime = bfs(net, startX, startY, endX, endY, maxTurns);
	cout << minTime << endl;

	return 0;