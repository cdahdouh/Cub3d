#include "test1.h"

int	m[MAPX][MAPY] = {{1, 1, 1, 1, 1, 1},
					 {1, 0, 0, 0, 0, 1},
					 {1, 0, 0, 0, 0, 1},
					 {1, 0, 0, 0, 0, 1},
					 {1, 0, 0,'E',0, 1},
					 {1, 1, 1, 1, 1, 1}};

float	rad_to_deg(double rad)
{
	return (rad / (M_PI / 180));
}

int	main(void)
{
    all a;
	//int angle = 90;
	a.map = map_copy(m, MAPX, MAPY);
	a.p = ft_player_start_pos(a.map, MAPX, MAPY);
	a.FOV = deg_to_rad(60);
	a.r.x = 320;
	a.r.y = 200;
	float angle = rad_to_deg(a.p.orientation);
	double	dist_cam_ecr = ((double)a.r.x/2) / tan(a.FOV/2);
	//double rad_angle = deg_to_rad(angle);
	coord point_horiz = find_wall_point_horiz(a.p.orientation, a.map , a.p);
	double dist_horiz = find_wall_dist_horiz(a.p.orientation, a.map, a.p);
	coord point_vert = find_wall_point_vert(a.p.orientation, a.map, a.p);
	double dist_vert = find_wall_dist_vert(a.p.orientation, a.map, a.p);
	double chosen_dist = find_wall_dist(a.p.orientation, a.map, a.p);
	int wall_height = find_wall_height(dist_cam_ecr, chosen_dist);
	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, a.r.x, a.r.y, "Snapshot");

	affiche_map(a.map, MAPX, MAPY);
	printf("\n");
	printf("Position joueur: (%lf, %f)\n",a.p.pos.x, a.p.pos.y);
	printf("Angle = %f degrés\n", angle);
	printf("Point horizontal: (%f, %f)\n", point_horiz.x, point_horiz.y);
	printf("Point vertical: (%f, %f)\n", point_vert.x, point_vert.y);
	printf("Distance entre personnage et point horizontal : %f unités\n", dist_horiz);
	printf("Distance entre personnage et point vertical : %f unités\n", dist_vert);
	printf("Disance choisie: %f\n", chosen_dist);
	printf("Taille du mur affichée: %d\n", wall_height);
	raycasting(&a);
	mlx_loop(a.mlx);
	return (0);
}
