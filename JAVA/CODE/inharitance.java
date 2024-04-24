public class inharitance {
    int add(int a,int b){
        return a+b;

    }
    int sub(int a,int b){
        return a-b;
    }
    }

      class cal extends inharitance {
        int mul(int a,int b){
            return a*b;
        }
        int div(int a,int b){
            return a/b;
        }

    }
    class demo{
        public static void main(String[] args) {
            cal obj1 = new cal();
            System.out.println(obj1.add(5,10));
            System.out.println(obj1.sub(28,8));
            System.out.println(obj1.mul(25,4));
            System.out.println(obj1.div(30,3));


        }
    }