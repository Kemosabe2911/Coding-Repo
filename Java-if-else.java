/*
Sample Input 0

3

Sample Output 0

Weird

Sample Input 1

24

Sample Output 1

Not Weird
 
*/
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {



    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int N = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
        if(N%2==1){
            System.out.println("Weird");
        }
        else{
            if((N>=2)&&(N<=5)){
                System.out.println("Not Weird");
            }
            else if((N>=6)&&(N<=20)){
                System.out.println("Weird");
            }
            else{
                System.out.println("Not Weird");
            }
        }

        scanner.close();
    }
}