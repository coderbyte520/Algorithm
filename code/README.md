# 《图解算法》配套代码仓库

> 本仓库为《图解算法：从零到精通的趣味入门书》全书配套代码，读者可直接下载运行，强化第四阶「真题刷题」的实操性。

---

## 快速开始

### 环境要求

- C++17 编译器（g++ / clang++）
- 推荐使用 VSCode + Code Runner 插件

### 编译运行

```bash
# 进入对应章节目录
cd code/ch16_two_pointers

# 编译
g++ -std=c++17 -o three_sum 01_three_sum.cpp

# 运行
./three_sum
```

### 一键编译所有章节（Linux/Mac）

```bash
find . -name "*.cpp" -exec g++ -std=c++17 -o {}.out {} \;
```

---

## 目录结构

```
code/
├── README.md                  ← 本文件
├── DIFFICULTY.md              ← 难度分层索引
├── templates/
│   └── template_reference.md  ← 全书统一模板速查手册
│
├── ch01_algorithm_basics/     ← 第1章 算法基础
│   ├── 01_two_sum_brute.cpp
│   └── 02_two_sum_hash.cpp
│
├── ch02_complexity/           ← 第2章 复杂度分析
│   └── 01_arithmetic_geometric.cpp
│
├── ch03_containers/           ← 第3章 容器
│   ├── 01_vector_sum.cpp
│   ├── 02_unordered_map.cpp
│   └── 03_string_reverse.cpp
│
├── ch04_arrays/               ← 第4章 数组
│   ├── 01_array_max_min.cpp
│   └── 02_remove_duplicates.cpp
│
├── ch05_hashing/              ← 第5章 哈希
│   └── 01_valid_anagram.cpp
│
├── ch06_strings/              ← 第6章 字符串
│   └── 01_palindrome.cpp
│
├── ch07_sorting/              ← 第7章 排序
│   ├── 01_quicksort.cpp
│   └── 02_bubble_sort.cpp
│
├── ch08_binary_search/        ← 第8章 二分查找
│   └── 01_binary_search.cpp
│
├── ch09_two_pointers/         ← 第9章 双指针基础
│   └── 01_two_sum_sorted.cpp
│
├── ch10_prefix_sum/           ← 第10章 前缀和
│   └── 01_prefix_sum.cpp
│
├── ch11_stack_queue/          ← 第11章 栈与队列
│   └── 01_valid_parentheses.cpp
│
├── ch12_binary_tree/          ← 第12章 二叉树
│   └── 01_tree_traversal.cpp
│
├── ch13_dfs_bfs/              ← 第13章 DFS与BFS
│   ├── 01_cloud_dfs.cpp
│   └── 02_level_order_bfs.cpp
│
├── ch14_greedy/               ← 第14章 贪心算法
│   ├── 01_drone_greedy.cpp
│   └── 02_supply_greedy.cpp
│
├── ch15_dp_intro/             ← 第15章 DP入门与数学公式
│   ├── 01~03_frog_jump_dp.cpp (递归/DP数组/滚动变量)
│   ├── 04_fib_matrix.cpp
│   ├── 05_catalan.cpp
│   ├── 06_inclusion_exclusion.cpp
│   ├── 07_derangement.cpp
│   ├── 08_harmonic.cpp
│   └── 09_euler_phi.cpp
│
├── ch16_two_pointers/         ← 第16章 双指针高阶
│   ├── 01_three_sum.cpp
│   └── 02_four_sum.cpp
│
├── ch17_binary_answer/        ← 第17章 二分答案
│   ├── 01_wood_cutting.cpp
│   ├── 02_factory_scheduling.cpp
│   └── 03_fast_power.cpp
│
├── ch18_sliding_window/       ← 第18章 滑动窗口
│   ├── 01_signal_dedup.cpp
│   ├── 02_sensor_peak.cpp
│   └── 03_gene_locate.cpp
│
├── ch19_backtracking/         ← 第19章 回溯算法
│   ├── 01_permutation.cpp
│   ├── 02_subsets.cpp
│   ├── 03_combination_sum.cpp
│   ├── 04_combination_precompute.cpp
│   └── 05_pascal_triangle.cpp
│
├── ch20_advanced_dp/          ← 第20章 高阶DP
│   ├── 01_knapsack01.cpp
│   ├── 02_knapsack01_optimized.cpp
│   └── 03_tree_dp_bonus.cpp
│
├── ch21_comprehensive/        ← 第21章 综合拆解
│   ├── 01~02_skyline_water.cpp (前缀max/双指针两种解法)
│   └── 03~04_command_validate.cpp (栈/DP两种解法)
│
├── ch26_cross_technique/      ← 第26章 跨技巧综合
│   ├── 01_matrix_path.cpp
│   └── 02_task_scheduling.cpp
│
├── ch27_mock_interview/       ← 第27章 面试模拟
│   ├── 01_kth_smallest_matrix.cpp
│   ├── 02_permute_unique.cpp
│   ├── 03_lis_binary.cpp
│   ├── 04_max_rectangle.cpp
│   ├── 05_wildcard_match.cpp
│   └── 06_merge_k_lists.cpp
│
├── ch28_engineering/          ← 第28章 工程迁移
│   ├── 01_pointcloud_bfs.cpp
│   └── 02_coverage_map.cpp
│
└── appendix_math/             ← 附录 竞赛数学
    ├── 01_stirling.cpp
    ├── 02_mobius.cpp
    ├── 03_crt.cpp
    └── 04_lucas.cpp
```

