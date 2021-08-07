import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.OutputStream;

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

class Solution {
    static final int L = 300000 + 5;
    static int[] up = new int[L];
    static int[] avail = new int[L];

    static int find(int v) {
        if (up[v] < 0) {
            return v;
        } else {
            up[v] = find(up[v]);
            return up[v];
        }
    }

    static void union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (up[b] < up[a]) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        avail[a] += avail[b];
        up[a] --;
        up[b] = a;
    }

    public static void main(String[] args) throws Exception {
        Kattio io = new Kattio(System.in, System.out);

        int n = io.getInt();
        int l = io.getInt();
        
        // Initialize
        for (int i = 1; i <= l; ++ i) {
            up[i] = -1;
            avail[i] = 1;
        }

        for (int i = 0; i < n; ++ i) {
            int a = io.getInt();
            int b = io.getInt();

            union(a, b);
            int root = find(a);
            if (avail[root] > 0) {
                avail[root] --;
                io.println("LADICA");
            } else {
                io.println("SMECE");
            }            
        }

        io.close();
    }
}