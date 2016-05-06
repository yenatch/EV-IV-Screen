#include "header/funcs.h"
//flags for buttons3_new_remapped:1=A,2=B,4=SELECT,8=ENTER,0x10=RIGHT,0x20=LEFT,0x40=UP,0x80=DOWN

const u16 handcoords[] = {0x9A,0x48,0xBA,0x48,0xDA,0x48,0x9A,0x68,0xBA,0x68,0xDA,0x68};

void decrypt_and_print(struct pokemon *);
void aborter(u8 task_id);
void task_02(u8 task_id)
{
	int i;
	switch(*(*malloc_pointer_loc))
	{
		case 0:
			(tasks[task_id].priv[2])++;
			if(tasks[task_id].priv[2] == 0x20)
				break;
			else return;
			break;
		case 1:
			switch(super->buttons3_new_remapped)
			{
				case 2: //B
					oak_fade(0xFFFFFFFF,0,0,0x10,0);
					break;
				case 0x10: //RIGHT
					for(i = 0; i < *pokemon_quanitity; ++i)
					{
						if(handcoords[2*i] == (objects[*hand_id_loc].x1 + 0x20) && handcoords[2*i+1] == objects[*hand_id_loc].y1)
						{
							objects[*hand_id_loc].x1 += 0x20;
							++(tasks[task_id].priv[3]);
							decrypt_and_print(partypokemon+tasks[task_id].priv[3]);
							break;
						}
					}
					return;
				case 0x20: //LEFT
					for(i = 0; i < *pokemon_quanitity; ++i)
					{
						if(handcoords[2*i] == (objects[*hand_id_loc].x1 - 0x20) && handcoords[2*i+1] == objects[*hand_id_loc].y1)
						{
							objects[*hand_id_loc].x1 -= 0x20;
							--(tasks[task_id].priv[3]);
							decrypt_and_print(partypokemon+tasks[task_id].priv[3]);
							break;
						}
					}
					return;
				case 0x40: //UP
					for(i = 0; i < *pokemon_quanitity; ++i)
					{
						if(handcoords[2*i] == objects[*hand_id_loc].x1 && handcoords[2*i+1] == (objects[*hand_id_loc].y1 - 0x20))
						{
							objects[*hand_id_loc].y1 -= 0x20;
							tasks[task_id].priv[3] -= 3;
							decrypt_and_print(partypokemon+tasks[task_id].priv[3]);
							break;
						}
					}
					return;
				case 0x80: //DOWN
					for(i = 0; i < *pokemon_quanitity; ++i)
					{
						if(handcoords[2*i] == objects[*hand_id_loc].x1 && handcoords[2*i+1] == (objects[*hand_id_loc].y1 + 0x20))
						{
							objects[*hand_id_loc].y1 += 0x20;
							tasks[task_id].priv[3] += 3;
							decrypt_and_print(partypokemon+tasks[task_id].priv[3]);
							break;
						}
					}
					return;
				default:
					return;
			}
			break;
		case 2:
			aborter(task_id);
			return;
		default:
			return;
	}	
	(*(*malloc_pointer_loc))++;
	return;
}

void aborter(u8 task_id)
{
	if(((pal_fade_control->mix_color) >> 8 & 0x80))
		return;
	task_del(task_id);
	rboxes_free();
	free(*malloc_pointer_loc);
	set_callback2(c2_exit_to_overworld_1_continue_scripts_and_music);
	return;
}