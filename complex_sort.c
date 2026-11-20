/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:44:36 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/20 13:23:47 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bit(int n)
{
	int	max_rank;
	int	max_bit;

	max_bit = 0;
	max_rank = n - 1;
	while (max_rank > 0)
	{
		max_rank /= 2;
		max_bit++;
	}
	return (max_bit);
}

int	sort_complex(t_ps *ps)
{
	size_t	n;
	size_t	i;
	int		bit;
	int		max_bit;
	int		x;

	bit = 0;
	n = ps->a.size;
	max_bit = get_max_bit(n);
	if (assign_ranks(&ps->a) < 0)
		return (-1);
	while (bit < max_bit)
	{
		i = 0;
		while (i < n)
		{
			x = stack_get(&ps->a, 0);
			if ((x >> bit) & 1)
				op(ps, OP_RA);
			else
				op(ps, OP_PB);
			i++;
		}
		while (ps->b.size > 0)
			op(ps, OP_PA);
		bit++;
	}
	return (0);
}
