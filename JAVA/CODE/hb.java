 class calculator {

    public static void main(String[] args){

        add(10,20);
        sub(10,2);
        multi(10,6);
        div(10,5);
    }

    public static void add(int a,int b){
        int c=a+b;
        System.out.println(c);
    }

    public static void sub(int a,int b){
        int c=a-b;
        System.out.println(c);
    }

    public static void multi(int a,int b){
        int c=a*b;
        System.out.println(c);
    }

    public static void div(int a,int b){
        int c=a/b;
        System.out.println(c);
    }
}