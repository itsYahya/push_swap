/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahya <yahya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:05:29 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/27 11:59:55 by yahya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(int *stack, t_data data)
{
	int	index;

	index = 0;
	if (data.lenght == 0)
		return (0);
	while (index < data.lenght - 1)
	{
		if (stack[index] < stack[index + 1])
			return (0);
		index++;
	}
	return (1);
}

void	swap_stack(int *stack, t_data data)
{
	int	swap;

	swap = stack[data.lenght - 1];
	stack[data.lenght - 1] = stack[data.lenght - 2];
	stack[data.lenght - 2] = swap;
}

void	push_up(int	*stack, t_data data)
{
	int	swap;
	int	index;

	index = data.lenght - 1;
	swap = stack[index];
	while (index > 0)
	{
		stack[index] = stack[index - 1];
		index--;
	}
	stack[index] = swap;
}

void	push_down(int *stack, t_data data)
{
	int	index;
	int	swap;

	index = 0;
	swap = stack[index];
	while (index < data.lenght)
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[data.lenght - 1] = swap;
}

void	push_to(int	*stack, int	*stack_to, t_data *data, t_data *data_to)
{
	stack_to[data_to->lenght] = stack[data->lenght - 1];
	data_to->lenght += 1;
	data->lenght -= 1;
}
