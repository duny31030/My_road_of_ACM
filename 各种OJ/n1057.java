package 大数;

import java.util.*;
import java.math.*;

public class n1057 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger a,b,c,i;
		a = in.nextBigInteger();
		c = b = new BigInteger("1");
		for(i = new BigInteger("1");i.compareTo(a) <= 0;i = i.add(c))
		{
			b = b.multiply(i);
		}
		System.out.println(b);
	}

}
