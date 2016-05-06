#include "header/funcs.h"
extern void sub_bg_init(void);
extern u8 tiles_load(void);
extern void string_print(void);
extern void box_draw(u8,u8);
extern void load_icons(void);
extern void task_02(u8 task_id);
const char bottomstring[] = {0x79,0x7A,0x7B,0x7C,0x00,0xE8,0xE3,0x00,0xE1,0xE3,0xEA,0xD9,0x00,0xD5,0xE2,0xD8,0x00,0xBC,0x00,0xE8,0xE3,0x00,0xE5,0xE9,0xDD,0xE8,0xAD,0xFF};
const char pokemonstring[] = {0xCA,0xC9,0xC5,0x1B,0xC7,0xC9,0xC8,0xFF};
const u8 blackboxpal[] __attribute__((align(4))) = {0x2E,0x53,0x00,0x00,0xFF,0x7F,0x00,0x00,0xFF,0x7F,0xFF,0x7F,0xFF,0x7F,0xFF,0x7F,0xFF,0x7F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
const struct rbox_short rbox_table[] __attribute__((align(4))) = 
{
	{0,10,2,12,2,0xF,0x57},{0xFF,0,0,0,0,0,0},{0,1,0x11,28,2,0xE,0},/*nums*/{0,1,5,0xE,10,0xD,0x6F},/*icon*/{0,0x11,5,12,10,0xd,0x309}
};

void task_loader(u8 task_id)
{
	int temp;
	switch(*(*malloc_pointer_loc+2))
	{
		case 0:
			vblank_handler_set((void*)0);
			break;
		case 1:
			sub_bg_init();
			break;
		case 2:
			if(!tiles_load())
				return;
			else break;
		case 3:
			gpu_tilemap_apply(1,lz_diploma_bg1_tilemap,0,0);
			break;
		case 4:
			lcd_io_set(0x14,((*saveblock2)->gender)*0x100);
			gpu_copy_to_tileset(0,box_tiles,0x120,0x2FF);//hey motherfucker! why's 2FF instead of 300???
			temp = rbox_spawn(rbox_table+2);
			box_draw(temp,0xE);
			rboxid_print(temp,2,bottomstring,15,0,0,0);
			string_print();
			temp = rbox_spawn(rbox_table+4);
			box_draw(rbox_spawn(rbox_table+3),0xD);
			box_draw(temp,0xD);
			rboxid_print(temp,2,pokemonstring,25,0,0,0);
			gpu_pal_apply(blackboxpal,0xD0,0x20);
			gpu_pal_apply((void*)0x847190C,0xE0,0x20);
			gpu_pal_apply((void*)0x847192C,0xF0,0x20);
			lcd_io_set(0x40,240);
			lcd_io_set(0x44,0x2080);
			lcd_io_set(0x48,0x1F3F);
			lcd_io_set(0x4A,0x0F1F);
			lcd_io_set(0x50,0x3F41);
			lcd_io_set(0x52,0x0A0F);
			decrypt_and_print(partypokemon);
			break;
		case 5:
			bgid_send_tilemap(0);
			bgid_send_tilemap(1);
			break;
		case 6:
			gpu_tile_obj_decompress_alloc_tag_and_upload_2((struct graphic *)0x8462EFC);//body
			gpu_tile_obj_decompress_alloc_tag_and_upload_2((struct graphic *)0x8462F04);//ear
			gpu_tile_obj_decompress_alloc_tag_and_upload_2((struct graphic *)0x8462F0C);//face
			gpu_pal_obj_alloc_tag_and_apply((struct pal_graphic *)0x8462F1C);//pal
			tasks[task_id].priv[0] = template_instanciate_forward_search((struct objtemplate *)0x846302C,0x10,0x11,0);
			(objects[tasks[task_id].priv[0]]).oamdata.attr2 &= 0xF3FF;//load body and priority = 0
			tasks[task_id].priv[1] = template_instanciate_forward_search((struct objtemplate *)0x8463044,0x10,0x9,0);
			(objects[tasks[task_id].priv[1]]).oamdata.attr2 &= 0xF3FF;//load ear and priority = 0
			(objects[tasks[task_id].priv[1]]).privatevars[0] = tasks[task_id].priv[0]; //the callback will move it by the first obj's frame index
			(objects[tasks[task_id].priv[1]]).callback = cb_8130FB8; //the callback to move
			tasks[task_id].priv[1] = template_instanciate_forward_search((struct objtemplate *)0x846305C,0x18,0xD,0);
			(objects[tasks[task_id].priv[1]]).oamdata.attr2 &= 0xF3FF;//load ear and priority = 0
			(objects[tasks[task_id].priv[1]]).privatevars[0] = tasks[task_id].priv[0]; //the callback will move it by the first obj's frame index
			(objects[tasks[task_id].priv[1]]).callback = cb_8130FB8; //the callback to move
			load_icons();
			break;
		case 7:
			oak_fade(0xFFFFFFFF,0,0x10,0,0); //make it come back to bright
			break;
		case 8:
			vblank_handler_set(vblank_cb_080F4BFC); //will update the fade_ctrl
			break;
		default:
			if(!((pal_fade_control->mix_color) >> 8 & 0x80))
				break;
			tasks[task_id].priv[2] = 0;
			tasks[task_id].priv[3] = 0;
			tasks[task_id].fptr = task_02;
			break;
	}
	(*(*malloc_pointer_loc+2))++;
	return;
}