#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Job {
  char id;
  int dead;
  int profit;
};

struct DisjointSet {
  int* parent;
  DisjointSet(int n) {
    parent = new int[n + 1];
    for (int i = 0; i <= n; i++) parent[i] = i;
  }
  int find(int s) {
    if (s == parent[s]) return s;
    return parent[s] = find(parent[s]);
  }
  void merge(int u, int v) { parent[v] = u; }
};

int printJobScheduling(vector<Job> arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end(),
      [](const Job& a, const Job& b) { return a.profit > b.profit; });

  int maxdead = INT_MAX;
  for (auto i : arr) maxdead = max(maxdead, i.dead);
  DisjointSet ds(maxdead);

  for (int i = 0; i < n; i++) {
    int availableSlot = ds.find(arr[i].dead);
    if (availableSlot > 0) {
      ds.merge(ds.find(availableSlot - 1), availableSlot);
      cout << arr[i].id << " ";
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<Job> arr(n, {'a', 0, 0});
  for (int i = 0; i < n; i++) cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
  printJobScheduling(arr);
  return 0;
}