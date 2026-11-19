/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 10:35:21 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/18 11:11:36 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

static int	find_max_index(t_stack *s)
{
	int	i;
	int	max_idx;

	i = 1;
	max_idx = 0;
	while (i < (int)s->size)
	{
		if (stack_get(s, i) > stack_get(s, max_idx))
			max_idx = i;
		i++;
	}
	return (max_idx);
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
		i = (int)size - max_idx;
		while (i > 0)
		{
			op(ps, OP_RRB);
			i--;
		}
	}
}

void	sort_medium(t_ps *ps)
{
	int	chunk_size;
	int	pushed;
	int	x;
	int	n;

	n = (int)ps->a.size;
	assign_ranks(&ps->a);
	chunk_size = (ft_sqrt(n) * 3) / 2;
	pushed = 0;
	while (ps->a.size > 0)
	{
		x = stack_get(&ps->a, 0);
		if (x <= pushed + chunk_size)
		{
			op(ps, OP_PB);
			if (x <= pushed && ps->b.size > 1)
				op(ps, OP_RB);
			pushed++;
		}
		else
			op(ps, OP_RA);
	}
	while (ps->b.size > 0)
	{
		bring_max_to_top(ps);
		op(ps, OP_PA);
	}
}
