/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:06:08 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/02 16:47:45 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	rra(t_stack *stack, int print)
{
	int	i;
	int	tmp;

	if (!stack->size_a)
		return ;
	i = stack->size_a;
	tmp = stack->stack_a[i - 1];
	while (--i > 0)
		stack->stack_a[i] = stack->stack_a[i - 1];
	stack->stack_a[i] = tmp;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int print)
{
	int	i;
	int	tmp;

	if (!stack->size_b)
		return ;
	i = stack->size_b;
	tmp = stack->stack_b[i - 1];
	while (--i > 0)
		stack->stack_b[i] = stack->stack_b[i - 1];
	stack->stack_b[i] = tmp;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int print)
{
	rra(stack, 0);
	rrb(stack, 0);
	if (print)
		write(1, "rrr\n", 4);
}
