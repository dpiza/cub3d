/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-camp <hde-camp@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:30:30 by hde-camp          #+#    #+#             */
/*   Updated: 2022/07/26 13:34:00 by hde-camp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <limits.h>

t_point	axis_collision(t_point position, t_point norm_dir, float x_factor)
{
	t_point	result;

	result.x = 0;
	result.y = 0;
	result.x = roundf((position.x + norm_dir.x * x_factor) * 10000)/10000;
	result.y = roundf((position.y + norm_dir.y * x_factor) * 10000)/10000;
	return (result);
}

t_collision	get_collision(t_cub3d *game, t_point norm_dir)
{
	float		sideDistX;
	float		sideDistY;
	float		deltaDistX;
	float		deltaDistY;
	int			hit;
	int			XYsteps[2];
	int			mapXY[2];
	t_collision	collision;
	float		wallDist;
	int			side;

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
			side = 1;
		}
		else
		{
			wallDist = sideDistY;
			sideDistY += deltaDistY;
			mapXY[1] += XYsteps[1];
			side = 0;
		}
		//Check if ray has hit a wall
		if (square_check(game, (float)mapXY[0], (float)mapXY[1]) == '1')
		{
			collision.point = axis_collision(game->player.pos, norm_dir, wallDist);
			collision.distance = wallDist;
			collision.perpDistance = wallDist * (norm_dir.x * game->player.dir.x + norm_dir.y * game->player.dir.y);
			if (side == 1)
			{
				if (norm_dir.x > 0)
					collision.side = WEST;
				else
					collision.side = EAST;
			}
			else
			{
				if (norm_dir.y > 0)
					collision.side = NORTH;
				else
					collision.side = SOUTH;
			}
			hit = 1;
		}
	}
	return (collision);
}