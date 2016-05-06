#include "types.h"
/*macroinstructions*/

/*structs*/
struct graphic
{
	u8 *img;
	u16 size;
	u16 tag;
};

struct pal_graphic
{
	u8 *pal_ptr;
	u16 tag;
	u16 filler;
};

struct rotscale
{
	s16 xscal;
	s16 yscal;
	s8 rotation;
	u8 duration;
	u16 filler;
};

struct image_frame
{
	u16 cmd;
	u16 parameter;
};

struct oam
{
	u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 fill;
};

struct objtemplate
{
	u16 tiles_tag;
	u16 pal_tag;
	struct oam *oam_ptr;
	struct image_frame **anime_table;
	struct graphic *gfx_table;
	struct rotscale **rotscale_table;
	void (*callback)(void*);
};

struct obj
{
	struct oam oamdata;
	struct image_frame **anime_table;
	struct graphic *gfx_table;
	struct rotscale **rotscale_table;
	struct objtemplate *obj_template;
	u8 *npc_type_detail;
	void (*callback)(void*);
	u16 x1;
	u16 y1;
	s16 x2;
	s16 y2;
	s8 x3;
	s8 y3;
	u8 anime_index;
	u8 frame_index;
	u8 delay;
	u8 frame_cnt;
	u16 privatevars[8];
	u8 bitfield2;
	u8 bitfield;
	u16 base_tile;
	u8 npc_type_detail_index;
	u8 y_height_related;
};


struct rbox_short
{
	u8 bg_id;
	u8 x;
	u8 y;
	u8 w;
	u8 h;
	u8 pal;
	u16 vram_tileset_offset;
};

struct rbox
{
	struct rbox_short rs;
	void * pixels;
};

struct superstate
{
	void(*callback1)(void);
	void(*callback2)(void);
	void(*callback2backup)(void);
	void(*callback5_vblank)(void);
	void(*hblank_callback)(void);
	u32 field_14;
	u32 field_18;
	u32 bits_to_wait_for;
	u32 ptr_vblank_counter;
	u32 field_24;
	u16 buttons0_held;
	u16 buttons1_new;
	u16 buttons2_held_remapped;
	u16 buttons3_new_remapped;
	u16 buttons4_new_and_keyrepeat;
	u16 keypad_countdown;
	u32 unused_apparently;
	struct oam sprites[128];
	u8 multi_purpose_state_tracker;
	u8 gpu_sprites_upload_skip;
};

struct pokemon
{
	u32 personality_value;
	u32 OTID;
	u8 nickname[10];
	u16 language;
	u8 OT_name[7];
	u8 markings;
	u16 checksum;
	u16 padding;
	u8 enc_data[48];
	u32 status;
	u8 level;
	u8 pokerus;
	u16 cur_hp;
	u16 tot_hp;
	u16 attack;
	u16 defense;
	u16 speed;
	u16 sattack;
	u16 sdefense;
};

struct task
{
	void (*fptr) (u8);
	u8 inuse;
	u8 prev;
	u8 next;
	u8 priority;
	u16 priv[16];
};

struct fade_ctrl
{
	u16 bg_pal_bitfield;
	u16 obj_pal_bitfield;
	u16 scale;
	u16 mix_color;
	u8 field_8;
	u8 field_9;
	u8 field_A;
	u8 field_B;
};

struct trainerdata
{
	u8 name[8];
	u8 gender;
	u8 centercheck;
	u16 TID;
	u16 SID;
	u16 hours;
	u8 mins;
	u8 secs;
	u8 frames;
	u8 options_button_style;
	u8 options_text_speed;
	u8 unk[19];
	u8 pokemon_flags_3[52];
	u8 pokemon_flags_4[52];
	u8 field_90[1044];
	u8 fourCharacters[4];
	u8 field_4A8[1008];
	u8 mapdata[1672];
	u32 obfuscation_xor_key;
	u8 field_F24[127];
	u8 last_byte_in_sav2;
};

struct bg_cfg
{
	u16 bg_id:2;
	u16 charbase:2; //0x6000000 + x * 0x4000
	u16 screenbase:5; //0x6000000 + x * 0x800
	u16 size:2;
	u16 color_mode:1;
	u16 priority:2;
	u16 filler:2;
	u16 filler2;
};

struct DMACNT
{
    u16 Count;              // Transfer Count
    u16 Dummy_21_16:5;
    u16 DestpCnt:2;         // Destination Address Control
    u16 SrcpCnt:2;          // Source Address Control
    u16 ContinuousON:1;     // Continuous Mode
    u16 BusSize:1;          // Bus Size 16/32Bit Select
    u16 DataRequest:1;      // Data Request Synchronize Mode
    u16 Timming:2;          // Timing Select
    u16 IF_Enable:1;        // Interrupt Request Enable
    u16 Enable:1;           // DMA Enable
};

struct DISPCNT{
    u16 BgMode:3;           // BG Mode Select
    u16 CgbMode:1;          // CGB Mode Select
    u16 Bmp_FrameNo:1;      // Bitmap Mode Display Frame Select
    u16 Obj_H_Off:1;        // OBJ Processing in H Blank OFF
    u16 ObjCharMapType:1;   // OBJ Character Data Mapping Type
    u16 Lcdc_Off:1;         // LCDC OFF
    u16 Bg0_On:1;           // BG 0 ON
    u16 Bg1_On:1;           // BG 1 ON
    u16 Bg2_On:1;           // BG 2 ON
    u16 Bg3_On:1;           // BG 3 ON
    u16 Obj_On:1;           // OBJ ON
    u16 Win0_On:1;          // Window 0 ON
    u16 Win1_On:1;          // Window 1 ON
    u16 ObjWin_On:1;        // OBJ Window ON
};

union DMACNT_CON
{
	u32 DMACNT_D;
	struct DMACNT DMACNT_S;
};

union DISPCNT_CON
{
	u16 DISPCNT_D;
	struct DISPCNT DISPCNT_S;
};

/*offsets*/
void *VRAM = (void *)0x6000000;
void *PRAM = (void *)0x5000000;
void *OAM = (void *)0x7000000;
void *volatile*DMA3SAD = (void *volatile*)0x40000D4;
void *volatile*DMA3DAD = (void *volatile*)0x40000D8;
vu32 *DMA3CNT = (vu32 *)0x40000DC;
struct task *tasks = (struct task *)0x3005090;
struct trainerdata **saveblock2 = (struct trainerdata **)0x300500C;
u8 **malloc_pointer_loc = (u8 **)0x203AB48;
struct fade_ctrl *pal_fade_control = (struct fade_ctrl *)0x2037AB8;
u8 *gfxc_pokedex_diploma_background = (u8 *)0x84147C0;
u8 *diploma_pal_1_and_2 =(u8 *)0x8415954;
u8 *lz_diploma_bg1_tilemap = (u8 *)0x84154E8;
struct obj *objects = (struct obj*)0x202063C;
u8 *box_tiles = (u8 *)0x8470D6C;
char *fcode_buffer2 = (char *)0x2021CD0;
struct pokemon *partypokemon = (struct pokemon *)0x02024284;
char *displayed_string = (char *)0x2021D18;
u8 *hand_id_loc = (u8 *)0x2039990;
struct superstate *super = (struct superstate *)0x30030F0;
u8 *pokemon_quanitity = (u8 *)0x2024029;