#three dict must refer to all nodes
infinit = float("inf")
graph = {}

graph["start"] = {}
graph["start"]["a"] = 5
graph["start"]["b"] = 2

graph["a"] = {}
graph["a"]["c"] = 4
graph["a"]["d"] = 2

graph["b"] = {}
graph["b"]["a"] = 8
graph["b"]["d"] = 7

graph["c"] = {}
graph["c"]["end"] = 3
graph["c"]["d"] = 6

graph["d"] = {}
graph["d"]["end"] = 1

graph["end"] = {}
#must write!!! but why...?

#
costs = {}
costs["a"] = 5
costs["b"] = 2
costs["c"] = infinit
costs["d"] = infinit
costs["end"] = infinit
#contains all nodes

#
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["c"] = None
parents["d"] = None
parents["end"] = None
#contains all nodes

processed = []

def find_lowest_cost(costs):
    lowest_node = None
    lowest_cost = infinit
    for node in costs : 
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_node = node
            lowest_cost = cost
    return lowest_node

def dijikstar(graph, costs, parents, processed):
    node = find_lowest_cost(costs) 

    while not node == None:
        cost = costs[node]
        neighbors = graph[node]

        for i in neighbors.keys():
            new_cost = cost + neighbors[i] 
            #neighbors[i] = graph[node][i]!!! ATTENTION
            if new_cost < costs[i]:
                costs[i] =  new_cost
                parents[i] = node
        processed.append(node)
        node = find_lowest_cost(costs)


def track_back():
    pre = "end" 
    trace =  []
    while not pre == "start":
       trace.append(pre) 
       pre = parents[pre]
    trace.append("start")
    trace.reverse()
    return trace

dijikstar(graph, costs, parents, processed)
print(costs["end"])

track = []
track = track_back()
print(track)
