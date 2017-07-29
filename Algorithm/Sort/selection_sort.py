anfang = 0

def suchen_grosst(list, anfang=0):
    gross = list[m]
    for i in len(list)-1:
        if list[i] > gross:
            list[i], gross = gross, list[i]

def selection_sort(list):
    
