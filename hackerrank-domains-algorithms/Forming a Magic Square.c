#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int matrix[3][3];
    int magicArray1[8] = {4,9,2,7,6,1,8,3};
    int magicArray2[8] = {2,9,4,3,8,1,6,7};
    int indexes[8] = {0,1,2,12,22,21,20,10};
    int i, j, shift = 0;
    int costResult = 100, costTmp = 0;
    int found = 0;
    
    for (i = 0; i < 3; i++) 
    {
        for (j = 0; j < 3; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
        scanf("\n");
    }
    
    for (shift = 0; shift < 8 && !found; shift += 2)
    {
        costTmp = 0;
        for (i = 0, j = shift; i < 8 ; i++) 
        {
            costTmp += abs(matrix[indexes[i]/10][indexes[i]%10] - magicArray1[j]);
            j = (j + 1) % 8;
        } 
        if (costTmp == 0)
        {
            found = 1;
            costResult = 0;
        } else if (costTmp < costResult) 
        {
            costResult = costTmp;
        }
    }

    for (shift = 0; shift < 8 && !found; shift += 2)
    {
        costTmp = 0;
        for (i = 0, j = shift; i < 8 ; i++) 
        {
            costTmp += abs(matrix[indexes[i]/10][indexes[i]%10] - magicArray2[j]);
            j = (j + 1) % 8;
        } 
        if (costTmp == 0)
        {
            found = 1;
            costResult = 0;
        } else if (costTmp < costResult) 
        {
            costResult = costTmp;
        }
    }

    costResult += abs(matrix[1][1] - 5);
    printf("%d", costResult);
}
