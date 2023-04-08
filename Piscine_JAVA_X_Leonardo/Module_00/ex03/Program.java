import java.util.Scanner;

public class Program {
	public static void main(String[] args) {
		String	str = "Ciao come stai?";

		for (int i = 1; i < 19; i++) {
			Scanner scanner = new Scanner(System.in);
			String week = scanner.nextLine();

			if (week.equals("Week " + i)) {
				// System.out.println("ok");
				for (int j = 0; j < 5; j++) {
					Scanner scanner2 = new Scanner(System.in);
					String pattern = "[0-9]*";
				}
			}
			else if (week.equals("Week " + (i > 22))) {
				System.out.println("IllegalArgument");
				scanner.close();
				System.exit(-1);
			}
			else
				continue;
		}
	}
}