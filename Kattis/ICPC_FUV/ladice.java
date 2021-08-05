import java.util.Scanner;

class Main {
    static int[] parent = new int[300005];
    static boolean[] occupied = new boolean[300005];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int l = scanner.nextInt();

        for (int i = 0; i < l; ++ i) {
            parent[i] = -1;
            occupied[i] = false;
        }

        for (int i = 0; i < n; ++ i) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            
        }
    }
}