package 大数;

import java.util.*;
import java.math.*;

public class n1059 {

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
		/*
		String pr = b.toString();
		int l = pr.length();
		int temp = l%1000;
		if(l%1000 == 0)
			l = l/1000;
		else 
			l = l/1000+1;
		
		for(int tmp = 0;tmp < l;tmp++)
		{
			if(tmp != l-1)
			{
				char[] prr = new char[1010];
				int st = tmp*1000;
				pr.getChars(st, st+1000, prr, 0);
				System.out.println(prr);
			}
			else 
			{
				char[] prr = new char[1010];
				int st = tmp*1000;
				pr.getChars(st, st+temp, prr, 0);
				System.out.println(prr);
			}
		}
		*/
	}
}
