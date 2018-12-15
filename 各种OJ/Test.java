import java.util.*;
import java.math.*;

class A{
	static{
		System.out.print("1");
	}
	public static final int a_number = 2;
	public A(){
		System.out.print("3");
	}
}

class B extends A{
	static{
		System.out.print("4");
	}
	public static final int b_number = 5;
	public B(){
		System.out.print("6");
	}
}

public class Test{
	public static void main(String[] args)
	{
		System.out.print(A.a_number);
		System.out.print(B.b_number);
		B b = new B();
	}
}