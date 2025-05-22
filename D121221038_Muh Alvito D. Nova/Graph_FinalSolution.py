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

    path = []
    node = end
    while node:
        path.append(node)
        node = prev[node]
    path.reverse()

    return distances[end], path

# =========================
# INPUT MANUAL DARI USER
# =========================

# Contoh graph (bisa dimodifikasi atau diganti input dari user jika diinginkan)
city_map = {
    'A': {'B': 5, 'C': 10},
    'B': {'A': 5, 'C': 3, 'D': 2},
    'C': {'A': 10, 'B': 3, 'D': 1},
    'D': {'B': 2, 'C': 1, 'E': 4},
    'E': {'D': 4}
}

# Ambil input dari user
print("Stasiun yang tersedia:", ', '.join(city_map.keys()))
start = input("Masukkan stasiun awal: ").strip().upper()
end = input("Masukkan stasiun tujuan: ").strip().upper()

# Validasi input
if start not in city_map or end not in city_map:
    print("Stasiun yang dimasukkan tidak tersedia.")
else:
    distance, path = dijkstra(city_map, start, end)
    print(f"\nJarak tercepat dari {start} ke {end}: {distance} menit")
    print("Rute tercepat:", " -> ".join(path))
