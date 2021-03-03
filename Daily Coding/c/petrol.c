/* 
A man his driving car from home to office with X petrol. There are N number of petrol bunks in the city with only few capacities and each petrol is located in different places For one km one liter will consume. So he fill up petrol in his petrol tank in each petrol bunks. Output the remaining petrol if he has or tell him that he cannot travel if he is out of petrol.
Input:
Petrol in car: 2 Liters
Petrol bunks: A B C
Distance from petrol each petrol bunks: 1, 5, 3
Capacities of each petrol bunk: 6, 4, 2
Output:
Remaining petrol in car is 5 liters
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int rem, len, i, distance[10], capacity[10], petrol;
    char bunks[10];
    printf("Enter the petrol in car : ");
    scanf("%d",&rem);
    printf("Enter the petrol bunks : ");
    scanf("%s",bunks);
    len = strlen(bunks);
    printf("Enter the distance of each petrol bunks : ");
    for(i=0; i<len; i++)
        scanf("%d",&distance[i]);
    printf("Enter the capacity of each petrol bunks : ");
    for(i=0; i<len; i++)
        scanf("%d",&capacity[i]);
    for(i=0; i<len; i++)
    {
        rem = rem - distance[i];
        if(rem < 0)
        {
            printf("Insufficient");
            return 0;
        }
        rem = rem + capacity[i];
    }
    printf("Remaining petrol : %d",rem);
    return 0;
}

