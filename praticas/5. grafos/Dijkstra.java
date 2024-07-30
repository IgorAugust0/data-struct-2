import java.util.*;

public class Dijkstra {
    static final int INF = Integer.MAX_VALUE; // infinite distance

    static void dijkstra(int[][] graph, int source) {
        int n = graph.length;
        int[] distance = new int[n]; // distance[i] will hold the shortest distance from source to i
        boolean[] visited = new boolean[n]; // visited[i] will be true if vertex i is included in shortest path tree

        // initialize distances and visited arrays
        for (int i = 0; i < n; i++) {
            distance[i] = INF;
            visited[i] = false;
        }

        // distance from source to itself is always 0
        distance[source] = 0;

        // find shortest path for all vertices
        for (int i = 0; i < n - 1; i++) {
            // pick the minimum distance vertex from the set of vertices not yet processed
            int u = minDistance(distance, visited);

            // mark the picked vertex as processed
            visited[u] = true;

            // update distance values of the adjacent vertices of the picked vertex
            for (int v = 0; v < n; v++) {
                // update distance[v] only if it is not in visited, there is an edge from u to
                // v, and total weight of path from source to v through u is smaller than
                // current value of distance[v]
                if (!visited[v] && graph[u][v] != 0 && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                }
            }
        }

        // print the shortest distances
        System.out.println("Vertex\tDistance from source");
        for (int i = 0; i < n; i++) {
            System.out.println(i + "\t\t" + distance[i]);
        }
    }

    // utility function to find the vertex with minimum distance value, from the set
    // of vertices not yet included in shortest path tree
    static int minDistance(int[] distance, boolean[] visited) {
        int min = INF;
        int minIndex = -1;

        for (int i = 0; i < distance.length; i++) {
            if (!visited[i] && distance[i] <= min) {
                min = distance[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            // read the number of vertices and edges
            System.out.print("Enter the number of vertices: ");
            int n = sc.nextInt();
            System.out.print("Enter the number of edges: ");
            int m = sc.nextInt();
            // sc.close();

            // create a graph with n vertices and m edges
            int[][] graph = new int[n][n];

            // read the edges and add them to the graph
            for (int i = 0; i < m; i++) {
                System.out.print("Enter the start vertex of edge " + (i + 1) + ": ");
                int u = sc.nextInt();
                System.out.print("Enter the end vertex of edge " + (i + 1) + ": ");
                int v = sc.nextInt();
                System.out.print("Enter the weight of edge " + (i + 1) + ": ");
                int w = sc.nextInt();
                graph[u][v] = w;
            }
        }
    }
}

/*public static void main(String[] args) {
        // Test the algorithm with a simple graph
        int[][] graph = {
                { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 }
        };
        int[] dist = new int[graph.length];
        dijkstra(graph, 0, dist);

        // Print the distances to all vertices
        System.out.println(Arrays.toString(dist));
    }
} */