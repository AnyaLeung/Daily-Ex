from collections import deque

graph = {}
graph["you"] = ["alice", "bobo", "claire"]
graph["bobo"] = ["anuj", "peggy"]
graph["alice"] = ["tom"]

search_queue = deque()
search_queue += graph["you"]
