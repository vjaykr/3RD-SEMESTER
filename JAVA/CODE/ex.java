public class ex {
    public static void main(String[] args) {
         
        eu( 50, 20, 10, 5);
        
    }

    public static void eu( double x1,double  x2,double y1,double y2){



        double x=x2 -x1;
        double y=y2 -y1;
        double x_pow= Math.pow(x,2);
        double y_pow= Math.pow(y,2);
        double x_y=x_pow+y_pow;
        double distance=Math.sqrt(x_y);
        System.out.println(distance);    

    }
        
        
    
}
