 class Calculatorr{

    public static void add (int a,int b){
        int c=a+b;
        System.out.println(c);
    }

    public static void sub (int a,int b){
        int c=a-b;
        System.out.println(c);
    }
    public static void multi (int a,int b){
        int c=a*b;
        System.out.println(c);
    }
    public static void div(int a,int b){
        int c=a/b;
        System.out.println(c);
    }

 }

 class demoo{

    public static void main(String[] args){
        calculator x =new calculator();

        x.add(10,20);
        x.sub(10,2);
        x.multi(10,6);
        x.div(10,5);
 
        System.out.println();
        System.out.println();

        
         calculator y =new calculator();
        y.add(10,40);
        y.sub(10,5);
        y.multi(12,5);
        y.div(100,5);
 
 
    }

 }

 


 