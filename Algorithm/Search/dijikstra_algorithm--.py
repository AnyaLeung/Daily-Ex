graph = {}

graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2
# like a two-dimen array
# print graph["start"].keys()

graph["a"] = {}
graph["a"]["fin"] = 1

graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["fin"] = 5

graph["fin"] = {} #end have no neighbor

infinity = float("inf") #for infinit
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity
# record the costs, that is, how much costs from start to this node

parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None
# record parent node

processed = [] #record used node

def find_smallest_node(costs, processed):
    min = "a"
    for i in costs.keys() and i not in processed:
        if costs[i] < costs[min]:
            min = i
    return min 
# return index

def dijikstra(graph, costs, parents, processed):
    while not processed == costs.keys():  #haven't search all node
        node_smallest = find_smallest_node(graph[start]) #find shortest node
        for i in graph[node_smallest].keys(): #all neighbor recursion
            if graph[node_smallest][i] < costs[i]: #if smaller than present
                costs[i] = graph[node_smallest][i] #replace the value #wrong
                parents[i] = node_smallest #record parent
