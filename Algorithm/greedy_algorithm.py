#   approximatino algorithm，
#
#   用接近的结果解决复杂问题，快
#
#   基本思想：每一步都是最优解
#
#   use set

aiming = set(["mt", "wa", "or", "id", "nv", "ut", "ca", "az"])

stations = {}
stations["kone"] = set(["id", "nv", "ut"])
stations["ktwo"] = set(["wa", "id", "mt"])
stations["kthree"] = set(["or", "nv", "ca"])
stations["kfour"] = set(["nv", "ut"])
stations["kfive"] = set(["ca", "az"])

final = set()

def greedy_algorithm(aiming, stations, final):
    while aiming:
        best = None #define variable inside loop, remember?
        best_cover = set()
        for sta, states_of_station in stations.items():
            cover = states_of_station & aiming
            if len(cover) > len(best_cover):
                best = sta
                best_cover = cover
        final.add(best)
        aiming -= best_cover

greedy_algorithm(aiming, stations, final)
print(final)
