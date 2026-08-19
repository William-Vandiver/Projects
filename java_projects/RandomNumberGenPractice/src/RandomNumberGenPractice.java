// just silly little practice program, focus on some basic math, and using random library to make array

import java.util.Random;
import java.util.Scanner;

public class RandomNumberGenPractice {
    public static void main(String[] args) {
        double number;

        System.out.println("Enter the number you are thinking of and i will divide, multiply it by 100");

        Scanner userInput = new Scanner(System.in);

        try {
            number = userInput.nextDouble();

            System.out.println("Okay your number: " + number + " divide by 100 is " + number / 100);
            System.out.println("Okay your number: " + number + " multiply by 100 is " + number * 100);

            System.out.println("Now you will divide and multiply a number I give you");
        } catch (ArithmeticException e) {
            System.out.println("You can NOT divide by 0!");
            // this try/catch will never matter since mathematically impossible for this program to divide by 0, by i wanna make it anyways
        }

        Random myNumber = new Random();

        number = myNumber.nextInt(100) +1;

        System.out.println("My number to is: " + number + " now divide it");

        double userNumber = userInput.nextDouble();

        if (userNumber == number / 100) {
            System.out.println("You are right!");
        }
        else {
            System.out.println("You are wrong!");
        }

        System.out.println("My number to is: " + number + " now multiply it");

        double userNumber2 = userInput.nextDouble();

        if (userNumber2 == number * 100) {
            System.out.println("You are right!");
        }
        else {
            System.out.println("You are wrong!");
        }

        System.out.println("Now how many hours have you been awake today?");

        int userHours = userInput.nextInt();

        System.out.println("There are this many hours left in the day " + (24 - userHours) + " hours");

        randomArray();
    }

    public static void randomArray() {
        System.out.println("I am making a array of random will be size from 1 to 10. Then filled with random numbers");
        Random randnum = new Random();
        int length = randnum.nextInt(10) + 1;

        int[] ray = new int[length];

        for(int i = 0; i < ray.length; i++){
            ray[i] = randnum.nextInt(11);
        }

        System.out.println("Array done.I'm now printing out numbers starting from index 0.");

        for(int index = 0; index < ray.length; index++){
            System.out.println(ray[index]);
        }
    }
}