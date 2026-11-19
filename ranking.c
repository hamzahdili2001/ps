/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:11:47 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/18 11:11:47 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	assign_ranks(t_stack *a)
{
	int	*ranks;
	int	i;
	int	j;
	int	count;

	ranks = malloc(sizeof(int) * a->size);
	if (!ranks)
		return ;
	i = 0;
	while (i < (int)a->size)
	{
		count = 0;
		j = 0;
		while (j < (int)a->size)
		{
			if (j != i && stack_get(a, j) < stack_get(a, i))
				count++;
			j++;
		}
		ranks[i] = count;
		i++;
	}
	i = 0;
	while (i < (int)a->size)
	{
		a->data[(a->head + i) % a->cap] = ranks[i];
		i++;
	}
	free(ranks);
}
