/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:33:12 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/03 17:29:44 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_put_all(t_stack *stack)
{
	int	i;
	int	j;

	ft_min_max(stack->stack_a, stack->size_a, &stack->min, &stack->max);
	while (stack->size_a > stack->lis)
	{
		i = -1;
		j = -1;
		while (++i < stack->size_a)
			if ((j == -1 || i < j) && !ft_check_lis(stack, stack->stack_a[i]))
				j = i;
		if (j < stack->size_a / 2 + stack->size_a % 2)
			ft_do_this(stack, ra, &j, stack->size_a);
		else
			ft_do_this(stack, rra, &j, stack->size_a);
		pb(stack, 1);
		if (stack->stack_b[0] < (stack->size_l / 2))
			rb(stack, 1);
	}
}

void	ft_empty_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a)
		stack->stack_b[i++] = 0;
}

void	ft_min_max(int *stack, int size, int *min, int *max)
{
	int		i;

	i = 0;
	*min = stack[0];
	*max = stack[0];
	while (++i < size)
	{
		if (stack[i] < *min)
			*min = stack[i];
		if (stack[i] > *max)
			*max = stack[i];
	}
}

int	ft_check_sort(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_a - 1)
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
	return (1);
}

void	ft_check_double(t_stack *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size_a)
	{
		j = i;
		while (++j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
			{
				free(stack->num);
				free(stack->stack_a);
				free(stack->stack_b);
				exit(write(2, "Error\nDuplicated number in input\n", 33));
			}
		}
	}
}
