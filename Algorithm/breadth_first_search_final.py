from collections import deque

# edited: 增加一个字典查重复

def is_seller(name):
    return name[-1] == 'm' #last letter of name is, then true

def breadth_first_search(graph, start):
    search_queue = deque() #create a *double-end* deque (...?)
    search_queue += graph["you"] #add all ur neighbors into queue

    searched = {}
    while search_queue: #not empty
        person = search_queue.popleft() 
        if not searched[person]: 
            #if haven't searched, add into the dict and check
            searched[person] = True
            if is_seller(person): #符合条件
                return True
            else: #否则把它的邻居都加进去
                search_queue += graph[person]
    return False #关系网络里没有

breadth_first_search(graph, "you")


