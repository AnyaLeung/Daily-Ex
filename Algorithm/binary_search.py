#有序列表
def binary_search(list, item):
    #all use index
    high = len(list) - 1 #last number in list
    low = list[0]

    while guess != list[mitten]:
        mitten = (high + low) / 2
        if list[mitten] > guess:
            high = mitten
        if list[mitten] < guess:
            low = mitten

    return guess
