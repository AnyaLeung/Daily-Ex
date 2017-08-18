from collections import deque

def is_seller(name):
    return name[-1] == 'm' #last letter of name is, then true

def breadth_first_search(dict, start):
    search_queue = deque()
    search_queue += dict[start] #add all ur friends

    if search_queue: #not empty
        person = search_queue.popleft()

        if is_seller(person):
            print "ok"
            print person + "is found!"
            return True
        else:
            search_queue += dict[person]
    return False

dict = {}
dict["anya"] = ["leslie", "lily", "manm"]
dict["leslie"] = ["alie", "fam"]

breadth_first_search(dict, "anya")
