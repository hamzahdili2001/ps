/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nums.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:38:27 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 09:42:46 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_nums(int ac, char **av, int start)
{
	size_t	count;
	size_t	token;
	int		i;

	count = 0;
	i = 0;
	while (start + i < ac)
	{
		token = token_count(av[start + i]);
		if (token == 0)
			return (0);
		count += token;
		i++;
	}
	return (count);
}

static int	fill_ints(int ac, char **av, t_stack *s, int start)
{
	int		*nums;
	int		i;
	size_t	count;
	size_t	k;

	i = 0;
	while (start + i < ac)
	{
		nums = ft_split(av[start + i], &count);
		if (!nums)
			return (-1);
		k = 0;
		while (k < count)
			stack_push(s, nums[k++]);
		free(nums);
		i++;
	}
	return (0);
}

static int	check_sup(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i < s->size)
	{
		j = i + 1;
		while (j < s->size)
		{
			if (stack_get(s, i) == stack_get(s, j))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(int ac, char **av, t_ps *ps)
{
	int	start;
	int	total;

	start = parse_flags(ac, av, ps);
	if (start < 0 || start >= ac)
		return (-1);
	total = count_nums(ac, av, start);
	if (total == 0)
		return (-1);
	if (stack_allocate(&ps->a, total) == -1)
		return (-1);
	if (stack_allocate(&ps->b, total) == -1)
		return (-1);
	if (fill_ints(ac, av, &ps->a, start) == -1)
		return (-1);
	if (check_sup(&ps->a) == -1)
		return (-1);
	return (0);
}
