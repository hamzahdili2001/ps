/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:56:54 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/17 09:12:03 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *s)
{
	int	i;
	int	min_idx;

	i = 1;
	min_idx = 0;
	while (i < (int)s->size)
	{
		if (stack_get(s, i) < stack_get(s, min_idx))
			min_idx = i;
		i++;
	}
	return (min_idx);
}

static void	bring_min_to_top(t_ps *ps)
{
	size_t	size;
	int		min_idx;
	int		i;

	size = ps->a.size;
	min_idx = find_min_index(&ps->a);
	if (min_idx <= (int)(size / 2))
	{
		i = 0;
		while (i < min_idx)
		{
			op(ps, OP_RA);
			i++;
		}
	}
	else
	{
		i = size - min_idx;
		while (i > 0)
		{
			op(ps, OP_RRA);
			i--;
		}
	}
}

static void	sort_2(t_ps *ps)
{
	int	a;
	int	b;

	a = stack_get(&ps->a, 0);
	b = stack_get(&ps->b, 1);
	if (b < a)
		op(ps, OP_RA);
}

static void	sort_3(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = stack_get(&ps->a, 0);
	b = stack_get(&ps->a, 1);
	c = stack_get(&ps->a, 2);
	if (a > b && b < c && a < c)
		op(ps, OP_SA);
	else if (a > b && b > c && a > c)
	{
		op(ps, OP_SA);
		op(ps, OP_RRA);
	}
	else if (a > b && b < c && a > c)
		op(ps, OP_RA);
	else if (a < b && b > c && a < c)
	{
		op(ps, OP_SA);
		op(ps, OP_RA);
	}
	else if (a < b && b > c && a > c)
		op(ps, OP_RRA);
}

void	sort_small(t_ps *ps)
{
	if (ps->a.size == 2)
		sort_2(ps);
	if (ps->a.size == 3)
		sort_3(ps);
}

void	sort_simple(t_ps *ps)
{
	while (ps->a.size > 3)
	{
		bring_min_to_top(ps);
		op(ps, OP_PB);
	}
	sort_small(ps);
	while (ps->b.size > 0)
		op(ps, OP_PA);
}
