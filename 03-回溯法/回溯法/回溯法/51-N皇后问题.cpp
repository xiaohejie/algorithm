#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
	51. N �ʺ�
*/
class Solution {
	vector<vector<string>> res;
	void generateResult(vector<vector<bool>>& board) {
		vector<string> rs;
		for (int i = 0; i < board.size(); i++) {
			string ans = "";
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j]) {
					ans += 'Q';
				}
				else {
					ans += '.';
				}
			}
			rs.push_back(ans);
		}
		res.push_back(rs);
	}
	void dfs(int index, int n , vector<vector<bool>>& board, unordered_set<int>& col, unordered_set<int>& pie ,unordered_set<int>& na) {
		if (index == n) {
			generateResult(board);
			return;
		}

		for (int i = 0; i < n; i++) {
			if (col.count(i) || pie.count(index + i) || na.count(index - i)) {
				continue;
			}
			board[index][i] = true;
			//����¼ѡȡ�õ������Щ�㲻����ȡ
			col.insert(i);
			pie.insert(index + i);
			na.insert(index - i);
			//dfs
			dfs(index + 1, n, board, col, pie, na);
			//����
			board[index][i] = false;
			col.erase(i);
			pie.erase(index + i);
			na.erase(index - i);
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<bool>> board(n, vector<bool>(n, 0));		//��¼ѡ�е�λ��
		unordered_set<int> col, pie, na;
		dfs(0, n, board, col, pie, na);
		return res;
	}
};