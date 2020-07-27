#include "test1.h"

int	m[MAPX][MAPY] = {{1, 1, 1, 1},
					 {1, 0, 0, 1},
					 {1,'N',0, 1},
					 {1, 1, 1, 1}};
int main(void)
{
	all a;
	int angle = 30;
	double rad_angle = deg_to_rad(angle);
	a.FOV = deg_to_rad(60);
	a.map = map_copy(m, MAPX, MAPY);
	a.p = ft_player_start_pos(a.map, MAPX, MAPY);
	printf("%s\n", wall_is_east(a.p, a.map, rad_angle) ? "true" : "false");
}
