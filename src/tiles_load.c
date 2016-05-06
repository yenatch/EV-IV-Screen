#include "header/funcs.h"
u8 tiles_load()
{
	switch(*(*malloc_pointer_loc+1))
	{
		case 0:
			graphic_log_clear();
			break;
		case 1:
			decompress_with_fallback(1,gfxc_pokedex_diploma_background,0,0,0);
			break;
		case 2:
			if(decompress_stat_check())
				return 0;
			else break;
		case 3:
			gpu_pal_apply(diploma_pal_1_and_2,0,0x40);
			return 1;
		default:
			return 1;
	}
	(*(*malloc_pointer_loc+1))++;
	return 0;
}