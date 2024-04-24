import java.util.Scanner;
public class compound_interest {
    public static void ci(){
        double p,r,n,t;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Principle amount");
        p=sc.nextDouble();
        System.out.println("Enter Rate of intrest ");
        r=sc.nextDouble();
        System.out.println("Enter number of time intrest");
        n=sc.nextDouble();
        System.out.println("Enter the time number");
        t=sc.nextDouble();
        System.out.println("enter total duration");
        double amount = p*Math.pow(1+(r/n), n*t);
        double cintrest = amount-p;
        System.out.println("compound intrest " +t+ "year" + cintrest);
        System.out.println("amount after " +t+ "year" + amount);
    }
    public static void main(String[] args) {
        ci();   
    }
    
}