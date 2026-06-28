class Solution {
public:
    int maximumLength(vector<int>& nums) {
    int ans = 1;
    map<double, int> mp; // 记录每个元素出现的次数
    for (int num : nums) mp[num]++;

    for (auto item : mp) {
      int x = item.first, count = item.second, len = 1; // x 是中间的最大点, 也是顶点
      if (x == 1) { // 需要特殊判断
        ans = max(ans, count - (count % 2 == 0)); // ans必须是奇数
        continue;
      }

      double next = sqrt(x);
      while (mp.find(next) != mp.end() && mp[next] >= 2) { // 判断是否可以往x的两边添加元素
        len += 2;
        next = sqrt(next);
      }
      ans = max(ans, len);
    }

    return ans;
    }
};