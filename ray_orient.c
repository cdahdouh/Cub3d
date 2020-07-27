#include "test1.h"

int ray_is_right(double ray_orient)
{
	return ((deg_to_rad(270) < ray_orient && ray_orient <= deg_to_rad(360)) ||
			(deg_to_rad(0) <= ray_orient && ray_orient < deg_to_rad(90)));
}

int ray_is_up(double ray_orient)
{
	return (0 < ray_orient && ray_orient < deg_to_rad(180));
}

int	ray_is_left(double ray_orient)
{
	return (deg_to_rad(90) < ray_orient && ray_orient < deg_to_rad(270));
}

int ray_is_down(double ray_orient)
{
	return (deg_to_rad(180) < ray_orient && ray_orient < deg_to_rad(360));
}
