import java.util.*;
public class digitcount{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int c=0;
        while(n>0){
            int d=n%10;
            c++;
            n=n/10;
        }
        System.out.println(c);
    }
}