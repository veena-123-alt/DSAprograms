#include <stdio.h>

int main()
{
    int array[5], total_m = 0, passed = 1;
    char sub[5][10] = {"English", "Maths", "Science", "Chemistry", "Punjabi"};

    printf("Enter marks for given subjects: \n");

    int temp_ = -1;
    int i = 0;
    while (1)
    {
        printf("Enter marks for %s: ", sub[i]);
        scanf("%d", &temp_);
        if (temp_ > 100 || temp_ < 0)
        {
            printf("Invalid marks, enter between 0 to 100\n");
            continue;
        }
        else
        {
            array[i] = temp_;
            total_m = total_m + temp_;
            i++;
            if (temp_ < 40)
            {
                passed = 0;
            }
        }
        if (i >= 5)
        {
            break;
        }
    }
    printf("\n");
    float average = total_m / 5;
    printf("Total marks: %d / 500\n", total_m);
    printf("Average marks: %.2f\n", average);

    if (passed == 0)
    {
        printf("Failed.\n");
    }
    else
    {
        printf("Passed.\n");
    }
}
