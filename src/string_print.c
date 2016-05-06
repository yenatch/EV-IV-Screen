#include "header/funcs.h"
const char headerstring[] = {0xBF,0xD0,0xAE,0xC3,0xD0,0x00,0xBE,0xC3,0xCD,0xCA,0xC6,0xBB,0xD3,0xFF};

void string_print()
{
	rboxid_fill_pixels(0,0);
	box_print(0,2,3,3,0x8415a04,0,headerstring);
	rboxid_bg_prepare(0);
	return;
}

void box_draw(u8 box_id, u8 pal)
{
	rboxid_fill_pixels(box_id,0);
	rboxid_bg_prepare(box_id);
	rboxid_draw_810F2E8(box_id,0,0x300,pal);
	return;
}