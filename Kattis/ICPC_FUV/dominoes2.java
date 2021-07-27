import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class dominoes2 {
    private static ArrayList<ArrayList<Integer>> adj;
    private static ArrayList<Boolean> visited;
    private static Queue<Integer> queue;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num_tests = scanner.nextInt();

        for (int test = 0; test < num_tests; ++ test) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int l = scanner.nextInt();

            // Reset arrays
            adj = new ArrayList<>();
            visited = new ArrayList<>();
            for (int i = 0; i < n; ++ i) {
                adj.add(new ArrayList<>());
                visited.add(false);
            }
            
            // Read edges
            for (int i = 0; i < m; ++ i) {
                int a = scanner.nextInt();
                int b = scanner.nextInt();
                a --; b --;

                adj.get(a).add(b);
            }
            
            // Initialize BFS
            queue = new LinkedList<>();
            for (int i = 0; i < l; ++ i) {
                int node = scanner.nextInt();
                node --;
                if (!visited.get(node)) { // In case a domino is knocked twice
                    queue.add(node);
                    visited.set(node, true);
                }
            }
            int count_fall = queue.size();
            
            // Run the BFS!
            while (!queue.isEmpty()) {
                int node = queue.poll();
                for (int neighbor : adj.get(node)) {
                    if (!visited.get(neighbor)) {
                        visited.set(neighbor, true);
                        queue.add(neighbor);
                        count_fall ++;
                    }
                }
            }

            System.out.println(count_fall);
        }
    }
}
