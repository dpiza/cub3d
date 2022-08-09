/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:30:04 by dpiza             #+#    #+#             */
/*   Updated: 2022/08/07 20:38:49 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_mlx_img	*load_texture(t_cub3d *game, char *filename)
{
	t_mlx_img		*img;

	img = ft_calloc(1, sizeof(t_mlx_img));
	img->mlx = game->mlx;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx->mlx_ptr, \
		filename, &img->width, &img->height);
	img->data = mlx_get_data_addr(img->img_ptr, &(img->bpp), \
		&(img->line_size), &(img->endian));
	return (img);
}

void	load_map_assets(t_cub3d *game)
{
	game->texture.no = load_texture(game, game->s_map->no_path);
	game->texture.so = load_texture(game, game->s_map->so_path);
	game->texture.ea = load_texture(game, game->s_map->ea_path);
	game->texture.we = load_texture(game, game->s_map->we_path);
	game->texture.door = load_texture(game, "./textures/lab/door.xpm");
	game->texture.pc = load_texture(game, "./textures/lab/k.xpm");
	game->texture.exit = load_texture(game, "./textures/lab/exit.xpm");
}

void	load_sprites_assets(t_cub3d *game)
{
	game->texture.scor01 = load_texture(game, \
		"./textures/sprites/scorched/01.xpm");
	game->texture.scor02 = load_texture(game, \
		"./textures/sprites/scorched/02.xpm");
	game->texture.scor03 = load_texture(game, \
		"./textures/sprites/scorched/03.xpm");
	game->texture.scor16 = load_texture(game, \
		"./textures/sprites/scorched/16.xpm");
	game->texture.scor17 = load_texture(game, \
		"./textures/sprites/scorched/17.xpm");
	game->texture.scor18 = load_texture(game, \
		"./textures/sprites/scorched/18.xpm");
	game->texture.scor19 = load_texture(game, \
		"./textures/sprites/scorched/19.xpm");
	game->texture.scor20 = load_texture(game, \
		"./textures/sprites/scorched/20.xpm");
	game->texture.cods00 = load_texture(game, \
		"./textures/sprites/codesworth/cods00.xpm");
	game->texture.cods01 = load_texture(game, \
		"./textures/sprites/codesworth/cods01.xpm");
}

void	load_assets(t_cub3d *game)
{
	unsigned char	*floor;
	unsigned char	*ceiling;

	floor = game->s_map->floor_c;
	ceiling = game->s_map->ceilling_c;
	game->floor = floor[0] << 16 | floor[1] << 8 | floor[2];
	game->ceilling = ceiling[0] << 16 | ceiling[1] << 8 | ceiling[2];
	load_map_assets(game);
	load_hud_assets(game);
	load_sprites_assets(game);
	game->texture.standby = load_texture(game, \
		"./textures/hud/standby.xpm");
	game->texture.dmg = load_texture(game, \
		"./textures/hud/dmg.xpm");
}
