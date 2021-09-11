amount = 3
coins = [2]


#the idea is if it cannot fit the value will be inf ,draw it to be clear


n = len(coins)
dp = [[float("inf") for _ in range(amount + 1)] for _ in range(n + 1)]

for i in range(n + 1):
    dp[i][0] = 0
for i in range(1, n + 1):
    for j in range(amount + 1):
        dp[i][j] = dp[i - 1][j]
        if j >= coins[i - 1]:
            dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1)

print(dp[n][amount] if dp[n][amount] != float("inf") else -1)
