#include <stdio.h>
#include "push_swap.h"

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void	stk_push(int stk_a[], int stk_b[], t_stk_ptr *ptr)
{

}

void	stk_rotate(int stk[])
{

}

void	stk_rotate_rev(int stk[])
{
	
}

int partition(int stk_a[], int stk_b[], t_stk_ptr *ptr, t_stk_flg *flg)
{  
    int pivot = stk_a[ptr->high_a];
	stk_rotate();
    int i = (ptr->low_a - 1);
    for(int j = low; j <= high - 1; j++)
    {    
      // If current element is smaller
      // than the pivot
      if (arr[j] < pivot)
      {      
        // Increment index of
        // smaller element
            i++;
            swap(arr, i, j);
       }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}


void	quickSort(int stk_a[], int stk_b[], t_stk_ptr *ptr, t_stk_flg *flg)
{
	t_stk_ptr *c_ptr;

	if (ptr->low_a < ptr->high_a)
	{
		c_ptr = (t_stk_ptr *)malloc(sizeof(t_stk_ptr));
		int pi = partition(stk_a, stk_b, ptr, flg);
		c_ptr->low_a = ptr->low_b;
		c_ptr->high_a = ptr->high_b;
		c_ptr->low_b = ptr->low_a;
		c_ptr->high_b = ptr->high_a;		
		quickSort(stk_b, stk_a, c_ptr, flg);
		quickSort(stk_a, stk_b, c_ptr, flg);
	}
}

void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
      printf("%d ", arr[i]);    
      printf("\n");
}

int main(int argc, char **argv)
{
	int stk_a[] = {1,6,8,3,4,9,2,7};
	int stk_b[8];

	t_stk_ptr	*ptr;
	t_stk_flg	*flg;

	ptr = (t_stk_ptr *)malloc(sizeof(t_stk_ptr));
	flg = (t_stk_flg *)malloc(sizeof(t_stk_flg));
	ptr->low_a = 0;
	ptr->low_b = 0;
	ptr->high_a = 7;
	ptr->high_b = 0;
	flg->stk_flag = 0;
	printArray(stk_a, 8);
	quickSort(stk_a, stk_b, ptr, flg);
	printArray(stk_a, 8);
}