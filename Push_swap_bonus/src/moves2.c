/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:24 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/02 16:47:20 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	pa(t_stack *stack, int print)
{
	int	i;

	if (!stack->size_b)
		return ;
	i = ++stack->size_a;
	while (--i > 0)
		stack->stack_a[i] = stack->stack_a[i - 1];
	stack->stack_a[0] = stack->stack_b[0];
	i = -1;
	while (++i < stack->size_b - 1)
		stack->stack_b[i] = stack->stack_b[i + 1];
	stack->stack_b[i] = 0;
	stack->size_b--;
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stack, int print)
{
	int	i;

	if (!stack->size_a)
		return ;
	i = ++stack->size_b;
	while (--i > 0)
		stack->stack_b[i] = stack->stack_b[i - 1];
	stack->stack_b[0] = stack->stack_a[0];
	i = -1;
	while (++i < stack->size_a - 1)
		stack->stack_a[i] = stack->stack_a[i + 1];
	stack->stack_a[i] = 0;
	stack->size_a--;
	if (print)
		write(1, "pb\n", 3);
}
