def binary_search(list, des): #item for aiming
    high = len(list) - 1
    low = 0
    mitten = (high + low) / 2
    count = 0

    while  list[mitten] != des:
        if list[mitten] > des:
            high = mitten - 1

        if list[mitten] < des:
            low = mitten + 1
        mitten = (high + low ) / 2

    return mitten 
