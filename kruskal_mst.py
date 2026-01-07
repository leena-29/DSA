
class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u == root_v:
            return False

        if self.rank[root_u] < self.rank[root_v]:
            self.parent[root_u] = root_v
        elif self.rank[root_u] > self.rank[root_v]:
            self.parent[root_v] = root_u
        else:
            self.parent[root_v] = root_u
            self.rank[root_u] += 1
        return True


def kruskal(n, edges):
    ds = DisjointSet(n)
    mst = []
    edges.sort(key=lambda x: x[2])  # Sort by weight

    for u, v, weight in edges:
        if ds.union(u, v):
            mst.append((u, v, weight))

    return mst


# Example usage:
vertices = 4
edges = [
    (0, 1, 10),
    (0, 2, 6),
    (0, 3, 5),
    (1, 3, 15),
    (2, 3, 4)
]

result = kruskal(vertices, edges)
print("Minimum Spanning Tree edges:")
for u, v, weight in result:
    print(f"{u} -- {v} == {weight}")
