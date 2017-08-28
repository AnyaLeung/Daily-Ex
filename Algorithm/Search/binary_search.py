def binary_search(list, aim):
    low = 0
    high = len(list) - 1

    while low <= high:
        mid = (low + high) / 2
        guess = list[mid]
        if guess == aim:
            return mid
        if guess < aim:
            low = mid + 1
        if guess > aim:
            high = mid - 1
    return None

# 能搜索所有的元素，包括头尾
