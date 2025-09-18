import java.util.*;
public class automorphic{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int t=n;
        int c=0;
        long di=1;
        while(n>0){
            int d=n%10;
            c++;
            n=n/10;
            di*=10;
        }
       long r=(long)t*t;
       
            long e=r%di;
            if(e==t){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        
    }
}