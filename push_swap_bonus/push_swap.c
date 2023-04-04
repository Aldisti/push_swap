/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <adi-stef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:48:55 by lde-mich          #+#    #+#             */
/*   Updated: 2023/04/03 11:00:45 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc <= 1)
		return (0);
	ft_size_count(argc, argv, &stack);
	stack.size_b = 0;
	stack.stack_b = (int *) malloc (stack.size_a * sizeof(int));
	ft_empty_b(&stack);
	ft_empty_stack_a(&stack);
	ft_check_double(&stack);
	if (ft_check_sort(&stack))
	{
		ft_free(&stack);
		return (0);
	}
	if (stack.size_a < 6)
		ft_solve_five(&stack);
	else
		ft_sort_swap(&stack);
	ft_free(&stack);
}
