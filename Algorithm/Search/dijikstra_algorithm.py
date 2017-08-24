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

def find_smallest_node(costs):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in costs:
        cost = costs[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node
# return index

def dijikstra(graph, costs, parents, processed):
    node = find_smallest_node(costs)

    while not node == None:
        cost = costs[node]
        neighbors = graph[node]

        for i in neighbors.keys(): #all neighbor recursion
            new_cost = cost + neighbors[i]
            if new_cost < costs[i]: #if smaller than present
                costs[i] = new_cost #replace the value #wrong
                parents[i] = node #record parent
        processed.append(node)
        node = find_smallest_node(costs) 
            
dijikstra(graph, costs, parents, processed)
print(costs["fin"])
