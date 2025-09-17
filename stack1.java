import java.util.Stack;
public class stack1{
    public static void main(String[] args){
        Stack<String> s=new Stack<>();
        s.push("karthik");
        s.push("vb");
        System.out.println(s);
       String pe= s.pop();
System.out.println(pe);
System.out.println("stack elements :" +s);
String te=s.peek();
System.out.println(te);
            }
}