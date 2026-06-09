# 《图解算法》通用模板速查手册

> **用途**：统一全书代码模板的命名、结构和风格，降低第三阶"背诵模板"的记忆成本。
> 所有模板经过规范化处理，可直接复用到面试和刷题中。

---

## 模板命名规范

| 规范项 | 统一写法 | 禁止写法 |
|--------|---------|---------|
| 数组变量 | `nums`, `arr` | `a`, `data`, `list` |
| 双指针 | `l`(左), `r`(右) | `left/right`, `i/j` |
| 二分查找 | `left`, `right`, `mid` | `lo/hi`, `low/high` |
| 结果变量 | `res`, `ans` | `result`, `answer` |
| 取模常量 | `MOD = 1e9 + 7` | `mod`, `M`, `1000000007` |
| 图/网格 | `grid`, `rows`, `cols` | `matrix`, `R`, `C` |
| 哈希表 | `mp`, `freq` | `hash`, `map`, `umap` |
| 队列/栈 | `q`, `st` | `queue`, `stack` |
| 路径/当前选择 | `path` | `current`, `cur` |
| 已访问标记 | `used`, `visited` | `seen`, `mark` |
| DP 数组 | `dp` | `memo`, `f` |
| 树节点 | `TreeNode` | `Node`, `BTNode` |
| 快速幂函数 | `power(base, exp, mod)` | `qpow`, `fast_pow` |

---

## 模板 1：二分查找（万能模板）

```cpp
// 适用场景：有序数组中查找目标值或满足条件的最值
// 时间: O(log n), 空间: O(1)
int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

### 变体：二分答案（求最大值）

```cpp
// 单调性：答案越大 → 条件越不满足
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) { ans = mid; left = mid + 1; }
    else { right = mid - 1; }
}
```

### 变体：二分答案（求最小值）

```cpp
// 单调性：答案越大 → 条件越满足
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (check(mid)) { ans = mid; right = mid - 1; }
    else { left = mid + 1; }
}
```

---

## 模板 2：双指针

### 左右指针（有序数组）

```cpp
int l = 0, r = nums.size() - 1;
while (l < r) {
    if (nums[l] + nums[r] == target) { /* 找到 */ }
    else if (nums[l] + nums[r] < target) l++;
    else r--;
}
```

### 快慢指针（原地修改）

```cpp
int slow = 0;
for (int fast = 0; fast < nums.size(); fast++) {
    if (/* 条件 */) nums[slow++] = nums[fast];
}
```

### 排序 + 固定 + 双指针 + 去重（N数之和）

```cpp
sort(nums.begin(), nums.end());
for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i-1]) continue; // 去重
    int l = i + 1, r = n - 1;
    while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
            res.push_back({nums[i], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l+1]) l++; // 去重
            while (l < r && nums[r] == nums[r-1]) r--; // 去重
            l++; r--;
        } else if (sum < 0) l++;
        else r--;
    }
}
```

---

## 模板 3：滑动窗口

### 可变窗口（最长/最短合法子串）

```cpp
int l = 0, maxLen = 0;
for (int r = 0; r < s.size(); r++) {
    // 右指针纳入：更新窗口状态
    while (/* 窗口不合法 */) {
        // 左指针收缩：更新窗口状态
        l++;
    }
    maxLen = max(maxLen, r - l + 1);
}
```

### 固定窗口 + 单调队列

```cpp
deque<int> dq; // 存下标
for (int i = 0; i < nums.size(); i++) {
    while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
    while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) res.push_back(nums[dq.front()]);
}
```

---

## 模板 4：回溯（通用框架）

```cpp
void backtrack(参数) {
    if (/* 终止条件 */) {
        res.push_back(path);
        return;
    }
    for (int i = start; i < n; i++) {
        // 做选择
        path.push_back(nums[i]);
        backtrack(/* 更新参数 */);
        // 撤销选择
        path.pop_back();
    }
}
```

### 排列 vs 子集 vs 组合（参数差异）

| 问题类型 | 遍历起点 | 收集时机 | 去重手段 |
|---------|---------|---------|---------|
| 排列 | `i = 0`（全量扫描） | 叶子节点 | `used` 数组 |
| 子集 | `i = start`（只向后） | 每个节点 | `start` 天然去重 |
| 组合 | `i = start`（只向后） | 满足条件时 | `start` + 排序去重 |

---

## 模板 5：动态规划（五步法）

```cpp
// 步骤1：定义状态    → dp[i] 代表什么
// 步骤2：转移方程    → dp[i] = f(dp[i-1], dp[i-2], ...)
// 步骤3：初始条件    → dp[0], dp[1] 的值
// 步骤4：遍历顺序    → 从小到大 or 从大到小
// 步骤5：空间优化    → 能否用滚动变量替代数组

