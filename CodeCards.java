import java.util.Scanner;

public class CodeCards {

    public static boolean incode(char ch) {
        return ch == 'c' || ch == 'o' || ch == 'd' || ch == 'e';
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        int t = scn.nextInt();
        while (t-- > 0) {

            String s1 = scn.next();
            String s2 = scn.next();

            boolean flag = true;
            int count = 0;

            for (int i = 0; i < s1.length(); i++) {
                if (s1.charAt(i) == s2.charAt(i)) {
                    continue;
                }

                if (s1.charAt(i) == '$' && incode(s2.charAt(i))) {
                    count++;
                    continue;
                }

                if (s2.charAt(i) == '$' && incode(s1.charAt(i))) {
                    count++;
                    continue;
                }

                flag = false;
                break;
            }

            System.out.println(flag ? count : "-1");

        }

    }
}
