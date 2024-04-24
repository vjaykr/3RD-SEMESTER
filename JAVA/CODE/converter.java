public class converter {
    
public static void main(String[] args){

    fernhiet(54);
    Celcius(85);
    massonmars(57);

}

public static void fernhiet(double t){

    double fernhiet=(t*9/2)+32;
    System.out.println(fernhiet);
} 

public static void Celcius(double t){

    double celcius=(t-32)*5/9;
    System.out.println(celcius);
}
public static void massonmars(double t)
{
double fehranheit = t * 0.38;
System.out.println(fehranheit + " mass");
}

}
