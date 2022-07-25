/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:30:04 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/25 10:18:46 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_img	*load_texture(t_cub3d *game, char *filename, int width, int height)
{
	t_mlx_img		*img;

	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, filename, &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	img->width = width;
	img->height = height;
	return (img);
}

void	load_assets(t_cub3d *game)
{
	unsigned char	*floor;
	unsigned char	*ceiling;
	
	floor = game->s_map->floor_c;
	ceiling = game->s_map->ceilling_c;
	game->texture_no = load_texture(game, game->s_map->no_path, 64, 64);
	game->texture_so = load_texture(game, game->s_map->so_path, 64, 64);
	game->texture_ea = load_texture(game, game->s_map->ea_path, 64, 64);
	game->texture_we = load_texture(game, game->s_map->we_path, 64, 64);
	game->bar = load_texture(game, "./textures/bar/fo_bar_nuk3d.xpm", 255, 126);
	game->bar_screen = load_texture(game, "./textures/bar/fo_bar_screen_painted.xpm", 255, 126);
	game->weapon = load_texture(game, "./textures/weapon/weapon_01.xpm", 98, 164);
	game->crosshair = load_texture(game, "./textures/crosshair.xpm", 13, 13);
	game->floor = floor[0] << 16 | floor[1] << 8 | floor[2];
	game->ceilling = ceiling[0] << 16 | ceiling[1] << 8 | ceiling[2];
	// printf("Floor: %i\nCeilling: %i\n", game->floor, game->ceilling);
}