---

## 学习路线建议

按照五阶闭环学习法，推荐以下刷题顺序：

### 第一阶段：启蒙（第一卷）
1. `ch01_algorithm_basics/` — 两数之和（暴力→哈希优化）
2. `ch02_complexity/` — 理解 O(1) vs O(n) 的差距
3. `ch03_containers/` — vector、unordered_map、string 基本操作

### 第二阶段：强化（第二卷）
4. `ch04_arrays/` — 数组最值 + 去重
5. `ch05_hashing/` — 哈希表实战
6. `ch06_strings/` — 回文串
7. `ch07_sorting/` — 冒泡排序 + 快速排序
8. `ch08_binary_search/` — 二分查找模板
9. `ch09_two_pointers/` — 双指针基础
10. `ch10_prefix_sum/` — 前缀和预处理
11. `ch11_stack_queue/` — 有效括号
12. `ch12_binary_tree/` — 前中后序遍历
13. `ch13_dfs_bfs/` — DFS/BFS 两大搜索
14. `ch14_greedy/` — 贪心两大模式
15. `ch15_dp_intro/` — DP五步法入门

### 第三阶段：进阶（第三卷）
16. `ch16_two_pointers/` — 高阶双指针
17. `ch17_binary_answer/` — 二分答案
18. `ch18_sliding_window/` — 滑动窗口
19. `ch19_backtracking/` — 回溯三大问题
20. `ch20_advanced_dp/` — 背包DP + 树形DP
21. `ch21_comprehensive/` — 综合真题

### 第四阶段：升华（第五卷）
22. `ch26_cross_technique/` — 跨技巧综合
23. `ch27_mock_interview/` — 限时面试模拟
24. `ch28_engineering/` — 工程实战

### 附录（竞赛进阶）
25. `appendix_math/` — 竞赛级数学公式

---

## 代码规范

所有代码文件遵循统一规范（详见 `templates/template_reference.md`）：

| 规范项 | 统一写法 |
|--------|---------|
| 数组变量 | `nums`, `arr` |
| 双指针 | `l`(左), `r`(右) |
| 结果变量 | `res`, `ans` |
| 取模常量 | `MOD = 1e9 + 7` |
| DP 数组 | `dp` |
| 快速幂 | `power(base, exp, mod)` |

---

## 与书稿的对应关系

| 书稿章节 | 代码目录 | 文件数 |
|---------|---------|--------|
| 第1章 算法基础 | `ch01_algorithm_basics/` | 2 |
| 第2章 复杂度 | `ch02_complexity/` | 1 |
| 第3章 容器 | `ch03_containers/` | 3 |
| 第4章 数组 | `ch04_arrays/` | 2 |
| 第5章 哈希 | `ch05_hashing/` | 1 |
| 第6章 字符串 | `ch06_strings/` | 1 |
| 第7章 排序 | `ch07_sorting/` | 2 |
| 第8章 二分查找 | `ch08_binary_search/` | 1 |
| 第9章 双指针基础 | `ch09_two_pointers/` | 1 |
| 第10章 前缀和 | `ch10_prefix_sum/` | 1 |
| 第11章 栈与队列 | `ch11_stack_queue/` | 1 |
| 第12章 二叉树 | `ch12_binary_tree/` | 1 |
| 第13章 DFS/BFS | `ch13_dfs_bfs/` | 2 |
| 第14章 贪心 | `ch14_greedy/` | 2 |
| 第15章 DP入门 | `ch15_dp_intro/` | 9 |
| 第16章 双指针高阶 | `ch16_two_pointers/` | 2 |
| 第17章 二分答案 | `ch17_binary_answer/` | 3 |
| 第18章 滑动窗口 | `ch18_sliding_window/` | 3 |
| 第19章 回溯 | `ch19_backtracking/` | 5 |
| 第20章 高阶DP | `ch20_advanced_dp/` | 3 |
| 第21章 综合 | `ch21_comprehensive/` | 4 |
| 第26章 跨技巧 | `ch26_cross_technique/` | 2 |
| 第27章 面试 | `ch27_mock_interview/` | 6 |
| 第28章 工程 | `ch28_engineering/` | 2 |
| 附录 | `appendix_math/` | 4 |
| **总计** | **25章 + 附录** | **64** |

---

*随书稿同步更新 · 2026年6月*
