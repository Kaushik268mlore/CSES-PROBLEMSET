import java.util.*;
import java.io.*;

public class TwoSets {

  static class FastIO extends PrintWriter {
    private InputStream stream;
    private byte[] buf = new byte[1 << 16];
    private int curChar, numChars;

    // standard input
    public FastIO() {
      this(System.in, System.out);
    }

    public FastIO(InputStream i, OutputStream o) {
      super(o);
      stream = i;
    }

    // file input
    public FastIO(String i, String o) throws IOException {
      super(new FileWriter(o));
      stream = new FileInputStream(i);
    }

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
    // FastScanner sc = new FastScanner();
    // Scanner sc = new Scanner(System.in);
    FastIO sc = new FastIO();

    // CODE START

    int n = sc.nextInt();

    StringBuilder sb1 = new StringBuilder(n / 2 + 1);
    StringBuilder sb2 = new StringBuilder(n / 2);

    if (n % 4 == 0) {
      sb1.append("1 4 ");
      sb2.append("2 3 ");
      helper(sb1, sb2, 5, n);
    } else if (n < 3 || (n + 1) % 4 != 0) {
      System.out.println("NO");
      sc.close();
      return;
    } else {
      sb1.append("1 2 ");
      sb2.append("3 ");
      helper(sb1, sb2, 4, n);
    }

    System.out.print("YES\n" + ((n + 1) / 2) + "\n" + sb1 + "\n" + (n / 2) + "\n" + sb2);

    // CODE END

    sc.close();
  }

  private static void helper(StringBuilder sb1, StringBuilder sb2, int i, int n) {
    for (; i < n - 2; i += 4) {
      sb1.append(i + " " + (i + 3) + " ");
      sb2.append((i + 1) + " " + (i + 2) + " ");
    }
  }
}