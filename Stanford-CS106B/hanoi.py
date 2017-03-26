#!/urs/bin/env python3
# -*- coding: utf-8 -*-

a = raw_input("From: ")
c = raw_input("to: ")
n = int(raw_input("N: "))
b = raw_input("Transient: ")

def move(n, a, b, c):
    if n==1:
        print "%c-->%c" %(a, c)
    else:
        move(n-1, a, c, b)
        move(1, a, b, c)
        move(n-1, b, c, a)

move(n, a, b, c)
