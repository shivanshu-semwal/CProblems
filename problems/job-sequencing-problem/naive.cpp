#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Job {
  char id;
  int dead;
  int profit;
};

void printJobScheduling(vector<Job>& arr) {
}

int main() {
  int n;
  cin >> n;
  vector<Job> arr(n, {'a', 0, 0});
  for (int i = 0; i < n; i++) cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
  printJobScheduling(arr);
  return 0;
}
