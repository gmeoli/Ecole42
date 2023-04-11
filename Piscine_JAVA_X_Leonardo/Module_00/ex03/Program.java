import java.util.Scanner;

public class Program {
	public static void main(String[] args) {
		for (byte i = 1; i < 19; i++) {
			Scanner scanner = new Scanner(System.in);
			String week = scanner.nextLine();

			if (week.equals("Week " + i)) {
				Scanner	scanner2 = new Scanner(System.in);
				String	pattern = "[0-9]*";
				String	n;
				long	output;

				for (byte j = 0; j < 5; j++) {
					n = scanner2.next();
					if (scanner2.next() < "1" || scanner2.next() > "9") {
						System.out.println("IllegalArgument");
						scanner.close();
						scanner2.close();
						System.exit(-1);
					}
					// else if (scanner2.next() == "1")
					// 	store += 1;
					// else if (scanner2.next() == "2")
					// 	store += 2;
					// else if (scanner2.next() == "3")
					// 	store += 2;
					// else if (scanner2.next() == "4")
					// 	store += 2;
					// else if (scanner2.next() == "5")
					// 	store += 2;
					// else if (scanner2.next() == "6")
					// 	store += 2;
					// else if (scanner2.next() == "7")
					// 	store += 2;
					// else if (scanner2.next() == "8")
					// 	store += 2;
					// else if (scanner2.next() == "9")
					// 	store += 2;
				}
			}
			else {
				System.out.println("IllegalArgument");
				scanner.close();
				System.exit(-1);
			}
		}
	}
}
