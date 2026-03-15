/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:28:33 by elwilks           #+#    #+#             */
/*   Updated: 2026/03/12 11:47:17 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_complex c, int max_iter)
{
	double		tmp;
	int			i;

	i = 0;
	while (i < max_iter)
	{
		if ((z.r * z.r + z.i * z.i) > 4.0)
			return (i);
		tmp = z.r * z.r - z.i * z.i + c.r;
		z.i = 2.0 * z.r * z.i + c.i;
		z.r = tmp;
		i++;
	}
	return (max_iter);
}
