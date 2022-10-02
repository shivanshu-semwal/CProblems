#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeLPS(string pat) {
  vector<int> lps(pat.length(), 0);
  int len = 0;
  int i = 1;
  while (i < pat.length()) {
    if (pat[i] == pat[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps;
}

void KMPSearch(string pat, string txt) {
  vector<int> lps = computeLPS(pat);
  int i = 0;
  int j = 0;
  while ((txt.length() - i) >= (pat.length() - j)) {
    if (pat[j] == txt[i]) {
      j++;
      i++;
    }
    if (j == pat.length()) {
      printf("Found pattern at index %d ", i - j);
      j = lps[j - 1];
    } else if (i < txt.length() && pat[j] != txt[i]) {
      if (j != 0)
        j = lps[j - 1];
      else
        i = i + 1;
    }
  }
}

int main() {
  string txt = "ABABDABACDABABCABAB";
  string pat = "ABABCABAB";
  KMPSearch(pat, txt);
  return 0;
}