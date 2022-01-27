/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahya <yahya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:46:59 by yahya             #+#    #+#             */
/*   Updated: 2022/01/27 11:59:42 by yahya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	ft_find_one(int *stack, t_data data)
{
	t_var	var;
	int		index;
	
	index = 0;
	var.index = 0;
	var.number = stack[var.index];
	while (index < data.lenght)
	{
		if (var.number > stack[index])
		{
			var.number = stack[index];
			var.index = index;
		}
		index++;
	}
	var.go_up = 1;
	if (var.index < data.lenght / 2)
		var.go_up = 0;
	return (var);
}

void	ft_bringtop(t_twoatone *two, t_var var)
{
	while (var.go_up)
	{
		if (var.number == two->stack_a[two->data_a->lenght - 1])
			return ;
		push_up(two->stack_a, *two->data_a);
		write(1, "ra\n", 3);
	}
	while (!var.go_up)
	{
		if (var.number == two->stack_a[two->data_a->lenght - 1])
			return ;
		push_down(two->stack_a, *two->data_a);
		write(1, "rra\n", 4);
	}
}

void	ft_sort_3(t_twoatone *two)
{
	t_var	var;
	
	var = ft_find_one(two->stack_a, *two->data_a);
	if (var.index == 0)
	{
		if (two->stack_a[2] < two->stack_a[1])
		{
			push_down(two->stack_a, *two->data_a);
			write(1, "rra\n", 4);
		}
		else 
		{
			swap_stack(two->stack_a, *two->data_a);
			write(1, "sa\n", 3);
			push_down(two->stack_a, *two->data_a);
			write(1, "rra\n", 4);
		}
	}
	else if (var.index == 1)
	{
		if (two->stack_a[2] > two->stack_a[0])
		{
			push_up(two->stack_a, *two->data_a);
			write(1, "ra\n", 3);
		}
		else
		{
			swap_stack(two->stack_a, *two->data_a);
			write(1, "sa\n", 3);
		}
	}
	else 
	{
		swap_stack(two->stack_a, *two->data_a);
		write(1, "sa\n", 3);
		push_up(two->stack_a, *two->data_a);
		write(1, "ra\n", 3);
	}
}

void	sort_10(t_twoatone *two)
{
	t_var	var;
	
	while (1)
	{
		if (ft_sorted(two->stack_a, *two->data_a) || two->data_a->lenght <= 3)
			break ;
		var = ft_find_one(two->stack_a, *two->data_a);
		ft_bringtop(two, var);
		push_to(two->stack_a, two->stack_b, two->data_a, two->data_b);
		write(1, "pb\n", 3);
	}
	if (!ft_sorted(two->stack_a, *two->data_a) && two->data_a->lenght == 3)
		ft_sort_3(two);
	else if (!ft_sorted(two->stack_a, *two->data_a) && two->data_a->lenght == 2)
	{
		swap_stack(two->stack_a, *two->data_a);
		write(1, "sa\n", 3);
	}
	while (two->data_b->lenght > 0)
	{
		push_to(two->stack_b, two->stack_a, two->data_b, two->data_a);
		write(1, "pa\n", 3);
	}
}