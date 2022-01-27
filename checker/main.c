/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahya <yahya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:01:39 by yahya             #+#    #+#             */
/*   Updated: 2022/01/27 14:34:31 by yahya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <stdlib.h>

t_check	ft_atoi(char *number)
{
	t_check	check;
	int		sign;

	check.index = 0;
	check.number = 0;
	check.check = 0;
	sign = 1;
	if (number[check.index] == '-')
	{
		check.index++;
		sign = -1;
	}
	while (number[check.index] <= '9' && number[check.index] >= '0')
	{
		check.number = check.number * 10 + (number[check.index] - 48);
		check.index++;
	}
	check.number *= sign;
	if (number[check.index] != 0)
		check.check = 1;
	return (check);
}

int	ft_is_it_there(t_stack *stka, int number, int len)
{
	int	index;

	index = 0;
	while (index < stka->lenght)
	{
		if (number == stka->arr[len - index - 1])
			return (1);
		index++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *line, char ch)
{
	char	*tmp;
	int		len;
	int		index;
	
	if (line)
		len = ft_strlen(line);
	else
	 	len = 0;
	tmp = (char *)malloc(sizeof(char) * len + 2);
	index = 0;
	if (line)
	{
		while (line[index])
		{
			tmp[index] = line[index];
			index++;
		}
		free(line);
	}
	tmp[index++] = ch;
	tmp[index] = 0;
	return (tmp);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	index;

	index = 0;
	while (str1[index] == str2[index] && str2[index])
		index++;
	return (str2[index] - str1[index]);
}

int	ft_inst_tomake(char *inst, t_stack *stka, t_stack *stkb)
{
	if (ft_strcmp(inst, "ra") == 0)
		push_up(stka);
	else if (ft_strcmp(inst, "rb") == 0)
		push_up(stkb);
	else if (ft_strcmp(inst, "rra") == 0)
		push_down(stka);
	else if (ft_strcmp(inst, "rrb") == 0)
		push_down(stkb);
	else if (ft_strcmp(inst, "pa") == 0)
		push_to(stkb, stka);
	else if (ft_strcmp(inst, "pb") == 0)
		push_to(stka, stkb);
	else if (ft_strcmp(inst, "sa") == 0)
		swap_stack(stka);
	else if (ft_strcmp(inst, "sb") == 0)
		swap_stack(stkb);
	return (0);
}

void	ft_check(t_stack *stka, t_stack *stkb)
{
	char	ch;
	int		index;
	char	*inst = NULL;
	index = 0;
	while (1)
	{
		ch = 0;
		if (read(0, &ch, 1) != 1)
			break ;
		if (ch == 10 && inst)
		{
			ft_inst_tomake(inst, stka, stkb);
			free(inst);
			inst = 0;
		}
		else
			inst = ft_strjoin(inst, ch);
	}
}

int	ft_init(t_stack *stka, t_stack *stkb, int len, char **argv)
{
	int		index;
	t_check	check;
	
	index = 0;
	stka->lenght = 0;
	stka->size = len;
	while (argv[index])
	{
		check = ft_atoi(argv[index]);
		if (check.check || ft_is_it_there(stka, check.number, len))
			return (0);
		stka->arr[len - index - 1] = check.number;
		index++;
		stka->lenght++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stka;
	t_stack	stkb;
	
	stka.arr = (int *)malloc(sizeof(int) * (argc - 1));
	stkb.arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (!ft_init(&stka, &stkb, argc - 1, ++argv))
	{
		free(stka.arr);
		free(stkb.arr);
		write(1, "Error\n", 6);
		return (0);
	}
	else
		ft_check(&stka, &stkb);
	return (0);
}