import java.util.Stack;

public class stack {
    public static void main(String[] args) {
        Stack<String> stack = new Stack<>();

        stack.push("A");
        stack.push("B");
        stack.push("C");

        System.out.println("Stack: " + stack); // Output: Stack: [A, B, C]

        String poppedElement = stack.pop();
        System.out.println("Popped element: " + poppedElement); // Output: Popped element: C
        System.out.println("Stack after pop: " + stack); // Output: Stack after pop: [A, B]

        // Peek at the top element
        String topElement = stack.peek();
        System.out.println("Top element: " + topElement); // Output: Top element: B
    }
}