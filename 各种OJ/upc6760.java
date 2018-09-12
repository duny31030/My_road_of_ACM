package 大数;

import java.util.*;
import java.math.*;

public class upc6760 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		BigInteger two,one;
		two = new BigInteger("2");
		one = new BigInteger("1");
		BigInteger a1,a2,a3,a4;
		a1 = one;
		a2 = two;
		int t,pri,tmp;
		t = in.nextInt();
		while(t != 0)
		{
			t--;
			pri = in.nextInt();
			if(pri == 1)
			{
				System.out.println("1");
			}
			else 
			{
				if(pri == 2)
				{
					System.out.println("2");
				}
				else 
				{
					a1 = one;
					a2 = two;
					for(tmp = 3;tmp <= pri;tmp++)
					{
						a3 = two.multiply(a1).add(a2).add(one);
						a1 = a2;
						a2 = a3;
					}
					System.out.println(a2);
				}
			}
		}
	}

}
