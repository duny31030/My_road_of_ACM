import java.math.BigInteger;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner ss = new Scanner(System.in);
		BigInteger a = ss.nextBigInteger();
		int b = ss.nextInt();
		System.out.println(a.divide(BigInteger.valueOf(b))+" "+a.mod(BigInteger.valueOf(b)));
		ss.close();
	}

}

