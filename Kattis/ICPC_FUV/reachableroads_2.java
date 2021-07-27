import java.util.ArrayList;
import java.util.Scanner;

class Main {
    private static ArrayList<ArrayList<Integer>> adj;
    private static ArrayList<Boolean> visited;

    private static void dfs(int vertex) {
        visited.set(vertex, true);

        for (int neighbor : adj.get(vertex)) {
            if (!visited.get(neighbor)) {
                dfs(neighbor)
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num_testcases = scanner.nextInt();
        
        for (int test = 0; test < num_testcases; ++test) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            
            // Create adjacent list for N vertices
            adj = new ArrayList<>();
            for (int i = 0; i < n; ++ i) {
                adj.add(new ArrayList<>());
            }
            
            // Read edges
            for (int i = 0; i < m; ++ i) {
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                adj.get(a).add(b);
                adj.get(b).add(a);
            }

            // Create the visited array
            visited = new ArrayList<>();
            for (int i = 0; i < n; ++ i) {
                visited.add(false);
            }

            // Iterate through the "connected components"
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (!visited.get(i)) {
                    dfs(i);
                    count ++;
                }
            }

            System.out.println(count - 1);
        }
    }
}