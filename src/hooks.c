/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:28:02 by elwilks           #+#    #+#             */
/*   Updated: 2026/03/15 18:54:13 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	close_hook(void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	mlx_close_window(f->mlx);
}

static void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	(void)xdelta;
	if (ydelta > 0)
		f->zoom *= 0.9;
	else
		f->zoom *= 1.1;
	render(f);
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*f;

	f = (t_fractol *)param;
	if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(f->mlx);
	else if (keydata.key == MLX_KEY_LEFT)
		f->offset_x -= 0.1 * f->zoom * WIDTH;
	else if (keydata.key == MLX_KEY_RIGHT)
		f->offset_x += 0.1 * f->zoom * WIDTH;
	else if (keydata.key == MLX_KEY_UP)
		f->offset_y -= 0.1 * f->zoom * HEIGHT;
	else if (keydata.key == MLX_KEY_DOWN)
		f->offset_y += 0.1 * f->zoom * HEIGHT;
	render(f);
}

void	setup_hooks(t_fractol *f)
{
	mlx_scroll_hook(f->mlx, scroll_hook, f);
	mlx_key_hook(f->mlx, key_hook, f);
	mlx_close_hook(f->mlx, close_hook, f);
}
