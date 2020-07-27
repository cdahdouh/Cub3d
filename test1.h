#ifndef TEST1_H
# define TEST1_H

# include <math.h>
# include <mlx.h>
# include <mlx_int.h>
# include <stdlib.h>
# include <stdio.h>

# define MAPY 6
# define MAPX 6
# define LONG_CUB 64

typedef struct	keyboard{
	int left;
	int right;
	int w;
	int a;
	int s;
	int d;
}				keyboard;

typedef struct	 resolution{
	int x;
	int y;
}				resolution;

typedef struct	coord{
	double x;
	double y;
}				coord;

typedef struct	player{
	coord	pos;
	double	orientation;
}				player;

typedef struct	all{
	void *mlx;
	void *win;
	keyboard k;
	double	FOV;
	struct resolution	r;
	struct player p;
	int **map;
}				all;


int		ft_keypPress(int keycode, all *param);//OK
int		ft_keyRelease(int keycode, all *param);//OK

void	affiche_map(int **map, int mapx, int mapy);//OK

player	ft_player_start_pos(int **map, int mapx, int mapy);//OK
int		**map_copy(int m[][MAPY], int mapx,int mapy);//OK

double	deg_to_rad(float degre);//OK
double	min(double a, double b);

int		ray_is_right(double ray_orient);
int		ray_is_up(double ray_orient);
int		ray_is_left(double ray_orient);
int		ray_is_down(double ray_orient);

void	raycasting(all *a);
double	find_wall_dist(double ray_orientation, int **map, player p);
double	correct_dist(double dist, double angle);
int		find_wall_height(double dist_cam_ecran, double wall_dist);
void	draw_wall_slice(int wall_height, all *a, int col, double cam_height_ratio);

int		is_in_wall(int y, int top_wall, int bot_wall);
int		is_wall(coord c, int **map);//OK
int		is_in_map(coord c, int **map);//OK
int		is_out_map(coord p, int ** map);

double	find_wall_dist_horiz(double ray_orientation, int **map, player p);
coord	find_wall_point_horiz(double ray_orientation, int **map, player p);//OK
coord	first_horiz_point(double ray_orientation, player p);//OK

coord	first_vert_point(double ray_orientation, player p);//OK
coord	find_wall_point_vert(double ray_orientation, int **map, player p);
double	find_wall_dist_vert(double ray_orientation, int **map, player p);

#endif //TEST1_H
