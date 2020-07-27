#include "test1.h"

int		is_wall(coord c, int **map) //OK
{
	int	case_x = c.x / LONG_CUB;
	int case_y = c.y / LONG_CUB;
		
	return (map[case_x][case_y] == 1);
}

int		is_out_map(coord p, int ** map)
{
	int case_x = p.x / LONG_CUB;
	int case_y = p.y / LONG_CUB;
	
	return ((case_x < 0 || case_x >= MAPX || case_y < 0 || case_y >= MAPY) ||
			(map[case_y][case_x] == -1));
}

double	find_wall_dist(double ray_orientation, int **map, player p)
{
	double	wall_dist_horiz;
	double	wall_dist_vert;

	if (ray_orientation == 0 || ray_orientation == deg_to_rad(180))
	{
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n!! %f \t\t!!\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" ,find_wall_dist_vert(ray_orientation, map, p));
		return (find_wall_dist_vert(ray_orientation, map, p));
	}
	else if (ray_orientation == deg_to_rad(90) ||
			 ray_orientation == deg_to_rad(270))
		return (find_wall_dist_horiz(ray_orientation, map, p));
	
	wall_dist_horiz = find_wall_dist_horiz(ray_orientation, map, p);
	wall_dist_vert = find_wall_dist_vert(ray_orientation, map, p);
	if (wall_dist_vert == -1)
	{
		if (wall_dist_horiz == -1)
			return (-1);
		else
			return (wall_dist_horiz);
	}
	if (wall_dist_horiz == -1)
		return (wall_dist_vert);
	return(min(wall_dist_horiz, wall_dist_vert));
}

int		find_wall_height(double dist_cam_ecran, double wall_dist)
{
	return (((double)LONG_CUB / wall_dist) * dist_cam_ecran);
}

int		is_in_wall(int y, int top_wall, int bot_wall)
{
	return (top_wall <= y && y <= bot_wall);
}

void	draw_wall_slice(int wall_height, all *a, int col, double cam_height_ratio)
{
	int	screen_height = a->r.y;
	int top_wall = screen_height / 2 - wall_height * (1 - cam_height_ratio);
	//Rappel:l'axe y va vers le bas
	int bot_wall = screen_height / 2 + wall_height * cam_height_ratio;
	int ligne = 0;
	while(ligne < screen_height)
	{
		if (is_in_wall(ligne, top_wall, bot_wall))
		{
			mlx_pixel_put(a->mlx, a->win, col, ligne, 255);
		}
		ligne++;
	}
	return ;
}

double	correct_dist(double dist, double angle)
{
	return (fabs(dist * cos(angle)));
}

void	raycasting(all *a)
{
	double	cam_height_ratio;
	double	dist_cam_ecr = ((float)a->r.x/2) / tan(a->FOV/2);
	double	angle_bt_rays = a->FOV/a->r.x;
	double	ray_orientation = a->p.orientation + a->FOV/2;
	printf("ray orientation: %f\n", ray_orientation);
	int		curr_col = 0;
	double	wall_dist = -1;
	int		wall_height;
	double	corr_dist;
	
	cam_height_ratio = 1. / 2;
	while (curr_col < a->r.x)
	{
		wall_dist = find_wall_dist(ray_orientation, a->map, a->p);
		if (wall_dist == -1)
			wall_height = 0;
		else
		{
			corr_dist = correct_dist(wall_dist, ray_orientation - a->p.orientation);
			wall_height = find_wall_height(dist_cam_ecr, corr_dist);
			printf("ORIENTATION \t   CORR DIST \t   REAL DIST \t  WALL \t   COL\n");
			printf("%f \t|| %f \t|| %f \t|| %d\t || %d\n\n", ray_orientation, corr_dist, wall_dist, wall_height, curr_col);
		}
		draw_wall_slice(wall_height, a, curr_col, cam_height_ratio);

		/* if (ray_orientation <= 0) */
		/* 	ray_orientation = deg_to_rad(360) + ray_orientation; */
		ray_orientation -= angle_bt_rays;
		curr_col++;
	}	
}

