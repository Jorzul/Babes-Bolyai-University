#include <stdio.h>


void readArray(int arr[], int* len)

// This function is used to read an Array of numbers. 
// parameters: arr[] - array of numbers, len - length of the array.
// return: It returns the array to the main function.

{
    int n, x;
    printf("How many numbers are in the array? \n>");
    scanf("%d", &n);
    *len = n;
    printf("The elements of the array are: \n");
    for (int i = 0 ; i < n ; i++)
    {
        scanf("%d", &x);
        arr[i] = x;
    }
}


void first_n_prime_numbers(int n)

// This function is used for the A problem. It prints the first n prime numbers.
// parameters: n - variable read by the operator.
// return: It does not return anything, it only prints the first n prime numbers.

{
    int i=2, ok, j;

    if (n==1)
    {
        printf("1.");
    }
    else if (n==2)
    {
        printf("1, 2.");
    }
    else
    {   
        printf("1, 2, ");
        n = n - 2;

        while(n > 0)
        {

            ok = 1;
            i = i + 1;

            for (j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    ok = 0;
                }
            }

            if (ok == 1)
            {
                if (n == 1)
                {
                    printf("%d.", i);
                }
                else
                {
                    printf("%d, ", i);
                }
                n = n - 1;
            }
        
        }
    }
}


void printSubsequence(int arr[], int start, int end)

// This function is used to print the longest subsequence, 
// after we denoted a start point and an end point.
// parameters: arr - the initial array, start - start point of the subsequence,
//             end - end point of the subsequence.
// return: it does not return anything. It only prints the longest subsequence.


{
    printf("The longest subsequence is: \n");
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }
}


int greatest_common_divisor(int a, int b)

// This function takes two numbers, and returns their greatest common divisor.
// parameters: two numbers.
// return: The number's greatest common divisor.

{
    int gcd;
    for (int i=1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}


void longest_sub(int arr[], int arr_len)

// This function is used for the B problem. It calculates the longest contiguous subsequence,
// such that any two consecutive elements are relatively prime.
// parameters: arr - the initial array, arr_len - the length of the array
// return: It does not return anything. It will eventually print the longest subsequence using another function.

{
    int start = 0, end = 0;
    int maxlength = 0, current_length = 0;
    int gcd;

    for (int i = 0; i < arr_len - 1; i++)
    {

        int j = i;
        while (j < arr_len - 1 && greatest_common_divisor(arr[j], arr[j+1]) == 1)
        {
            j = j + 1;
        }

        current_length = j - i;
        if (current_length > maxlength)
        {
            maxlength = current_length;
            start = i;
            end = j;
        }

    }

    printSubsequence(arr, start, end);
}


int main()

// The main function.

{
    int option;
    int arr[50];
    int len = 0;
    int array_read = 0;

    while (1)
    {
        printf("\nInput your option: ");
        printf("\n1. Read the array of numbers.");
        printf("\n2. Problem A");
        printf("\n3. Problem B");
        printf("\n4. Exit the program.");
        printf("\n>");
        scanf("%d", &option);

        if (option == 4)
        {
            break;
        }

        if (option == 1)
        {
            readArray(arr, &len);
            array_read = 1;
        }

        if (option == 2)
        {   
            int n;
            printf("n = ");
            scanf("%d", &n);
            first_n_prime_numbers(n);
        }

        if (option == 3)
        {
            if (array_read == 1)
            {
                longest_sub(arr, len);
            }
            else
            {
                printf("You have to read an array first.");
            }
        }
    }

    return 0;

}
