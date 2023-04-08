import java.util.Scanner;

public class Program {
	public static int isPrime(int sqrt, int iter) {
		int temp = 0;

		for (int i = 2; i <= sqrt; i++) {
			iter++;
			if (temp % i == 0)
				return 1;
			}
		return 0;
	}
	public static void main(String[] args) {
		
		int temp = 0, iter = 0, sqrt = 0, j = 1;

		while (true) {
			Scanner scanner = new Scanner(System.in);
			int	input = scanner.nextInt();

			if (input == 42) {
				System.out.println("Count of coffee-request - " + iter);
				scanner.close();
				System.exit(0);
			}

			if (input <= 1) {
				System.err.println("IllegalArgument");
				scanner.close();
				System.exit(-1);
			}
			
			while (input > 0) {
				temp += input % 10;
				input /= 10;
			}

			while (j < temp) {
				if (j * j == temp) {
					sqrt = j;
					break;
				}
				if (j * j < temp)
					sqrt = j;
				else
					break;
				j++;
			}

			iter += isPrime(sqrt, iter);
		}
	}
}
