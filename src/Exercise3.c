/*
3.	Input an array of n integers. Find the largest sorted sub array
(sorted array increasing/decreasing and has the largest number of elements)
Ex:
 _____________________________________________
| Input: 2 5 3 4 8 9 7 6 10                   |
| Output: Increasing 3 4 8 9 Decreasing 9 7 6 |
|_____________________________________________|
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Ex3(int in_arr[], int n){
	//Your codes here
 int max1 = 1, len = 1, maxIndex1 = 0; 

    int max2 = 1, len2= 1, maxIndex2 =0;
    int arr2[n];


    for (int i =0; i<n; i++) {
        arr2[i] = in_arr[i];
    }


    for (int i=1; i<n; i++)
    {
        if (in_arr[i] > in_arr[i-1])
            len++;
        else
        {
            if (max1 < len)
            {
                max1 = len; 
                maxIndex1 = i - max1;
            }
            len = 1;
        }
    }
    if (max1 < len)
    {
        max1 = len;
        maxIndex1 = n - max1;
    }
    printf("Increasing ");
    for (int i=maxIndex1; i<max1 + maxIndex1; i++) {
        printf("%d ", in_arr[i]);
    }



for (int i=1; i<n; i++)
    {
        if (arr2[i] < arr2[i-1])
            len2++;
        else
        {
            if (max2 < len2)
            {
                max2 = len2; 
                maxIndex2 = i - max2;
            }
            len2 = 1;
        }
    }
    if (max2 < len2)
    {
        max2 = len2;
        maxIndex2 = n - max2;
    }
    printf("Decreasing ");
    for (int i=maxIndex2; i<max2+maxIndex2; i++) {
        printf("%d ", arr2[i]);
    }

}
	

int main(int argc, char *argv[]) {
	//testing variable, applying it to your algorithm for auto-evaluating
	argc--;
	int testcase[argc],i;
	for(i=0; i<argc;i++){
		testcase[i] = atoi(argv[i+1]);
	}
	
	Ex3(testcase, argc);
	
	return 0;
}
