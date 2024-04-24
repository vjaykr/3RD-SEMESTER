import java.util.*;

public class game {
    public static void guessinggame() {
       int answer=(int)(Math.random() * 100) +1;
       int k=5;
       Scanner input =new Scanner(System.in); 
       boolean correct=false;
       System.out.println("I'm thinking jof a number between 1 and 100. \nyou have 5 tries to guess the number.");
       while(k>0){
        System.out.println("enter your guess: ");
        int guess=input.nextInt();
        if(guess==answer){
            System.out.println("you the number :\n you win!");
            break;
        }
        else if(guess>answer){
            System.out.println("your guess is to high.\n" + (k - 1) + "tries lefft.");
        }
        else{
            System.out.println("your guess is too low.\nyou have " + (k - 1) + "tries left.");

        }
        k--;
       }
       if(correct==false){
        System.out.println("you ran out of tries.\nyou lose!");
       }
       System.out.println("correct number is:"+ answer);
        
    }
}
