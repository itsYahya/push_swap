/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahya <yahya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:03:59 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/24 13:11:23 by yahya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int	size;
	int	lenght;
}	t_data;

typedef struct s_twoatone
{
	int		*stack_a;
	t_data	*data_a;
	int		*stack_b;
	t_data	*data_b;
}	t_twoatone;

typedef struct s_var
{
	int	number;
	int	index;
	int	ko;
	int	go_up;
}	t_var;

t_var	ft_atoi(char *num);
void	swap_stack(int *stack, t_data data);
void	push_up(int	*stack, t_data data);
void	push_down(int *stack, t_data data);
void	push_to(int	*stack, int	*stack_to, t_data *data, t_data *data_to);
void	ft_init(t_twoatone *two, char **argv);
int		ft_sorted(int *stack, t_data data);
void	print_stack(int	*stack, t_data data);
void	sort_radix(t_twoatone *two);
void	ft_filter_0(t_twoatone *two, int index, int len, int i);
void	ft_filter_1(t_twoatone *two, int len, int i);
void	ft_finishing(t_twoatone *two, int len, int index);
void	sort_10(t_twoatone *two);
void	ft_sort_3(t_twoatone *two);
void	ft_bringtop(t_twoatone *two, t_var var);
t_var	ft_find_one(int *stack, t_data data);

#endif