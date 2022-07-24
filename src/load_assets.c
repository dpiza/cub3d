/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:30:04 by dpiza             #+#    #+#             */
/*   Updated: 2022/07/24 12:02:10 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

t_mlx_img	*load_texture(t_cub3d *game, char *filename)
{
	t_mlx_img		*img;
	int				width;
	int				height;

	width = 64;
	height = 64;
	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, filename, &width, &height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), &(img->line_size), &(img->endian));
	return (img);
}

void	load_assets(t_cub3d *game)
{
	unsigned char	*floor;
	unsigned char	*ceiling;
	
	floor = game->s_map->floor_c;
	ceiling = game->s_map->ceilling_c;
	game->texture_no = load_texture(game, game->s_map->no_path);
	game->texture_so = load_texture(game, game->s_map->so_path);
	game->texture_ea = load_texture(game, game->s_map->ea_path);
	game->texture_we = load_texture(game, game->s_map->we_path);
	game->floor = floor[0] << 16 | floor[1] << 8 | floor[2];
	game->ceilling = ceiling[0] << 16 | ceiling[1] << 8 | ceiling[2];
	// printf("Floor: %i\nCeilling: %i\n", game->floor, game->ceilling);
}