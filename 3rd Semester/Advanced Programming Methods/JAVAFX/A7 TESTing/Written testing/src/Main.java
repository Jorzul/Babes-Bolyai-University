import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

interface In1 { int getS1(int x);}
class A implements In1 {
    int f1;
    static int s1=0;
    public A(int a) { this.f1=a*s1;s1=s1+1; }
    int getS() { return s1; }
    @Override
    public int getS1(int x) {return s1;}
}

public class Main {
    public static void main(String[] args)
    {
        List<Integer> numbers = Arrays.asList(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15);

        String result = numbers.stream()
                .filter(n -> n % 5 == 0 || n % 2 == 0) // keep only multiples of 5 and 2
                .map(n -> "N" + n + "R") // Transforms each number to a string
                .collect(Collectors.joining()); // Concatenate all the strings

        int result2 = numbers.stream()
                .filter(n -> n % 3 == 0 || n % 7 == 0) // Eliminate numbers that are not multiples of 3 or 7
                .mapToInt(n -> (n - 1) * 10) // Transform each remaining number into its predecessor multiplied by 10
                .reduce(0, Integer::sum) % 5; // Compute the sum

        int result3 = numbers.stream()
                        .filter(n -> n % 4 == 0 || n % 3 == 0)
                        .mapToInt(n -> (n + 1) % 3)
                        .reduce(0, Integer::sum) % 2;

        System.out.println(result);
        System.out.println(result2);
    }
}