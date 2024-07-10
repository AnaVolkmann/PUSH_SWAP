/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-lda- <ana-lda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:12:25 by ana-lda-          #+#    #+#             */
/*   Updated: 2024/07/09 16:38:15 by ana-lda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/** @brief Frees the elements generated by split funtion.*/
int	free_split(int argc, char **argv, bool flag)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	if (flag)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

/** @brief Frees elements of stack and stack.*/
void	free_stack(t_stack *node)
{
	t_stack	*temp;

	while (node)
	{
		temp = node;
		node = (node)->next;
		free(temp);
	}
}
