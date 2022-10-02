#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Job {
  char id;
  int dead;
  int profit;
};

void printJobScheduling(vector<Job> arr) {
  int n = arr.size();
  vector<Job> result;
  sort(arr.begin(), arr.end(), [](Job a, Job b) { return a.dead < b.dead; });
  auto compare = [](const Job& a, const Job& b) { return a.profit < b.profit; };
  priority_queue<Job, vector<Job>, decltype(compare)> pq(compare);

  for (int i = n - 1; i >= 0; i--) {
    int slot_available = (i == 0) ? arr[i].dead : (arr[i].dead - arr[i - 1].dead);
    pq.push(arr[i]);
    while (slot_available > 0 && pq.size() > 0) {
      result.push_back(pq.top());
      pq.pop();
      slot_available--;
    }
  }

  sort(result.begin(), result.end(), [&](Job a, Job b) { return a.dead < b.dead; });
  for (int i = 0; i < result.size(); i++) cout << result[i].id << ' ';
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<Job> arr(n, {'a', 0, 0});
  for (int i = 0; i < n; i++) cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
  printJobScheduling(arr);
  return 0;
}
