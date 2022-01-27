/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahya <yahya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:05:29 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/27 14:09:45 by yahya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_sorted(t_stack *stack)
{
	int	index;

	index = 0;
	if (stack->lenght == 0)
		return (0);
	while (index < stack->lenght - 1)
	{
		if (stack->arr[index] < stack->arr[index + 1])
			return (0);
		index++;
	}
	return (1);
}

void	swap_stack(t_stack *stack)
{
	int	swap;

	swap = stack->arr[stack->lenght - 1];
	stack->arr[stack->lenght - 1] = stack->arr[stack->lenght - 2];
	stack->arr[stack->lenght - 2] = swap;
}

void	push_up(t_stack	*stack)
{
	int	swap;
	int	index;

	index = stack->lenght - 1;
	swap = stack->arr[index];
	while (index > 0)
	{
		stack->arr[index] = stack->arr[index - 1];
		index--;
	}
	stack->arr[index] = swap;
}

void	push_down(t_stack *stack)
{
	int	index;
	int	swap;

	index = 0;
	swap = stack->arr[index];
	while (index < stack->lenght)
	{
		stack->arr[index] = stack->arr[index + 1];
		index++;
	}
	stack->arr[stack->lenght - 1] = swap;
}

void	push_to(t_stack *stack, t_stack	*stack_to)
{
	stack_to->arr[stack_to->lenght] = stack->arr[stack->lenght - 1];
	stack_to->lenght += 1;
	stack->lenght -= 1;
}
