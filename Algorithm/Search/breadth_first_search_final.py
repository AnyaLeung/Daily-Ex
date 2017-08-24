from collections import deque

# edited: 增加一个字典查重复

def is_seller(name):
    return name[-1] == 'm' #last letter of name is, then true

def breadth_first_search(graph, start):
    search_queue = deque() 
    search_queue += graph[start] 

    searched = {} #查重的字典
    count = 0
    while search_queue:
        person = search_queue.popleft() 

        #查重复
        if not searched.get(person): 
            searched[person] = True
        #查重复

            if is_seller(person): #符合条件
                return True
            else: #否则把它的邻居都加进去
                search_queue += graph[person]
    return False 
