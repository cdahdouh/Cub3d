#include "test1.h"

player	ft_player_start_pos(int **map, int mapx, int mapy) //OK
{
	int i;
	int j;
	player p = {{0,0},0};

	i = 0;
	while(i < mapy)
	{
		j = 0;
		while(j < mapx)
		{
			if (map[i][j] == 'N' || map[i][j] == 'E' || map[i][j] == 'S' ||
				map[i][j] =='W')
			{
				p.pos.x = LONG_CUB * j + LONG_CUB / 2 ;
				p.pos.y = LONG_CUB * i + LONG_CUB / 2;
				if (map[i][j] == 'N')
					p.orientation = deg_to_rad(90);
				else if (map[i][j] == 'E')
					p.orientation = 0;
				else if (map[i][j] == 'S')
					p.orientation = deg_to_rad(270);
				else if (map[i][j] =='W')
					p.orientation = deg_to_rad(180);
				return (p);
			}
			j++;
		}
		i++;
	}
	return(p);
}


int		**map_copy(int m[][MAPY], int mapx,int mapy) //OK
{
	int **map;
	int i = 0;
	int j = 0;
	
	map = (int**)malloc(mapy * sizeof(int*));//Allocation de la map
	while(i < mapy)//Allocation des lignes de la map
	{
		map[i] = (int*)malloc(mapx * sizeof(int));
		i++;
	}
	i = 0;
	while(i < mapy)//Copie de m de test1.h dans map
	{
		j = 0;
		while(j < mapx)
		{
			map[j][i] = m[j][i];
			j++;
		}
		i++;
	}
	return (map);
}

void affiche_map(int **map, int mapx, int mapy)//OK
{
	int i = 0;
	int j;

	while (i < mapy)
	{
		printf("\n");
		j = 0;
		while (j < mapx)
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' ||
				map[i][j] == 'W')
				printf("%c ", map[i][j]);
			else
				printf("%d ", map[i][j]);
			j++;
		}
		i++;
	}
	printf("\n");
}
