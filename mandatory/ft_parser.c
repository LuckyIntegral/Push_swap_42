/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:05:33 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/17 22:23:08 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parse_strings(t_data *data, int *c, char **v, int *flag)
{
	char	**strs;
	int		i;

	if (*c == 2)
	{
		if (ft_is_blank(v[1]))
			ft_error(data, INVALID_ARGS);
		strs = ft_split(v[1], ' ');
		if (!strs)
			ft_error(data, MALLOC_FAIL);
		if (!*strs)
			ft_error(data, INVALID_ARGS);
		i = 0;
		while (strs[i])
			i++;
		(free(NULL), *c = i, *flag = 1);
	}
	else
	{
		strs = ++v;
		if (ft_is_blank(*strs))
			ft_error(data, INVALID_ARGS);
		*c = *c - 1;
	}
	return (strs);
}

static void	validate_numbers(t_data *data, char **strs, int c, int flag)
{
	int	i;

	i = 0;
	while (i < c)
	{
		if (ft_is_blank(strs[i]) || ft_is_int_overflow(strs[i]))
		{
			if (flag)
				ft_free_split(strs);
			ft_error(data, INVALID_ARGS);
		}
		i++;
	}
}

static void	parse_numbers(t_data *data, char **strs, int count, int flag)
{
	int	i;

	data->a.stack = ft_calloc(sizeof (int), count);
	if (!data->a.stack)
	{
		if (flag)
			ft_free_split(strs);
		ft_error(data, MALLOC_FAIL);
	}
	data->a.size = count;
	data->b.stack = ft_calloc(sizeof (int), count);
	if (!data->b.stack)
	{
		if (flag)
			ft_free_split(strs);
		ft_error(data, MALLOC_FAIL);
	}
	data->b.size = 0;
	data->size = count;
	i = 0;
	while (i < count)
	{
		data->a.stack[i] = ft_atoi(strs[i]);
		i++;
	}
}

static void	check_distinct(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->a.size)
	{
		j = 0;
		while (j < i)
		{
			if (data->a.stack[i] == data->a.stack[j])
				ft_error(data, INVALID_ARGS);
			j++;
		}
		i++;
	}
}

void	ft_parse_arguments(t_data *data, int count, char **v)
{
	char	**numbers;
	int		split_flag;

	split_flag = 0;
	numbers = parse_strings(data, &count, v, &split_flag);
	validate_numbers(data, numbers, count, split_flag);
	parse_numbers(data, numbers, count, split_flag);
	if (split_flag)
		ft_free_split(numbers);
	check_distinct(data);
}
