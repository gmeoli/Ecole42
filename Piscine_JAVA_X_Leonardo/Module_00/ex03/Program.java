import java.util.Scanner;

public class Program {
	public static void main(String[] args) {
		Scanner	scanner = new Scanner(System.in);
		String	input;
		int		nWeek;
		long	votes;

		for (int i = 1; i < 19; i++) {
			input = scanner.nextLine();
			if (input.equals("Week ")) {
				System.out.println("Dentro Week");
				nWeek = scanner.nextInt();
				if (nWeek == i) {
					System.out.println("cewa");
				}
			}
		}
		scanner.close();
	}
}
