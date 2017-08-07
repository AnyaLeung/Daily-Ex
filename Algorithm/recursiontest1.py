anfang = 0
def sum(list, res):
    if len(list) == 0:
        return res
    else:
        res += list[0]
        return sum(list[1 : len(list)], res)
    #为啥这里不写return就是none呢。。

list = [1, 2, 3]
res = sum(list, anfang)
print res
