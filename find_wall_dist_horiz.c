#include "test1.h"

coord	first_horiz_point(double ray_orientation, player p)//OK
{
	coord	point;

	if (ray_is_up(ray_orientation)) // Le rayon pointe vers le haut
		point.y = ((int)p.pos.y / LONG_CUB) * 64 - 1;
	else // le rayon pointe vers le bas
		point.y = ((int)p.pos.y / LONG_CUB) * 64 + 64;
	point.x = p.pos.x + (p.pos.y - point.y) / tan(ray_orientation);

	return (point);
}

coord	find_wall_point_horiz(double ray_orientation, int **map, player p)//OK
{
	coord	horiz_check;
	double	y_step = ray_is_up(ray_orientation) ? -LONG_CUB : LONG_CUB;
	double	x_step = -1 * y_step / tan(ray_orientation);

	horiz_check = first_horiz_point(ray_orientation, p);
	while (!is_out_map(horiz_check, map) && !is_wall(horiz_check, map))
	{
		horiz_check.x += x_step;
		horiz_check.y += y_step;
	}
	/* if (is_out_map(horiz_check, map)) */
	/* { */
	/* 	horiz_check.x = -1; */
	/* 	horiz_check.y = -1; */
	/* 	return (horiz_check); */
	/* } */
	return (horiz_check);
}

double	find_wall_dist_horiz(double ray_orientation, int **map, player p)
{
	coord	wall_point_horiz;
	double		dist;
	
	wall_point_horiz = find_wall_point_horiz(ray_orientation, map, p);
	if (is_out_map(wall_point_horiz, map))
		return (-1);
	dist = fabs((p.pos.y - wall_point_horiz.y) / sin(ray_orientation));

	return (dist);
}
