#include <iostream>

using namespace std;

int digitsCount(int x)
{
    int digits = 1;

    while (x / 10 > 0)
    {
        digits++;
        x = x / 10;
    }

    return digits;
}

int isLarger(int x, int y)
{
    int lengthOfX = digitsCount(x);
    int lengthOfY = digitsCount(y);

    if (x > y)
    {
        int multiplier = 1;
        for (int i = 0; i < lengthOfX - lengthOfY; i++)
        {
            multiplier *= 10;
        }

        y *= multiplier;
    }
    else
    {
        int multiplier = 1;
        for (int i = 0; i < lengthOfY - lengthOfX; i++)
        {
            multiplier *= 10;
        }

        x *= multiplier;
    }

    return x > y;
}

void sortLex(unsigned int* a, unsigned int n)
{
    bool swapped = false;
    for (unsigned int i = 0; i < n - 1; ++i)
    {

        for (unsigned int j = 0; j < n - i - 1; ++j)
        {
            if (isLarger(a[j], a[j + 1]))
            {
                unsigned int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void printArray(unsigned int arr[], unsigned int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver program to test above functions
int main()
{
    unsigned int a[] = {24, 4, 25555, 129999, 22, 1100, 90};
    unsigned int n = sizeof(a)/sizeof(a[0]);
    sortLex(a, n);
    printf("Sorted array: ");
    printArray(a, n);
    return 0;
}


