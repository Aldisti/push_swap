/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:20:13 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/03 11:04:42 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_do_this(t_stack *stack, void (*f)(t_stack *, int), int *n, int size)
{
	if (*n > (size / 2 + size % 2))
		*n = size - *n;
	while (*n > 0 && (*n)--)
		(*f)(stack, 1);
}

void	ft_push_to_a1(t_stack *stack, int bi, int ai)
{
	if (bi < stack->size_b / 2 + stack->size_b % 2
		&& ai < stack->size_a / 2 + stack->size_a % 2)
	{
		while (ai > 0 && bi > 0 && ai-- && bi--)
			rr(stack, 1);
		while (ai > 0 && ai--)
			ra(stack, 1);
		while (bi > 0 && bi--)
			rb(stack, 1);
	}
	else if (bi > stack->size_b / 2 + stack->size_b % 2
		&& ai > stack->size_a / 2 + stack->size_a % 2)
	{
		ai = stack->size_a - ai;
		bi = stack->size_b - bi;
		while (ai > 0 && bi > 0 && ai-- && bi--)
			rrr(stack, 1);
		while (ai > 0 && ai--)
			rra(stack, 1);
		while (bi > 0 && bi--)
			rrb(stack, 1);
	}
	else
		ft_push_to_a2(stack, ai, bi);
	ft_min_max(stack->stack_a, stack->size_a, &stack->min, &stack->max);
}

void	ft_push_to_a2(t_stack *stack, int ai, int bi)
{
	if (ai < stack->size_a / 2 + stack->size_a % 2)
		while (ai > 0 && ai--)
			ra(stack, 1);
	else
	{
		ai = stack->size_a - ai;
		while (ai > 0 && ai--)
			rra(stack, 1);
	}
	if (bi < stack->size_b / 2 + stack->size_b % 2)
		while (bi > 0 && bi--)
			rb(stack, 1);
	else
	{
		bi = stack->size_b - bi;
		while (bi > 0 && bi--)
			rrb(stack, 1);
	}
}

void	ft_final_sort(t_stack *stack)
{
	int	y;

	ft_min_max(stack->stack_a, stack->size_a, &stack->min, &stack->max);
	y = ft_get_index(stack->stack_a, stack->size_a, stack->min);
	if (y < (stack->size_a / 2 + stack->size_a % 2))
		while (stack->stack_a[0] != stack->min)
			ra(stack, 1);
	else
		while (stack->stack_a[0] != stack->min)
			rra(stack, 1);
}

void	ft_sort_swap(t_stack *stack)
{
	int	index[4];

	ft_lis(stack);
	ft_put_all(stack);
	while (stack->size_b)
	{
		index[0] = -1;
		index[2] = -1;
		while (++index[0] < stack->size_b)
		{
			index[3] = ft_mosse(stack, stack->stack_b[index[0]], index[0]);
			if (index[2] == -1 || index[2] > index[3])
			{
				index[1] = stack->stack_b[index[0]];
				index[2] = index[3];
			}
		}
		ft_push_to_a1(stack, ft_get_index(stack->stack_b,
				stack->size_b, index[1]),
			ft_get_index(stack->stack_a, stack->size_a,
				ft_min_of_max(stack->stack_a, stack->size_a, index[1])));
		pa(stack, 1);
	}
	ft_final_sort(stack);
}
