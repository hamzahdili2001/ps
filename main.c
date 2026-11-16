/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 09:40:43 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 16:19:20 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bring_min_to_top(t_ps *ps);
int	main(int ac, char **av)
{
	t_ps	*ps;
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
	else
	{
		i = 0;
		while (i < ps->a.size)
			printf("%d ", stack_get(&ps->a, i++));
		printf("\nsize: %ld\n", ps->a.size);
		printf("cap: %ld\n", ps->a.cap);
		printf("mode: %d\n", ps->mode);
		printf("---------OP-------\n");
		bring_min_to_top(ps);
		printf("------------------\n");
		i = 0;
		while (i < ps->a.size)
			printf("%d ", stack_get(&ps->a, i++));
		printf("\nsize: %ld\n", ps->a.size);
		printf("cap: %ld\n", ps->a.cap);
		printf("mode: %d\n", ps->mode);
	}
	free(ps);
	return (0);
}
