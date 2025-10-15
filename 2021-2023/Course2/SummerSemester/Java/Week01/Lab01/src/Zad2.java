import java.util.Scanner;

public class Zad2 {
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        System.out.print("Enter number: ");
        int originalNumber=input.nextInt();
       if(originalNumber<10_000||originalNumber>99_999){
           System.out.println("The number is not 5 digitted");
           return;
       }

       String resultString = Integer.toString(originalNumber);
        for (int i = resultString.length()-1 ,j=0; i >=resultString.length()/2 ; i--,j++) {
            int endDigit = resultString.codePointAt(i)-"0".codePointAt(0);
            int startDigit = resultString.codePointAt(j)-"0".codePointAt(0);
            if(endDigit!=startDigit){
                System.out.println("Not palindrome");
                return;
            }
        }

        System.out.println("Is Palindrome");
    }
}
