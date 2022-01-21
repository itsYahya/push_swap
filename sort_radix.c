/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:02:53 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/21 21:04:28 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_filter_0(t_twoatone *two, int index, int len, int i)
{
	while (index < len)
	{
		if ((two->stack_a[two->data_a->lenght - 1] >> i & 1) == 1)
		{
			push_up(two->stack_a, *two->data_a);
			write(1, "ra\n", 3);
		}
		else
		{
			push_to(two->stack_a, two->stack_b, two->data_a, two->data_b);
			write(1, "pb\n", 3);
		}
		index++;
	}
}

void	ft_filter_1(t_twoatone *two, int len, int i)
{
	while (len-- > 0)
	{
		if ((two->stack_b[two->data_b->lenght - 1] >> i & 1) == 1)
		{
			write(1, "pa\n", 3);
			push_to(two->stack_b, two->stack_a, two->data_b, two->data_a);
		}
		else
		{
			write(1, "rb\n", 3);
			push_up(two->stack_b, *two->data_b);
		}
	}
}

void	ft_finishing(t_twoatone *two, int len, int index)
{
	while (two->data_b->lenght > 0)
	{
		write(1, "pa\n", 3);
		push_to(two->stack_b, two->stack_a, two->data_b, two->data_a);
	}
	len = two->data_a->lenght;
	while (two->stack_a[0] < 0 && index < len)
	{
		push_down(two->stack_a, *two->data_a);
		write(1, "rra\n", 4);
		index++;
	}
}

void	sort_radix(t_twoatone *two)
{
	int	i;

	i = 0;
	while (1)
	{
		ft_filter_0(two, 0, two->data_a->lenght, i);
		i++;
		ft_filter_1(two, two->data_b->lenght, i);
		if (ft_sorted(two->stack_a, *two->data_a))
		{
			ft_finishing(two, 0, 0);
			break ;
		}
	}
}
