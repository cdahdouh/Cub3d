#include "test1.h"

int		ft_keyPress(int keycode, all *param) //OK
{
	if (keycode == 0xff51) //<- key
		param->k.left = 1;
	else if (keycode == 0xff53) //-> key
		param->k.right = 1;
	else if (keycode == 0x0077) //w key
		param->k.w = 1;
	else if (keycode == 0x0061) //a key
		param->k.a = 1;
	else if(keycode == 0x0073) //s key
		param->k.s = 1;
	else if(keycode == 0x0064) //d key
		param->k.d = 1;
	return (0);
}

int		ft_keyRelease(int keycode, all *param) //OK
{
	if (keycode == 0xff51) //<- key
		param->k.left = 0;
	else if (keycode == 0xff53) //-> key
		param->k.right = 0;
	else if (keycode == 0x0077) //w key
		param->k.w = 0;
	else if (keycode == 0x0061) //a key
		param->k.a = 0;
	else if(keycode == 0x0073) //s key
		param->k.s = 0;
	else if(keycode == 0x0064) //d key
		param->k.d = 0;
	return (0);
}
