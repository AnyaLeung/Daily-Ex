def bubble_sort(list):
    for start in range(0, len(list)):
        for item in range(start): #!
            if list[item] > list[item+1]:
                list[item+1], list[item] = list[item], list[item+1]
