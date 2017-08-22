def binary_search_recursion(list, aim, low=0, high=None):
    high = len(list) - 1
    middle = (high + low) // 2
    guess = list[middle]
    
    if guess == aim:
        return middle
    elif guess > aim:
        low = middle + 1
        return binary_search_recursion(list, aim, low, high)
    elif guess < aim:
        high = middle - 1
        return binary_search_recursion(list, aim, low, high)
    elif low == high:
        return false

print(binary_search_recursion([1, 2, 3, 4, 5], 4))
# To be rewrite...
#https://stackoverflow.com/questions/19989910/recursion-binary-search-python
#https://docs.python.org/2/library/bisect.html
