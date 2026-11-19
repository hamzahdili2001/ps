/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:40:43 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/19 14:53:54 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*ps;
	t_flags	*flag;
	int		i;

	ps = malloc(sizeof(t_ps));
	if (!ps)
		return (-1);
	ps_init(ps);
	if (parse_args(ac, av, ps) < 0)
	{
		ft_putendl_fd("Error", 1);
		return (-1);
	}
	if (is_sorted(ps) == 0)
		return (1);
	if (ps->mode == MODE_SIMPLE)
		sort_simple(ps);
	if (ps->mode == MODE_MEDIUM)
		sort_medium(ps);
	free(ps);
	return (0);
}
