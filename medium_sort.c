/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 10:35:21 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/17 10:49:09 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack *s)
{
	int	i;
	int	min_idx;

	i = 1;
	min_idx = 0;
	while (i < (int)s->size)
	{
		if (stack_get(s, i) > stack_get(s, min_idx))
			min_idx = i;
		i++;
	}
	return (min_idx);
}

void	bring_max_to_top(t_ps *ps)
{
	size_t	size;
	int		max_idx;
	int		i;

	size = ps->b.size;
	max_idx = find_max_index(&ps->b);
	if (max_idx <= (int)(size / 2))
	{
		i = 0;
		while (i < max_idx)
		{
			op(ps, OP_RB);
			i++;
		}
	}
	else
	{
		i = size - max_idx;
		while (i > 0)
		{
			op(ps, OP_RRB);
			i--;
		}
	}
}

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
		a->data[(a->head + i) % a->cap] = ranks[i];
	free(ranks);
}
