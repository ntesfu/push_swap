#include <stdio.h>
#include "libft.h"
#include "push_swap.h"

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void printArray(int arr[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", arr[i]);    
	printf("h\n");
}

void	stk_push(int stk_a[], int stk_b[], t_stk_ptr *ptr, t_stk_flg *flg)
{	
	if (flg->stk_flag == 0)
	{
		stk_b[ptr->high_b + 1] = stk_a[ptr->high_a];
		stk_a[ptr->high_a] = 0;
		ptr->high_b = ptr->high_b + 1;
		ptr->high_a = ptr->high_a - 1;
	}
	else
	{
		stk_a[ptr->high_a + 1] = stk_b[ptr->high_b];
		stk_b[ptr->high_b] = 0;
		ptr->high_b--;
		ptr->high_a++;
	}
}

void	stk_rotate(int stk[], t_stk_ptr *ptr, t_stk_flg *flg, int freq)
{
	while (freq--)
	{
		int i = 0;
		int h;
		if (flg->stk_flag == 0)
			h = ptr->high_a;
		else
			h = ptr->high_b;		
		while (i < h)
			swap(stk, i++ , h);
	}
}

void	stk_rotate_rev(int stk[], t_stk_ptr *ptr, t_stk_flg *flg,int freq)
{
	while (freq--)
	{
		int i = 0;
		int h;
		if (flg->stk_flag == 0)
			h = ptr->high_a;
		else
			h = ptr->high_b;
		while (i < h)
		{		
			swap(stk, i , h--);
		}
	}
}

int	partition(int stk_a[], int stk_b[], t_stk_ptr *ptr, t_stk_flg *flg)
{
	ft_putstr_fd("look1\n",1);
	int	psh = 0;
	int	rtt = 0;
	int pivot = stk_a[ptr->high_a];
	stk_rotate(stk_a, ptr, flg, 1);
	int low_num = stk_a[(ptr->low_a + 1)];
	int j = ptr->high_a;
	while (1) //here I am writing from vim
	{
		printf("%d:", low_num);
		ft_putstr_fd("look2\n",1);
		printArray(stk_a, ptr->high_a + 1);
		printArray(stk_b, ptr->high_b + 1);
		if (stk_a[ptr->high_a] <= pivot)
		{
			stk_push(stk_a, stk_b, ptr, flg);
			psh++;
		}
		else
		{
			stk_rotate(stk_a, ptr, flg, 1);
			rtt++;
		}
		if (stk_a[ptr->high_a] == pivot)
			break;
		ft_putstr_fd("***\n",1);
		printArray(stk_a, ptr->high_a + 1);
		printArray(stk_b, ptr->high_b + 1);
	}
	stk_rotate_rev(stk_a, ptr, flg, rtt + 1);

    // for(int j = ptr->low_a; j <= ptr->high_a - 1; j++)
    // {    
    //   // If current element is smaller
    //   // than the pivot
    //   if (arr[j] < pivot)
    //   {      
    //     // Increment index of
    //     // smaller element
    //         i++;
    //         swap(arr, i, j);
    //    }
    // }
    // swap(arr, i + 1, high);
    // return (i + 1);
	return j;
}

void	clonePointer(t_stk_ptr *ptr1, t_stk_ptr *ptr2)
{
	ptr2->high_a = ptr1->high_a;
	ptr2->high_b = ptr1->high_b;
	ptr2->low_a = ptr1->low_a;
	ptr2->low_b = ptr1->low_b;
}

void	quickSort(int stk_a[], int stk_b[], t_stk_ptr *ptr, t_stk_flg *flg)
{
	printf("hey:inside quicksort\n");
	t_stk_ptr	*c_ptr;
	int			tmp_flg;

	ft_putstr_fd("hey1\n",1);
	if (ptr->low_a < ptr->high_a)
	{
		c_ptr = (t_stk_ptr *)malloc(sizeof(t_stk_ptr));
		tmp_flg = flg->stk_flag;
		ft_putstr_fd("hey2\n",1);
		int pi = partition(stk_a, stk_b, ptr, flg);
		// clonePointer(ptr, c_ptr);
		// if (tmp_flg == 0)
		// {
		// 	flg->stk_flag = 1;
		// 	c_ptr->high_a = pi - 1;
		// }			
		// else
		// {
		// 	flg->stk_flag = 0;
		// }
			
		// quickSort(stk_b, stk_a, c_ptr, flg);
		// flg->stk_flag = tmp_flg;
		// quickSort(stk_a, stk_b, c_ptr, flg);
		
	}
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
	ptr->high_b = -1;
	ptr->pa_a = ptr->high_a;
	ptr->pa_b = ptr->high_b;
	flg->stk_flag = 0;
	// ft_putstr_fd("***\n",1);
	// printArray(stk_a, 8);
	// printArray(stk_b, 8);
	//stk_rotate(stk_a, ptr, flg, 2);
	quickSort(stk_a, stk_b, ptr, flg);
	// stk_push(stk_a, stk_b, ptr, flg);
	// stk_push(stk_a, stk_b, ptr, flg);
	ft_putstr_fd("Final RESULT***\n",1);
	printArray(stk_a, ptr->high_a + 1);
	printArray(stk_b, ptr->high_b + 1);
}
