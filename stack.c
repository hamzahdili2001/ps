/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 15:27:40 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 11:00:59 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_allocate(t_stack *s, size_t cap)
{
	s->data = malloc(sizeof(int) * cap);
	if (!(s->data))
		return (-1);
	s->cap = cap;
	s->head = 0;
	s->size = 0;
	return (0);
}

int	stack_get(t_stack *s, int index)
{
	return (s->data[(s->head + index) % s->cap]);
}

void	stack_push(t_stack *s, int v)
{
	if (s->size >= s->cap)
		return ;
	s->head = (s->head - 1 + s->cap) % s->cap;
	s->data[s->head] = v;
	s->size++;
}

int	stack_pop(t_stack *s)
{
	int	v;

	if (s->size == 0)
		return (0);
	v = s->data[s->head % s->cap];
	s->head = (s->head + 1) % s->cap;
	s->size--;
	return (v);
}

void	stack_swap(t_stack *s)
{
	int	i0;
	int	i1;
	int	tmp;

	if (s->size < 2)
		return ;
	i0 = s->head;
	i1 = (s->head + 1) % s->cap;
	tmp = s->data[i1];
	s->data[i1] = s->data[i0];
	s->data[i0] = tmp;
}

void	stack_rotate(t_stack *s)
{
	int	v;

	if (s->size < 2)
		return ;
	v = stack_get(s, 0);
	s->head = (s->head + 1) % s->cap;
	s->data[(s->head + s->size - 1) % s->cap] = v;
}

void	stack_rrotate(t_stack *s)
{
	int	v;

	if (s->size < 2)
		return ;
	v = stack_get(s, s->size - 1);
	s->head = (s->head - 1 + s->cap) % s->cap;
	s->data[s->head] = v;
}
