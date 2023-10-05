#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Job {
  char id;
  int dead;
  int profit;
};

void printJobScheduling(vector<Job> arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end(), [](const Job& a, const Job& b) { return a.profit > b.profit; });

  vector<int> result(n);
  vector<bool> slot(n, false);

  for (int i = 0; i < n; i++) {
    for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
      if (slot[j] == false) {
        result[j] = i;
        slot[j] = true;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (slot[i])
      cout << arr[result[i]].id << " ";
}

int main() {
  int n;
  cin >> n;
  vector<Job> arr(n, {'a', 0, 0});
  for (int i = 0; i < n; i++) cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
  printJobScheduling(arr);
  return 0;
}
