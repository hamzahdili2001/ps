/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 12:00:33 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/16 12:24:16 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*op_name(t_op code)
{
	static const char	*ops[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb", "ra",
			"rb", "rr", "rra", "rrb", "rrr"};

	if (code < 0 || code >= OP_COUNT)
		return ("");
	return (ops[code]);
}

static void	pushes(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	stack_push(to, stack_pop(from));
}

static void	stack_pushes(t_ps *ps, t_op code)
{
	if (code == OP_PA)
		pushes(&ps->b, &ps->a);
	if (code == OP_PB)
		pushes(&ps->a, &ps->b);
}

static void	stack_swaps(t_ps *ps, t_op code)
{
	if (code == OP_SA || code == OP_SS)
		stack_swap(&ps->a);
	if (code == OP_SB || code == OP_SS)
		stack_swap(&ps->b);
}

static void	stack_rotations(t_ps *ps, t_op code)
{
	if (code == OP_RA || code == OP_RR)
		stack_rotate(&ps->a);
	if (code == OP_RB || code == OP_RR)
		stack_rotate(&ps->b);
}

static void	stack_rrotations(t_ps *ps, t_op code)
{
	if (code == OP_RRA || code == OP_RRR)
		stack_rrotate(&ps->a);
	if (code == OP_RRB || code == OP_RRR)
		stack_rrotate(&ps->b);
}

static void	op_apply(t_ps *ps, t_op code)
{
	stack_swaps(ps, code);
	stack_pushes(ps, code);
	stack_rotations(ps, code);
	stack_rrotations(ps, code);
}

void	op(t_ps *ps, t_op code)
{
	op_apply(ps, code);
	ps->ops_count++;
	ps->op_counts[code]++;
	if (ps->silent)
		return ;
	ft_putendl_fd((char *)op_name(code), 1);
}

void	op_repeat(t_ps *ps, t_op code, int n)
{
	while (n-- > 0)
		op(ps, code);
}
