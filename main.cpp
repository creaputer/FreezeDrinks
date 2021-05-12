#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x;
  int y;
};

vector<vector<int>> board;
const Point direction[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void bfs_mark(Point start) {
	queue<Point> q;
	q.push(start);

	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
    board[cur.y][cur.x] = 1;

		for (int i = 0; i < 4; ++i) {
		  Point move = {cur.x + direction[i].x, cur.y + direction[i].y};
		  
		  if (move.x < 0) continue;
		  if (move.y < 0) continue;
		  if (move.x >= board[0].size()) continue;
		  if (move.y >= board.size()) continue;
		  
		  if (board[move.y][move.x] == 0) {
		    q.push(move);
		  }
		}
	}
}

int search() {
	int count = 0;

	for (int y = 0; y < board.size(); y++) {
		for (int x = 0; x < board[y].size(); ++x) {
			if (board[y][x] == 0) {
				count++;
				bfs_mark({x, y});
			}
		}
	}

	return count;
}

int main() {
	std::cout << "Freeze Drinks!\n";

	board.push_back({0, 0, 1, 1, 0});
	board.push_back({0, 0, 0, 1, 1});
	board.push_back({1, 1, 1, 1, 1});
	board.push_back({0, 0, 0, 0, 0});

	std::cout << "Count : " << search() << endl;
	
}