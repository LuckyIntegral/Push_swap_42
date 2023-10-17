/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfrants <vfrants@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:46:06 by vfrants           #+#    #+#             */
/*   Updated: 2023/10/08 18:32:00 by vfrants          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_data *data, char *status)
{
	if (data)
	{
		ft_free(data->a.stack);
		ft_free(data->b.stack);
	}
	ft_printf("Error, %s\n", status);
	exit(1);
}
