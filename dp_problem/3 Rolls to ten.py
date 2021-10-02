"""
"3 Rolls to ten":
you roll fair 6-sided die three times ,if the sum of the rolls 10 or greater you win 
if it smaller you lose
-what the probability of wining "3 Rolls to ten"
"""

from random import randint

round = True
result = []
num_round = 10000
sum_of_rolls = 0
for i in range(num_round):
    num_of_boxes = 0
    sum_of_rolls = 0
    for i in range(3):
        num = randint(1, 6)
        sum_of_rolls += num
    if sum_of_rolls >= 10:
        result.append([i, sum_of_rolls, "win"])
    else:
        result.append([i, sum_of_rolls, "lose"])

num_of_win = 0
for item in result:
    win_or_lose = item[2]
    if win_or_lose == "win":
        num_of_win += 1


print(result)
print(f"num of wining {num_of_win}")
print(f"num of lose {num_round-num_of_win}")
print(f"probabilty of wining = {num_of_win/num_round}")
