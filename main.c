/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:03:33 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/21 20:34:34 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_var	ft_atoi(char *number)
{
	t_var	var;
	int		sign;

	var.index = 0;
	var.number = 0;
	var.ko = 0;
	sign = 1;
	if (number[var.index] == '-')
	{
		var.index++;
		sign = -1;
	}
	while (number[var.index] <= '9' && number[var.index] >= '0')
	{
		var.number = var.number * 10 + (number[var.index] - 48);
		var.index++;
	}
	var.number *= sign;
	if (number[var.index] != 0)
		var.ko = 1;
	return (var);
}

void	ft_free(t_twoatone *two, int cas)
{
	free(two->stack_b);
	free(two->stack_a);
	free(two->data_a);
	free(two->data_b);
	if (cas == 1)
	{
		write(1, "Error\n", 6);
		exit(cas);
	}
}

int	ft_is_it_there(t_twoatone *two, int number, int len)
{
	int	index;

	index = 0;
	while (index < two->data_a->lenght)
	{
		if (number == two->stack_a[len - index - 1])
			return (1);
		index++;
	}
	return (0);
}

void	ft_init(t_twoatone *two, char **argv)
{
	int		index;
	int		len;
	t_var	var;

	len = 1;
	while (argv[len])
		len++;
	two->data_a->lenght = 0;
	two->data_a->size = --len;
	index = 1;
	while (argv[index])
	{
		var = ft_atoi(argv[index]);
		if (var.ko || ft_is_it_there(two, var.number, len))
			ft_free(two, 1);
		two->stack_a[len - index] = var.number;
		two->stack_b[index - 1] = 0;
		index++;
		two->data_a->lenght += 1;
	}
	two->data_b->lenght = 0;
	two->data_b->size = two->data_a->size;
}

int	main(int argc, char **argv)
{
	t_twoatone	two_;

	if (argc > 1)
	{
		two_.stack_a = (int *)malloc(sizeof(int) * (argc - 1));
		two_.stack_b = (int *)malloc(sizeof(int) * (argc - 1));
		two_.data_a = (t_data *)malloc(sizeof(t_data));
		two_.data_b = (t_data *)malloc(sizeof(t_data));
		ft_init(&two_, argv);
		if (!ft_sorted(two_.stack_a, *two_.data_a))
			sort_radix(&two_);
		ft_free(&two_, 0);
	}
	return (0);
}
