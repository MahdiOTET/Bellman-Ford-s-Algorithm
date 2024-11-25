class Edge:
    def __init__(self, src, dest, weight):
        self.src = src
        self.dest = dest
        self.weight = weight

def bellman_ford(vertices, edges, edge_list, source):
    # Step 1: Initialize distances from source to all vertices as infinity
    distance = [float('inf')] * vertices
    distance[source] = 0

    # Step 2: Relax all edges |V| - 1 times
    for _ in range(vertices - 1):
        for edge in edge_list:
            if distance[edge.src] != float('inf') and distance[edge.src] + edge.weight < distance[edge.dest]:
                distance[edge.dest] = distance[edge.src] + edge.weight

    # Step 3: Check for negative-weight cycles
    for edge in edge_list:
        if distance[edge.src] != float('inf') and distance[edge.src] + edge.weight < distance[edge.dest]:
            print("Graph contains a negative-weight cycle")
            return

    # Print the distances from source
    print("Vertex\tDistance from Source")
    for i in range(vertices):
        if distance[i] == float('inf'):
            print(f"{i}\tInfinity")
        else:
            print(f"{i}\t{distance[i]}")

# Driver code
if __name__ == "__main__":
    vertices = int(input("Enter the number of vertices: "))
    edges = int(input("Enter the number of edges: "))

    edge_list = []
    print("Enter the edges (source, destination, weight):")
    for _ in range(edges):
        src, dest, weight = map(int, input().split())
        edge_list.append(Edge(src, dest, weight))

    source = int(input("Enter the source vertex: "))
    bellman_ford(vertices, edges, edge_list, source)
