// Sum of Pairs bookmark_borderGiven an array of integers and a number K, check if there exist a pair of indices i,j s.t. a[i] + a[j] = K and i!=j.

// Input Format
// The first line of input contains T - the number of test cases. It's followed by 2T lines, first line of each test case contains N - the size of the array and K, and the next line contains N space separated integers - the elements of the array.

// Output Format
// For each test case, print "True" if such a pair exists, "False" otherwise, separated by newline.

// Constraints
// 30 points
// 1 <= T <= 100
// 2 <= N <= 1000

// 70 points
// 1 <= T <= 300
// 2 <= N <= 10000

// General Constraints
// -108 <= K <= 108
// -108 <= ar[i] <= 108

// Example
// Input
// 3
// 5 -15
// -30 15 20 10 -10
// 2 20
// 10 10
// 4 7
// -4 0 10 -7

// Output
// True
// True
// False


import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Main. */
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0){
            int n=sc.nextInt();
            long k=sc.nextLong();
            Set<Long> set=new HashSet<>();
            boolean ist=false;
            for(int i=0;i<n;i++){
                long p=sc.nextLong();
                if(set.contains(k-p)){
                    ist=true;
                }
                set.add(p);
            }
            if(ist){
                System.out.println("True");
            }else{
                System.out.println("False");
            }
        }
    }
}