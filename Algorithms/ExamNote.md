## 01背包
```py
def test_2_wei_bag_problem1(weight, value, bagweight):
    # 二维数组
    dp = [[0] * (bagweight + 1) for _ in range(len(weight))]

    # 初始化
    for j in range(weight[0], bagweight + 1):
        dp[0][j] = value[0]

    # weight数组的大小就是物品个数
    for i in range(1, len(weight)):  # 遍历物品
        for j in range(bagweight + 1):  # 遍历背包容量
            if j < weight[i]:
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])

    return dp[len(weight) - 1][bagweight]

if __name__ == "__main__":

    weight = [1, 3, 4]
    value = [15, 20, 30]
    bagweight = 4

    result = test_2_wei_bag_problem1(weight, value, bagweight)
    print(result)
```

## 烂橘子
```py
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        rotten = {(i, j) for i in range(row) for j in range(col) if grid[i][j] == 2} # 腐烂集合
        fresh = {(i, j) for i in range(row) for j in range(col) if grid[i][j] == 1}  # 新鲜集合
        time = 0
        while fresh:
            if not rotten: return -1
            rotten = {(i + di, j + dj) for i, j in rotten for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)] if (i + di, j + dj) in fresh} # 即将腐烂的如果在新鲜的集合中，就将它腐烂
            fresh -= rotten # 剔除腐烂的
            time += 1
        return time
```

