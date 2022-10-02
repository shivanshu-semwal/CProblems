#include <iostream>
#include <vector>

using namespace std;

int rowWithMax1s(vector<vector<int>> mat) {
  int rowIndex = -1;
  int maxCount = 0;
  for (int i = 0; i < mat.size(); i++) {
    int count = 0;
    for (int j = 0; j < mat[i].size(); j++) {
      if (mat[i][j] == 1) count++;
    }
    if (count > maxCount) {
      maxCount = count;
      rowIndex = i;
    }
  }
  return rowIndex;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> mat(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> mat[i][j];
  }
  cout << rowWithMax1s(mat);
  return 0;
}