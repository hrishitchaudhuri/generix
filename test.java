class A {
	private int a = 10;
	private int b = 20;

	public void showInts() {
		System.out.println(a + ", " + b);
	}
}

class B extends A {
	private int a = 30;
	private int b = 40;

	public void showInts() {
		super.showInts();
	}
}

public class test {
	public static void main(String[] args) {
		B b = new B();

		b.showInts();
	}
}
