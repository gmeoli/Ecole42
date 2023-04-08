public class Program {
	public static int sumNumber(int n) {
		int somma = 0;

		somma += n % 10;
		n /= 10;
		somma += n % 10;
		n /= 10;
		somma += n % 10;
		n /= 10;
		somma += n % 10;
		n /= 10;
		somma += n % 10;
		n /= 10;
		somma += n % 10;
		n /= 10;
		return (somma);
	}
	public static void main(String[] args) {
		int num = sumNumber(479598);
		System.out.println(num);

		System.exit(0);
	}
}
