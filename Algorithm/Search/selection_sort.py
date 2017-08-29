def bubble_sort(list):
    res = []
    while len(list) != 0:
        for item in range(len(list)): #range(len(list))
            min_index = 0
            if list[item] < list[min_index]:
                 min_index = item
        res.append(list.pop(min_index))
    return res
