import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

class Solution {

    static int[] up = new int[1000000];

    static void union(int a, int b) {
        // Make sure a is from the bigger set
        if (up[b] < up[a]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        up[a] --; 
        up[b] = a; // Actually merge b into a
    }

    static int find(int v) {
        if (up[v] < 0) {
            return v;
        }
        up[v] = find(up[v]);
        return up[v];
    }

    public static void main(String[] args) {
        Kattio io = new Kattio(System.in, System.out);
        

        int n = io.getInt();
        int q = io.getInt();
        
        for (int i = 0; i < n; ++ i) {
            up[i] = -1;
        }
        
        for (int i = 0; i < q; i ++) {
            String type = io.getWord();
            int a = find(io.getInt());
            int b = find(io.getInt());

            if (type.equals("?")) {
                if (a == b) {
                    io.println("yes");
                } else {
                    io.println("no");
                }
            } else {
                if (a != b) {
                    union(a, b);
                }
            }
        }
        io.close();
    }
}

class Kattio extends PrintWriter {
    public Kattio(InputStream i) {
        super(new BufferedOutputStream(System.out));
        r = new BufferedReader(new InputStreamReader(i));
    }
    public Kattio(InputStream i, OutputStream o) {
        super(new BufferedOutputStream(o));
        r = new BufferedReader(new InputStreamReader(i));
    }

    public boolean hasMoreTokens() {
        return peekToken() != null;
    }

    public int getInt() {
        return Integer.parseInt(nextToken());
    }

    public double getDouble() {
        return Double.parseDouble(nextToken());
    }

    public long getLong() {
        return Long.parseLong(nextToken());
    }

    public String getWord() {
        return nextToken();
    }



    private BufferedReader r;
    private String line;
    private StringTokenizer st;
    private String token;

    private String peekToken() {
        if (token == null)
            try {
                while (st == null || !st.hasMoreTokens()) {
                    line = r.readLine();
                    if (line == null) return null;
                    st = new StringTokenizer(line);
                }
                token = st.nextToken();
            } catch (IOException e) { }
        return token;
    }

    private String nextToken() {
        String ans = peekToken();
        token = null;
        return ans;
    }
}