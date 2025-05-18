import heapq

def dijkstra(graph, start, end):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    prev = {node: None for node in graph}
    queue = [(0, start)]

    while queue:
        curr_dist, curr_node = heapq.heappop(queue)

        if curr_node == end:
            break

        for neighbor, weight in graph[curr_node].items():
            dist = curr_dist + weight
            if dist < distances[neighbor]:
                distances[neighbor] = dist
                prev[neighbor] = curr_node
                heapq.heappush(queue, (dist, neighbor))

    # Rekonstruksi jalur
    path = []
    node = end
    while node:
        path.append(node)
        node = prev[node]
    path.reverse()

    return distances[end], path

# Contoh graf rute antar stasiun
city_map = {
    'A': {'B': 5, 'C': 10},
    'B': {'A': 5, 'C': 3, 'D': 2},
    'C': {'A': 10, 'B': 3, 'D': 1},
    'D': {'B': 2, 'C': 1, 'E': 4},
    'E': {'D': 4}
}

# Penggunaan
start = 'A'
end = 'E'
distance, path = dijkstra(city_map, start, end)

print(f"Jarak tercepat dari {start} ke {end}: {distance} menit")
print("Rute tercepat:", " -> ".join(path))
