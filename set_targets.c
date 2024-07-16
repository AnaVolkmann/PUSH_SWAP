/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 14:26:47 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/16 15:05:59 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief this funcion sets the best targets for each 
 * element of statck a in stack b; */
void set_target_in_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *biggest_b;
	t_stack *best_target;
	t_stack *temp_a;
	t_stack *temp_b;

	temp_a = *stack_a;
	biggest_b = ft_biggest(stack_b);
	while (temp_a)
	{
		best_target = NULL;
		temp_b = *stack_b;
		while (temp_b)
		{
			if (temp_a->data > temp_b->data && (!best_target ||
			 temp_b->data > best_target->data))
				best_target = temp_b;
			temp_b = temp_b->next;
		}
		if (!best_target)
			temp_a->target = biggest_b;
		else
			temp_a->target = best_target;
		temp_a = temp_a->next;
	}
}

/** @brief this funcion sets the best targets for each element
 *  of statck b in stack a; */
void set_target_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	t_stack *best_target;
	t_stack *biggest;

	temp_b = *stack_b;
	biggest = ft_biggest(stack_a);
	while (temp_b)
	{
		best_target = NULL;
		temp_a = *stack_a;
		while (temp_a)
		{
			if (temp_a->data > temp_b->data && (!best_target || 
			temp_a->data < best_target->data))
				best_target = temp_a;
			temp_a = temp_a->next;
		}
		if (!best_target)
			temp_b->target = biggest;
		else 
			temp_b->target = best_target;
		temp_b = temp_b->next;
	}
}
void	update_stack_nodes(t_stack **stack_a, t_stack **stack_b, int flag)
{
	index_median(stack_a);
	idex_median(stack_b);
	if (flag == 1)
	{
		set_target_in_b(stack_a, stack_b);
		cost_of_a(stack_a, stack_b);
	}
	else if (flag == 0)
	{
		set_target_in_a(stack_a, stack_b);
		cost_of_b(stack_a, stack_b);
	}
}