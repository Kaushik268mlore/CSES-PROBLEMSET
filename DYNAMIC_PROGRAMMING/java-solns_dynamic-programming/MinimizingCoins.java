import java.util.*;
import java.io.*;

public class MinimizingCoins {

  static class FastIO {
    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
    private int curChar, numChars;

    // standard input
    public FastIO() {
      this(System.in);
    }

    public FastIO(InputStream i) {
      stream = i;
    }

    // // file input
    // public FastIO(String i, String o) throws IOException {
    // super(new FileWriter(o));
    // stream = new FileInputStream(i);
    // }

    // throws InputMismatchException() if previously detected end of file
    private int nextByte() {
      if (numChars == -1)
        throw new InputMismatchException();
      if (curChar >= numChars) {
        curChar = 0;
        try {
          numChars = stream.read(buf);
        } catch (IOException e) {
          throw new InputMismatchException();
        }
        if (numChars == -1)
          return -1; // end of file
      }
      return buf[curChar++];
    }

    // to read in entire lines, replace c <= ' '
    // with a function that checks whether c is a line break
    public String next() {
      int c;
      do {
        c = nextByte();
      } while (c <= ' ');
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = nextByte();
      } while (c > ' ');
      return res.toString();
    }

    public String nextLine() {
      int c;
      do {
        c = nextByte();
      } while (c < '\n');
      StringBuilder res = new StringBuilder();
      do {
        res.appendCodePoint(c);
        c = nextByte();
      } while (c > '\n');
      return res.toString();
    }

    public int nextInt() {
      int c;
      do {
        c = nextByte();
      } while (c <= ' ');
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = nextByte();
      }
      int res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res = 10 * res + c - '0';
        c = nextByte();
      } while (c > ' ');
      return res * sgn;
    }

    public long nextLong() {
      int c;
      do {
        c = nextByte();
      } while (c <= ' ');
      int sgn = 1;
      if (c == '-') {
        sgn = -1;
        c = nextByte();
      }
      long res = 0;
      do {
        if (c < '0' || c > '9')
          throw new InputMismatchException();
        res = 10 * res + c - '0';
        c = nextByte();
      } while (c > ' ');
      return res * sgn;
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }
  }

  public static void main(String args[]) {
    // Scanner sc = new Scanner(System.in);
    FastIO sc = new FastIO();
    int MOD = 1000000007;

    // CODE START

    int n = sc.nextInt();
    int x = sc.nextInt();
    int[] dp = new int[x + 1];
    Arrays.fill(dp, 9999999);
    int coins[] = new int[n];
    for (int i = 0; i < n; i++) {
      coins[i] = sc.nextInt();
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= x; j++) {
        if (j - coins[i] >= 0) {
          dp[j] = Math.min(dp[j], dp[j - coins[i]] + 1);
        }
      }
    }
    System.out.println(dp[x] == 9999999 ? -1 : dp[x]);

    // CODE END
  }
}