package 大数;

import java.math.BigInteger;
import java.util.Scanner;

public class n1029 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger a = in.nextBigInteger();
		BigInteger b = in.nextBigInteger();
		System.out.println(a.divide(b));
		System.out.println(a.mod(b));
	}

}
