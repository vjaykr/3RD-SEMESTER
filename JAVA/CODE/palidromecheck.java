class palidromecheck {
    public static boolean ispalindrome(String str){
        String reversed = new StringBuilder(str).reverse().toString();
        return str.equals(reversed);
    }


    public static void main(String args){
        String str = "racecar";

        if(ispalindrome(str)){
            System.out.println(str+"is a palindrome");
        }else{
            System.out.println(str+"is not a palindrome");
        }
    }
}