package Task05;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int limit = input.nextInt();

        double[][] borrowers = new double[n][n];
        for (int bankId = 0; bankId < n; bankId++) {
            int balance = input.nextInt();
            int bankCount = input.nextInt();
            borrowers[bankId][bankId] = balance;
            for (int pairIndex = 0; pairIndex < bankCount; pairIndex++) {
                int lenderId = input.nextInt();
                double loan = input.nextDouble();
                borrowers[bankId][lenderId] += loan;
            }
        }

        ArrayList<Integer> unsafeBanks = new ArrayList<>();
        getUnsafe(n, limit, borrowers, unsafeBanks, -1);
        System.out.printf("Unsafe banks are %s",
                unsafeBanks.stream().map(Object::toString).collect(Collectors.joining(" ")));
    }

    private static void getUnsafe(int n, int limit, double[][] borrowers, ArrayList<Integer> unsafeBanks, int unsafeBankId) {
        for (int bankId = 0; bankId < n; bankId++) {
            if (unsafeBankId >= 0) {
                borrowers[bankId][unsafeBankId] = 0;
            }
            if (!unsafeBanks.contains(bankId) && Arrays.stream(borrowers[bankId]).sum() < limit) {
                unsafeBanks.add(bankId);
                getUnsafe(n, limit, borrowers, unsafeBanks, bankId);
            }
        }
    }
}
