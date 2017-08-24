# rewrite dijikstra funck
# **AND find_lowest_cost func**
#
# three dict must refer to ALL NODES!!!
# haven't got --> write as None / {} / infinity

infinity = float("inf") #infinite

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

graph["fin"] = {} 
#must write !!! (but y..?


costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity
# record the costs, that is, how much costs from start to this node
# haven't got-->infinity
# MUST CONTAINS ALL NODES

parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None
# record parent node
# MUST CONTAINS ALL NODES

processed = [] #record used node

def find_lowest_cost(costs):
    lowest_cost = float("inf") #infinity
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node
# return index

def dijikstra(graph, costs, parents, processed):
    node = find_lowest_cost(costs)

    while not node == None:
        cost = costs[node]
        neighbors = graph[node]

        for i in neighbors.keys(): #all neighbor recursion
            new_cost = cost + neighbors[i]
            if new_cost < costs[i]: #if smaller than present
                costs[i] = new_cost #replace the value #wrong
                parents[i] = node 
                #record parent, child-->key, parent-->value
        processed.append(node)
        node = find_lowest_cost(costs) 


# write by me ww
track = []
def track_back_parent(parents):

    pre_node = "fin"

    while not pre_node == "start":
        track.append(pre_node)
        pre_node = parents[pre_node]
    track.append("start")
    track.reverse()
# write by me ww


dijikstra(graph, costs, parents, processed)
track_back_parent(parents)

print(track)
print(costs["fin"])
