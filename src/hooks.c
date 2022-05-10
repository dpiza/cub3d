/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:01:01 by dpiza             #+#    #+#             */
/*   Updated: 2022/05/10 17:16:16 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	set_img_black(t_cub3d *game)
{
	int	l;
	int	c;
	t_mlx_img	*img;

	l = 0;
	img = game->mlx->img;
	while ( l < 20)
	{
		c = 0;
		while ( c < 20)
		{
			((unsigned int *)img->data)[l * img->width + c] = 0x00000000;
			c++;
		}
		l++;
	}
}

void	set_img_white(t_cub3d *game)
{
	int	l;
	int	c;
	t_mlx_img	*img;

	l = 0;
	img = game->mlx->img;
	while ( l < 20)
	{
		c = 0;
		while ( c < 20)
		{
			((unsigned int *)img->data)[l * img->width + c] = 0x00ffffff;
			c++;
		}
		l++;
	}
}

int	key_hook(int k, t_cub3d *game)
{
	if (k == 0xff1b) // ESC
		mlx_loop_end(game->mlx->mlx_ptr);
	if (k == 0x0061 || k == 0x0041)
	{
		set_img_black(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->img->img_ptr, 0, 0);
		printf("a pressed\n");
	}
	if (k == 0x0073 || k == 0x0053)
	{
		set_img_white(game);
		mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr, game->mlx->img->img_ptr, 0, 0);
		printf("s pressed\n");
	}
	if (k == 0x0064 || k == 0x0044)
		printf("d pressed\n");
	if (k == 0x0077 || k == 0x0057)
		printf("w pressed\n");
	if (k == 0x0070 || k == 0x0050)
		printf("p pressed\n");
	if (k == 0xff0d)
		printf("return pressed\n");
	/*
	teclas de interesse:
				normal		UPPERCASE
	a			0x0061		0x0041
	s			0x0073		0x0053
	d			0x0064		0x0044
	w			0x0077		0x0057
	p			0x0070		0x0050
	escape		0xff1b
	enter		0xff0d
	uparrow		0xff52
	downarrow	0xff54
	leftarrow	0xff51
	rightarrow	0xff53
	*/
	return (0);
}