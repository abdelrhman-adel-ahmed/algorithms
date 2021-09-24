#brute force approach o(n^2)
numbers = [1, 2, 3, 4, 4, 9, 56, 90]
target = 8
len_list = len(numbers)
result = []
flage = False
for i in range(len_list):
    for j in range(i + 1, len_list):
        if flage:
            continue
        if numbers[i] + numbers[j] == target:
            result.append(i + 1)
            result.append(j + 1)
            break
        if numbers[i] + numbers[j] > target:
            numbers = numbers[:j]
            len_list = len(numbers)
            flage = True
            continue
    flage = False

print(result)
