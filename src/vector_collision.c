/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:30:30 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/21 17:09:12 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <limits.h>

enum	e_player_direction{
	NORTH = 0,
	NE = 1,
	EAST = 2,
	SE = 3,
	SOUTH = 4,
	SW = 5,
	WEST = 6,
	NW = 7
};

int	determine_direction(t_point *dir)
{
	if (dir->x == 0)
	{
		if (dir->y > 0)
			return (SOUTH);
		return (NORTH);
	}
	if (dir->y == 0)
	{
		if (dir->x > 0)
			return (EAST);
		return (WEST);
	}
	if (dir->x > 0)
	{
		if (dir->y > 0)
			return (SE);
		return (NE);
	}
	if (dir->x < 0)
	{
		if (dir->y > 0)
			return (SW);
		return (NW);
	}
	return (-1);
};

t_point	axis_collision(t_point position, t_point norm_dir, float x_factor)
{
	t_point	result;

	result.x = 0;
	result.y = 0;
	result.x = roundf((position.x + norm_dir.x * x_factor) * 10000)/10000;
	result.y = roundf((position.y + norm_dir.y * x_factor) * 10000)/10000;
	return (result);
}

t_point	get_first_collision_dda(t_cub3d *game, t_point norm_dir)
{
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	int		hit;
	int		XYsteps[2];
	int		mapXY[2];
	t_point	collision;
	float	wallDist;
	//int		side;

	// Initialize default values;
	deltaDistX = __FLT_MAX__;
	deltaDistY = __FLT_MAX__;
	sideDistX = 0;
	sideDistY = 0;
	if (norm_dir.x != 0)
		deltaDistX = fabs(1 / norm_dir.x);
	if (norm_dir.y != 0)
		deltaDistY = fabs(1 / norm_dir.y);
	//define steps
	XYsteps[0] = 1;
	XYsteps[1] = 1;
	if (norm_dir.x < 0)
		XYsteps[0] = -1;
	if (norm_dir.y < 0)
		XYsteps[1] = -1;
	mapXY[0] = (int)game->player.pos.x;
	mapXY[1] = (int)game->player.pos.y;
	// calculate step and initial sideDist
	if (norm_dir.x < 0)
		sideDistX = (game->player.pos.x - (int)game->player.pos.x) * deltaDistX;
	else
		sideDistX = ((int)game->player.pos.x + 1.0 - game->player.pos.x) * deltaDistX;
	if (norm_dir.y < 0)
		sideDistY = (game->player.pos.y - (int)game->player.pos.y) * deltaDistY;
	else
		sideDistY = ((int)game->player.pos.y + 1.0 - game->player.pos.y) * deltaDistY;

	////perform DDA
	hit = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			wallDist = sideDistX;
			sideDistX += deltaDistX;
			mapXY[0] += XYsteps[0];
			//side = 1;
		}
		else
		{
			wallDist = sideDistY;
			sideDistY += deltaDistY;
			mapXY[1] += XYsteps[1];
			//side = 0;
		}
		//Check if ray has hit a wall
		if (square_check(game, (float)mapXY[0], (float)mapXY[1]) == '1')
		{
			collision = axis_collision(game->player.pos, norm_dir, wallDist);
			hit = 1;
		}
		//if (square_dir_check(game, &collision, &norm_dir) == '1')
		//	hit = 1;
	}
	printf("Collision xy: %.2f\t%.2f\n", collision.x, collision.y);
	// printf("Side hit: %i\n", side);
	// printf("Wall Distance: %.4f\n", wallDist);
	return (collision);
}

t_collision	get_collision(t_cub3d *game, t_point norm_dir)
{
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	int		hit;
	int		XYsteps[2];
	int		mapXY[2];
	t_collision	collision;
	float	wallDist;
	//int		side;

	// Initialize default values;
	deltaDistX = __FLT_MAX__;
	deltaDistY = __FLT_MAX__;
	sideDistX = 0;
	sideDistY = 0;
	if (norm_dir.x != 0)
		deltaDistX = fabs(1 / norm_dir.x);
	if (norm_dir.y != 0)
		deltaDistY = fabs(1 / norm_dir.y);
	//define steps
	XYsteps[0] = 1;
	XYsteps[1] = 1;
	if (norm_dir.x < 0)
		XYsteps[0] = -1;
	if (norm_dir.y < 0)
		XYsteps[1] = -1;
	mapXY[0] = (int)game->player.pos.x;
	mapXY[1] = (int)game->player.pos.y;
	// calculate step and initial sideDist
	if (norm_dir.x < 0)
		sideDistX = (game->player.pos.x - (int)game->player.pos.x) * deltaDistX;
	else
		sideDistX = ((int)game->player.pos.x + 1.0 - game->player.pos.x) * deltaDistX;
	if (norm_dir.y < 0)
		sideDistY = (game->player.pos.y - (int)game->player.pos.y) * deltaDistY;
	else
		sideDistY = ((int)game->player.pos.y + 1.0 - game->player.pos.y) * deltaDistY;

	////perform DDA
	hit = 0;
	while (hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (sideDistX < sideDistY)
		{
			wallDist = sideDistX;
			sideDistX += deltaDistX;
			mapXY[0] += XYsteps[0];
			//side = 1;
		}
		else
		{
			wallDist = sideDistY;
			sideDistY += deltaDistY;
			mapXY[1] += XYsteps[1];
			//side = 0;
		}
		//Check if ray has hit a wall
		if (square_check(game, (float)mapXY[0], (float)mapXY[1]) == '1')
		{
			collision.point = axis_collision(game->player.pos, norm_dir, wallDist);
			collision.distance = wallDist;
			collision.perpDistance = wallDist;
			hit = 1;
		}
		//if (square_dir_check(game, &collision, &norm_dir) == '1')
		//	hit = 1;
	}
	printf("Collision xy: %.2f\t%.2f\n", collision.point.x, collision.point.y);
	// printf("Side hit: %i\n", side);
	// printf("Wall Distance: %.4f\n", wallDist);
	return (collision);
}