// 通用模板
vector<int> dp(n + 1, 0);
dp[0] = /* 初始值 */;
dp[1] = /* 初始值 */;
for (int i = 2; i <= n; i++) {
    dp[i] = /* 转移方程 */;
}
return dp[n];
```

### 0-1 背包

```cpp
vector<int> dp(W + 1, 0);
for (int i = 0; i < n; i++) {
    for (int j = W; j >= weight[i]; j--) { // ⚠️ 倒序！
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
```

### 完全背包

```cpp
vector<int> dp(W + 1, 0);
for (int i = 0; i < n; i++) {
    for (int j = weight[i]; j <= W; j++) { // 正序
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
```

### 树形 DP

```cpp
pair<int,int> dfs(TreeNode* node) {
    if (!node) return {0, 0};
    auto left = dfs(node->left);
    auto right = dfs(node->right);
    int take = node->val + left.second + right.second;
    int skip = max(left.first, left.second) + max(right.first, right.second);
    return {take, skip};
}
```

---

## 模板 6：DFS / BFS

### DFS 网格搜索

```cpp
void dfs(vector<vector<int>>& grid, int r, int c) {
    int rows = grid.size(), cols = grid[0].size();
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return;
    grid[r][c] = 0; // 标记已访问
    dfs(grid, r+1, c); dfs(grid, r-1, c);
    dfs(grid, r, c+1); dfs(grid, r, c-1);
}
```

### BFS 层序遍历

```cpp
queue<TreeNode*> q;
q.push(root);
while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front(); q.pop();
        // 处理 node
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

---

## 模板 7：贪心

### 维护最远可达

```cpp
int maxReach = 0;
for (int i = 0; i < n; i++) {
    if (i > maxReach) return false;
    maxReach = max(maxReach, i + power[i]);
    if (maxReach >= n - 1) return true;
}
```

### 排序 + 贪心匹配

```cpp
sort(needs.begin(), needs.end());
sort(supplies.begin(), supplies.end());
int i = 0, j = 0;
while (i < needs.size() && j < supplies.size()) {
    if (supplies[j] >= needs[i]) i++;
    j++;
}
return i;
```

---

## 模板 8：快速排序

```cpp
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] > pivot) j--;
        while (i < j && nums[i] <= pivot) i++;
        if (i < j) swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[j]);
    return j;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int pi = partition(nums, left, right);
    quickSort(nums, left, pi - 1);
    quickSort(nums, pi + 1, right);
}
```

---

## 模板 9：快速幂取模

```cpp
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// 求逆元（mod 为素数时）
long long mod_inv(long long a, long long mod) {
    return power(a, mod - 2, mod);
}
```

---

## 模板 10：矩阵快速幂

```cpp
typedef vector<vector<long long>> Matrix;

Matrix mat_mul(const Matrix& A, const Matrix& B, long long mod) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

Matrix mat_pow(Matrix base, long long exp, long long mod) {
    int n = base.size();
    Matrix result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) result[i][i] = 1;
    while (exp > 0) {
        if (exp & 1) result = mat_mul(result, base, mod);
        base = mat_mul(base, base, mod);
        exp >>= 1;
    }
    return result;
}
```

---

## 跨章节复用指南

| 模板 | 首次出现 | 复用章节 |
|------|---------|---------|
| 二分查找 | 第8章 | 第17章二分答案 |
| 快速幂 | 第17章 | 第15章(矩阵快速幂)、第19章(组合数)、附录 |
| 双指针 | 第9章 | 第16章高阶、第21章综合 |
| 滑动窗口 | 第18章 | 第21章综合 |
| DFS | 第13章 | 第28章工程迁移 |
| 回溯框架 | 第19章 | 第27章面试模拟 |
| DP五步法 | 第15章 | 第20章高阶DP |
| 单调队列 | 第18章 | 第27章面试模拟(柱状图) |

---

*本文档随书稿同步更新*
