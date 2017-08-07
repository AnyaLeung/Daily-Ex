def suchen_grosst(list):
    g_index = 0
    gross = list[0]
    for i in range(len(list)):
        if list[i] > gross:
            gross = list[i]
            g_index = i
    return g_index

def selection_sort(list):
    res = []
    for i in range(len(list)):
       g = suchen_grosst(list)
       res.append(list.pop(g)) 
       #pop() method uses index, n return the num just poped
    return res

print selection_sort([3, 5, 4, 1, 10])
