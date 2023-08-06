#include <stdio.h>

int main()
{
    int age[6][4];
    for (int i = 0; i < sizeof(age)/sizeof(age[0]) ; i++)
    {
        printf("age + %d address is %p\n",i, age + i);
    }
    for (int i = 0; i < sizeof(age) / sizeof(age[0]); i++)
    {
        for (int j = 0; j < sizeof(age[0]) / sizeof(int); j++)
        {
            printf("age[%d][0] + %d address is %p\n",i,j,&age[i][0]+j);
        }

    }
}