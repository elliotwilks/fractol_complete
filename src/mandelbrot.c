/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:30:41 by elwilks           #+#    #+#             */
/*   Updated: 2026/03/12 11:41:16 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.r = 0;
	z.i = 0;
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
