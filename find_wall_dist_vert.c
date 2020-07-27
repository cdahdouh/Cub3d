#include "test1.h"

coord	first_vert_point(double ray_orientation, player p) //OK
{
	coord	point;

	if (ray_is_left(ray_orientation)) // Le rayon pointe vers la gauche
		point.x = ((int)p.pos.x / LONG_CUB) * 64 - 1;
	else // le rayon pointe vers la droite
		point.x = ((int)p.pos.x / LONG_CUB) * 64 + 64;
	point.y = p.pos.y + (p.pos.x - point.x) * tan(ray_orientation);

	return (point);
}

coord	find_wall_point_vert(double ray_orientation, int **map, player p)
{
	coord	vert_check;
	double	x_step = ray_is_left(ray_orientation) ? -LONG_CUB : LONG_CUB;
	double	y_step = -1 * x_step * tan(ray_orientation);
	
	vert_check = first_vert_point(ray_orientation, p);
	while (!is_out_map(vert_check, map) && !is_wall(vert_check, map))
	{
		vert_check.x += x_step;
		vert_check.y += y_step;
	}
	/* if (is_out_map(vert_check, map)) */
	/* { */
	/* 	vert_check.x = -1; */
	/* 	vert_check.y = -1; */
	/* } */
	return (vert_check);
}

double	find_wall_dist_vert(double ray_orientation, int **map, player p)
{
	coord	wall_point_vert;
	double	dist;
	
	wall_point_vert = find_wall_point_vert(ray_orientation, map, p);
	if (is_out_map(wall_point_vert, map))
		return (-1);
	dist = fabs((p.pos.x - wall_point_vert.x) / cos(ray_orientation));

	return (dist);
}
