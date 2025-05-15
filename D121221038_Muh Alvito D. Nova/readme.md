

# Muh Alvito Dean Nova 

***

***
**NIM : D121221038**   
**Topics: Graph, Dijkstra's Algorithm**  
**Difficulty: Medium**
***

<p style="font-size:22px; font-weight:bold; margin-bottom:6px;"> Short Description:</p>
This implementation showcases the use of Graph data structures and Dijkstra’s Algorithm to solve shortest path problems in a weighted network. By modeling real-world scenarios such as urban transport systems, nodes represent locations (e.g., stations), edges represent connections, and weights indicate travel time or cost. Dijkstra’s algorithm efficiently finds the minimum-cost paths from a starting node to all others using a priority queue, making it a foundational technique in routing, navigation, and network optimization.


***
<p style="font-size:22px; font-weight:bold; margin-bottom:6px;"> Approach:</p>

  - Utilizes a **priority queue (min-heap)** to select the next node with the smallest known distance.
  - Maintains a dictionary to track the shortest known distance to each node.
  - Updates neighbor distances if a shorter path is discovered.

***
<p style="font-size:22px; font-weight:bold; margin-bottom:6px;">Complexity:</p>

* **Time Complexity: O(N)**
* **Space Complexity: O(N)**

