from collections import Counter

nums = [6, 5, 5]

c = Counter(nums)
list_len=len(nums)
for key ,value in c.items():
    if value > list_len/2:
        print(key)
