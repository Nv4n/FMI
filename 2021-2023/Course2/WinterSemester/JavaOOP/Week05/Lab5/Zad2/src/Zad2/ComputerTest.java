package Zad2;

import java.util.Scanner;

public class ComputerTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Computer comp1 = new Computer();
        Computer comp2 = new Computer("Deel", 5000, new String[]{"test1.png,test2.txt"});
        Computer comp3 = new Computer(comp2);
        System.out.printf("""
                %s
                %s
                %s
                """, comp1, comp2, comp3);


        comp3.setType("AceeRRR");
        comp3.setProcSpeed(-100);
        comp1.setProcSpeed(6000);
        comp2.setType(null);
        comp1.setFiles(new String[]{"iHaveFiles.txt"});

        System.out.print("Click enter to continue...");
        if (input.hasNextLine())
            System.out.printf("""
                    %s
                    %s
                    %s
                    """, comp1, comp2, comp3);
    }
}
