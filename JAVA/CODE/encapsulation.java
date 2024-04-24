public class encapsulation {
    private String name;
    public int roll;
    protected String subject;

    encapsulation(String n ,int r,String s){
        name = n;
        subject=s;
        roll=r;

    }
    String getname(){
        return name;
    }
    void Setname(String n){
        name =n;
    }
}

class Demo{
    public static void main(String[] args) {
        encapsulation S = new encapsulation("xyz",1,"java");
        System.out.println(S.Setname);
        System.out.println(S.roll);
        System.out.println(S.subject);
        S.Setname("abc");
        System.out.println(S.Setname);
    }
}
