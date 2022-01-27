/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahya <yahya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:01:57 by yahya             #+#    #+#             */
/*   Updated: 2022/01/27 14:12:41 by yahya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_stack
{
	int	*arr;
	int	lenght;
	int	size;
}	t_stack;

typedef struct s_check
{
	int	number;
	int	check;
	int	index;
}	t_check;

int		ft_sorted(t_stack *stack);
void	swap_stack(t_stack *stack);
void	push_up(t_stack	*stack);
void	push_down(t_stack *stack);
void	push_to(t_stack *stack, t_stack	*stack_to);

#endif