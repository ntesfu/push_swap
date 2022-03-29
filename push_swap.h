#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
typedef struct stack_ptr
{
	int	low_a;
	int	high_a;
	int	low_b;
	int	high_b;
} t_stk_ptr;

typedef struct stack_flag
{
	int		stk_flag;
	char	*op;
} t_stk_flg;

#endif

