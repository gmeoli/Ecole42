import java.util.Scanner;

public class Program {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int	num = scanner.nextInt();
		
		if (num <= 1) {
			System.err.println("IllegalArgument");
			scanner.close();
			System.exit(-1);
		}

		int sqrt = 0, j = 1;

		while (j < num) {
			if (j * j == num) {
				sqrt = j;
				break;
			}
			if (j * j < num)
				sqrt = j;
			else
				break;
			j++;
		}

		int	iter = 0;
		boolean	isTrue = true;

		for (int i = 2; i <= sqrt + 1; i++) {
			iter++;
			if (num % i == 0) {
				isTrue = false;
				break;
			}
		}

		System.out.println(isTrue + " " + iter);

		scanner.close();
	}
}
