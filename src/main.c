/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <elwilks@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:30:26 by elwilks           #+#    #+#             */
/*   Updated: 2026/03/12 12:04:17 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	usage(void)
{
	ft_putstr("Usage:\n");
	ft_putstr("  ./fractol mandelbrot\n");
	ft_putstr("  ./fractol julia <real> <imag>\n");
	ft_putstr("Example: ./fractol julia -0.7 0.27015\n");
	exit(1);
}

static void	parse_args(int argc, char **argv, t_fractol *f)
{
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		f->fractal_type = 0;
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && argc == 4)
	{
		f->fractal_type = 1;
		f->julia_r = ft_atof(argv[2]);
		f->julia_i = ft_atof(argv[3]);
	}
	else
		usage();
}

static void	init_defaults(t_fractol *f)
{
	f->zoom = 0.004;
	f->offset_x = 0.0;
	f->offset_y = 0.0;
}

static void	init_mlx(t_fractol *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (!f->mlx)
		exit(1);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		exit(1);
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2)
		usage();
	parse_args(argc, argv, &f);
	init_defaults(&f);
	init_mlx(&f);
	render(&f);
	setup_hooks(&f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
