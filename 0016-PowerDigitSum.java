import java.io.*;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Created by SaurabhKhanduja on 17/06/17.
 */
class LargeSum {

    static class FastScanner {
        static BufferedReader br;
        static StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDoulbe() {
            return Double.parseDouble(next());
        }
    }

    private static FastScanner newInput() throws IOException {
        if (System.getProperty("JUDGE") != null) {
            return new FastScanner(new File("A-large.in"));
        } else {
            return new FastScanner(System.in);
        }
    }

    private static PrintWriter newOutput() throws IOException {
        if (System.getProperty("JUDGE") != null) {
            return new PrintWriter("A-large.out");
        } else {
            return new PrintWriter(System.out);
        }
    }

    public static void main(String[] args) throws IOException {
        int MAX_POWER = 10000;
        FastScanner in = newInput();
        PrintWriter out = newOutput();
        int t = in.nextInt();
        BigInteger[] powerOfTwo = new BigInteger[MAX_POWER + 1];
        BigInteger two = new BigInteger("2");
        powerOfTwo[0] = new BigInteger("1");
        for (int i = 1; i <= MAX_POWER; i++) {
            powerOfTwo[i] = powerOfTwo[i-1].multiply(two);
        }
        while (t > 0) {
            int N = in.nextInt();
            String digits = powerOfTwo[N].toString(10);
            int sum = 0;
            for (int j = 0; j < digits.length(); j++) {
                sum += (int) (digits.charAt(j) - '0');
            }
            out.println(sum);
            t--;
        }
        out.flush();
    }
}
