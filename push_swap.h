/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:03:59 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/21 20:51:59 by yel-mrab         ###   ########.fr       */
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

#endif