class Solution {
public:
  vector<int> res;
  vector<int> pancakeSort(vector<int> &arr) {
    sort(arr, arr.size());
    return res;
  }

  void sort(vector<int> &arr, int n) {
    if (n == 1)
      return;
    int maxn = 0, maxidx = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > maxn) {
        maxn = arr[i];
        maxidx = i;
      }
    }

    res.push_back(maxidx + 1);
    reverse(arr, 0, maxidx);
    res.push_back(n);
    reverse(arr, 0, n - 1);

    sort(arr, n - 1);
  }

  void reverse(vector<int> &arr, int l, int r) {
    while (l < r) {
      int tmp;
      tmp = arr[l];
      arr[l] = arr[r];
      arr[r] = tmp;
      l++;
      r--;
    }
  }
};

// 执行用时： 4 ms , 在所有 C++ 提交中击败了 68.44% 的用户
// 内存消耗： 11.1 MB , 在所有 C++ 提交中击败了 18.12% 的用户
