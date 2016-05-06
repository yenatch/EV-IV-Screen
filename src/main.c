#include "header/funcs.h"

void cb_main(void);
extern void cb_execute(void);
extern void task_loader(u8);

void main_func()
{
	sub_8112364();
	set_callback2(cb_main);
	script_env_2_enable();
	return;
}

void cb_main()
{
	*malloc_pointer_loc = (u8 *) malloc_and_clear(0x1004);
	obj_and_aux_reset_all();
	pal_fade_control_and_dead_struct_reset();
	gpu_pal_allocator_reset();
	tasks_init();
	dp12_abort();
	task_add(task_loader,0);
	set_callback2(cb_execute);
	return;
}

