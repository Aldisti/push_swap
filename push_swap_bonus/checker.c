/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:30:34 by adi-stef          #+#    #+#             */
/*   Updated: 2023/04/03 11:01:34 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ft_is_sorted(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1 && arr[i] < arr[i + 1])
		i++;
	return (i == size - 1);
}

int	ft_switch(t_stack *stack, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(stack, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sb(stack, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss(stack, 0);
	else if (!ft_strcmp(str, "pa\n"))
		pa(stack, 0);
	else if (!ft_strcmp(str, "pb\n"))
		pb(stack, 0);
	else if (!ft_strcmp(str, "ra\n"))
		ra(stack, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(stack, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr(stack, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(stack, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(stack, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(stack, 0);
	else
		return (0);
	return (1);
}

int	ft_check_b(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_l)
		if (stack->stack_b[i] != 0)
			return (0);
	return (1);
}

int	ft_checker(t_stack *stack)
{
	char	*str;

	while (42)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!ft_switch(stack, str))
		{
			write(2, "Error\nInvalid istruction\n", 25);
			free(str);
			ft_free(stack);
			exit(1);
		}
		free(str);
	}
	return (ft_is_sorted(stack->stack_a, stack->size_a) && ft_check_b(stack));
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac <= 1)
		return (0);
	ft_size_count(ac, av, &stack);
	stack.size_b = 0;
	stack.stack_b = (int *) malloc (stack.size_a * sizeof(int));
	ft_empty_b(&stack);
	ft_empty_stack_a(&stack);
	ft_check_double(&stack);
	if (!ft_checker(&stack))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (ft_free(&stack));
}
