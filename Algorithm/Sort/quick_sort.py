def quick_sort(list):
    if len(list) < 2:
        return list #one element
    else:
        pivot = list[0]
        klein = [i for i in list[1:] if i<= pivot]
        gross = [i for i in list[1:] if i > pivot]

        return quick_sort(klein) + [pivot] + quick_sort(gross)

#base line condition: len(list/array) is empty OR one element
#pivot & partitioning

print quick_sort([6, 5, 4, 3, 2, 1])
