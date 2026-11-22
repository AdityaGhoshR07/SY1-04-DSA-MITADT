class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adj = [[0 for _ in range(vertices)]
                    for _ in range(vertices)]
        self.visited = [False] * vertices

    def add_edge(self, source, destination):
        # Undirected graph: update both directions.
        self.adj[source][destination] = 1
        self.adj[destination][source] = 1

    def display_graph(self):
        print("\nAdjacency Matrix:")
        print("  ", *range(self.vertices))
        for i in range(self.vertices):
            print(i, self.adj[i])

    def dfs_util(self, vertex, traversal):
        self.visited[vertex] = True
        traversal.append(vertex)

        # Visit adjacent vertices in ascending order.
        for neighbour in range(self.vertices):
            if (self.adj[vertex][neighbour] == 1
                    and not self.visited[neighbour]):
                self.dfs_util(neighbour, traversal)

    def dfs(self, start_vertex):
        if start_vertex < 0 or start_vertex >= self.vertices:
            print("Invalid starting vertex.")
            return []

        self.visited = [False] * self.vertices
        traversal = []
        self.dfs_util(start_vertex, traversal)
        return traversal


def main():
    vertices = int(input("Enter number of vertices: "))
    if vertices <= 0:
        print("Number of vertices must be greater than zero.")
        return

    graph = Graph(vertices)

    edges = int(input("Enter number of edges: "))
    if edges < 0:
        print("Number of edges cannot be negative.")
        return

    print("Enter each edge as source and destination (0 to",
          vertices - 1, "):")
    for i in range(edges):
        source, destination = map(
            int, input(f"Edge {i + 1}: ").split()
        )

        if (0 <= source < vertices and
                0 <= destination < vertices):
            graph.add_edge(source, destination)
        else:
            print("Invalid edge. Please enter valid vertex numbers.")
            return

    graph.display_graph()

    start = int(input("\nEnter starting vertex for DFS: "))
    traversal = graph.dfs(start)

    if traversal:
        print("DFS Traversal:", " -> ".join(map(str, traversal)))
        if len(traversal) < vertices:
            print("Unreachable vertices:",
                  *[v for v in range(vertices)
                    if v not in traversal])


if __name__ == "__main__":
    main()