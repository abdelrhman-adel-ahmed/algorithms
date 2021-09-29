def reverse(x):
    range_ = range(-(2 ** 31), 2 ** 31 - 1)
    y = str(abs(x))
    if x == 0 or x not in range_:
        x = 0
    x = int("-" + y[::-1]) if "-" in str(x) else int(y[::-1])
    return x if x in range_ else 0
