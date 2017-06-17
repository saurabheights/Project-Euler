import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by SaurabhKhanduja on 17/06/17.
 */
class LargeSum { // Rename file to LargeSum.java before compiling.
    public static void main(String[] args) {
        int t;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        sc.nextLine();
        BigInteger sum = new BigInteger("0");
        while(t > 0) {
            String line= sc.nextLine();
            sum = sum.add(new BigInteger(line));
            t--;
        }
        while(sum.compareTo(new BigInteger("10000000000")) > 0) {
            sum = sum.divide(new BigInteger("10"));
        }
        System.out.println(sum);
    }
}