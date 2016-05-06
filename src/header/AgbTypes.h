/********************************************************************/
/*          AgbTypes.h                                              */
/*            AGB Standard Declaration                              */
/*                                                                  */
/*          Copyright (C) 1999-2001 NINTENDO Co.,Ltd.               */
/********************************************************************/
#ifndef _AGB_TYPES_H
#define _AGB_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif


/*------------------------------------------------------------------*/
/*                      Redefine Data Size                          */
/*------------------------------------------------------------------*/

typedef     unsigned char           u8;
typedef     unsigned short int      u16;
typedef     unsigned int            u32;
typedef     unsigned long long int  u64;

typedef     signed char             s8;
typedef     signed short int        s16;
typedef     signed int              s32;
typedef     signed long long int    s64;

typedef     float                   f32;
typedef     double                  f64;


#define     vl                      volatile

typedef     vl u8                   vu8;
typedef     vl u16                  vu16;
typedef     vl u32                  vu32;
typedef     vl u64                  vu64;

typedef     vl s8                   vs8;
typedef     vl s16                  vs16;
typedef     vl s32                  vs32;
typedef     vl s64                  vs64;

typedef     vl f32                  vf32;
typedef     vl f64                  vf64;


/*------------------------------------------------------------------*/
/*                          Structure                               */
/*------------------------------------------------------------------*/

// Program Status Register Structure
typedef struct {
    u32 CpuMode:5;          // CPU Mode
    u32 Thumb_State:1;      // THUMB State
    u32 Fiq_Disable:1;      // FIQ Disable
    u32 Irq_Disable:1;      // IRQ Disable
    u32 Dummy_27_8:20;
    u32 V_Flag:1;           // Overflow
    u32 C_Flag:1;           // Carry/Borrow/Expand
    u32 Z_Flag:1;           // Zero
    u32 N_Flag:1;           // Negative/Less than
} PsrData;
typedef  vl PsrData    vPsrData;

#define ST_PSR_USER_MODE            0x10    // User
#define ST_PSR_FIQ_MODE             0x11    // FIQ
#define ST_PSR_IRQ_MODE             0x12    // IRQ
#define ST_PSR_SVC_MODE             0x13    // Supervisor
#define ST_PSR_ABORT_MODE           0x17    // Abort (pre-fetch/data)
#define ST_PSR_UNDEF_MODE           0x1b    // Undefined command
#define ST_PSR_SYS_MODE             0x1f    // System


// Interrupt Request/Enable Flag Structure
typedef struct {
    u16 V_Blank:1;          // V Blank
    u16 H_Blank:1;          // H Blank
    u16 V_Count:1;          // V Counter Matching
    u16 Timer0:1;           // Timer 0
    u16 Timer1:1;           // Timer 1
    u16 Timer2:1;           // Timer 2
    u16 Timer3:1;           // Timer 3
    u16 Sio:1;              // Serial Communication
    u16 Dma0:1;             // DMA 0
    u16 Dma1:1;             // DMA 1
    u16 Dma2:1;             // DMA 2
    u16 Dma3:1;             // DMA 3
    u16 Key:1;              // Key
    u16 Cassette:1;         // Game Pak
    u16 Dummy_15_14:2;
} IntrFlags;
typedef  vl IntrFlags    vIntrFlags;


// Display Control Structure
typedef struct {
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
} DispCnt;
typedef  vl DispCnt   vDispCnt;

#define ST_DISP_OBJ_CHAR_2D_MAP     0       // OBJ character data 2D mapping
#define ST_DISP_OBJ_CHAR_1D_MAP     1       // OBJ character data 1D mapping


// Status Control Structure
typedef struct {
    u16 V_Blank_Flag:1;     // During B Blank
    u16 H_Blank_Flag:1;     // During H Blank
    u16 V_Count_Flag:1;     // V Counter Matching
    u16 V_Blank_IF_Enable:1;// V Blank Interrupt Request Enable
    u16 H_Blank_IF_Enable:1;// H Blank Interrupt Request Enable
    u16 V_Count_IF_Enable:1;// V Counter Matching Interrupt Request Enable
    u16 Dummy_7_6:2;
    u8  V_Count_Cmp;        // V Counter Comparison Value
    u8  V_Count;            // V Counter Value
    u8  Dummy_31_24;
} StatCnt;
typedef  vl StatCnt   vStatCnt;


// Mosaic Control Structure
typedef struct {
    u16 Bg_HSize:4;         // BG Mosaic H Size
    u16 Bg_VSize:4;         // BG Mosaic V Size
    u16 Obj_HSize:4;        // OBJ Mosaic H Size
    u16 Obj_VSize:4;        // OBJ Mosaic V Size
} MosCnt;
typedef  vl MosCnt    vMosCnt;


// Blend Control Structure
typedef struct {
    u16 Pixel_1st_Bg0_On:1; // 1st Pixel
    u16 Pixel_1st_Bg1_On:1;
    u16 Pixel_1st_Bg2_On:1;
    u16 Pixel_1st_Bg3_On:1;
    u16 Pixel_1st_Obj_On:1;
    u16 Pixel_1st_Bd_On:1;
    u16 BlendMode:2;        // Blend Mode
    u16 Pixel_2nd_Bg0_On:1; // 2nd Pixel
    u16 Pixel_2nd_Bg1_On:1;
    u16 Pixel_2nd_Bg2_On:1;
    u16 Pixel_2nd_Bg3_On:1;
    u16 Pixel_2nd_Obj_On:1;
    u16 Pixel_2nd_Bd_On:1;
    u16 Dummy_15_14:2;
    u16 Value_A:5;          // Parameter A
    u16 Dummy_23_21:3;
    u16 Value_B:5;          // Parameter B
    u16 Dummy_31_29:3;
    u16 Value_Y:5;          // Parameter Y
    u16 Dummy_39_37:3;
} BlendCnt;
typedef  vl BlendCnt    vBlendCnt;

#define ST_BLD_NORMAL_MODE          0       // Normal mode
#define ST_BLD_A_BLEND_MODE         1       // Translucent mode
#define ST_BLD_UP_MODE              2       // Brighness UP mode
#define ST_BLD_DOWN_MODE            3       // Brightness DOWN mode


// BG Control Structure
typedef struct {
    u16 Priority:2;         // Display Priority
    u16 CharBasep:2;        // Character Base Address
    u16 Dummy_5_4:2;
    u16 Mosaic:1;           // Mozaic
    u16 ColorMode:1;        // 16 colors/ 256 colors Select
    u16 ScBasep:5;          // Screen Base Address
    u16 Loop:1;             // Loop
    u16 Size:2;             // Screen Size
} BgCnt;
typedef  vl BgCnt    vBgCnt;

#define ST_BG_COLOR_16              0       // Select 16 colors
#define ST_BG_COLOR_256             1       // Select 256 colors


// BG Offset Control Structure
typedef struct {
    u16 H;
    u16 V;
} BgOffsetCnt;
typedef  vl BgOffsetCnt    vBgOffsetCnt;


// BG Screen Structure
typedef struct {
    u16 CharNo:10;          // Character No
    u16 HFlip:1;            // H Flip
    u16 VFlip:1;            // V Flip
    u16 Pltt:4;             // Palette No
} BgScData;
typedef  vl BgScData       vBgScData;


// BG Affine Transformation Source Data Structure
typedef struct {
    s32 SrcCenterX;         // Source Data Center Coordinate  << 8
    s32 SrcCenterY;
    s16 DispCenterX;        // Display Center Coordinate
    s16 DispCenterY;
    s16 RatioX;             // Scaling Ratio << 8
    s16 RatioY;
    u16 Theta;              // Rotation Angle (0 - 255) << 8
} BgAffineSrcData;
typedef  vl BgAffineSrcData    vBgAffineSrcData;

// BG Affine Transformation Destination Data Structure
typedef struct {
    s16 H_DiffX;            // Line Direction X Coordinate Difference
    s16 V_DiffX;            // Vertical Direction X Coordinate Difference
    s16 H_DiffY;            // Line Direction Y Coordinate Difference
    s16 V_DiffY;            // Vertical Direction Y Coordinate Difference
    s32 StartX;             // Start X Coordinate
    s32 StartY;             // Start Y Coordinate
} BgAffineDestData;
typedef  vl BgAffineDestData   vBgAffineDestData;


// OAM Structure
typedef struct {
    u32 VPos:8;             // Y Coordinate
    u32 AffineMode:2;       // Affine Mode
    u32 ObjMode:2;          // OBJ Mode
    u32 Mosaic:1;           // Mosaic
    u32 ColorMode:1;        // 16 colors/256 colors Select
    u32 Shape:2;            // OBJ Shape

    u32 HPos:9;             // X Coordinate
    u32 AffineParamNo_L:3;  // Affine Transformation Parameter No.  Lower 3 bits
    u32 HFlip:1;            // H Flip
    u32 VFlip:1;            // V Flip
    u32 Size:2;             // OBJ Size

    u16 CharNo:10;          // Character No.
    u16 Priority:2;         // Display priority
    u16 Pltt:4;             // Palette No.
    u16 AffineParam;        // Affine Trasnformation Parameter
} OamData;
typedef  vl OamData    vOamData;

#define ST_OAM_OBJ_NORMAL           0       // OBJ normal mode
#define ST_OAM_OBJ_BLEND            1       // OBJ translucent mode
#define ST_OAM_OBJ_WINDOW           2       // OBJ window mode
#define ST_OAM_AFFINE_NONE          0       // Affine invalid mode
#define ST_OAM_AFFINE_NORMAL        1       // Affine normal mode
#define ST_OAM_AFFINE_TWICE         3       // Affine double angle mode
#define ST_OAM_AFFINE_ERASE         2       // Affine non-display mode
#define ST_OAM_COLOR_16             0       // Select 16 colors
#define ST_OAM_COLOR_256            1       // Select 256 colors
#define ST_OAM_SQUARE               0       // Square OBJ
#define ST_OAM_H_RECTANGLE          1       // Horizontally-oriented rectangle OBJ
#define ST_OAM_V_RECTANGLE          2       // Vertically-oriented rectangle OBJ


// OAM sort set function parameter structure
typedef struct {
    s8    SortUpDown;       // Ascending/descending order sort select flag
    u8    SrcPadSize:4;     // Source data padding size
    u8    DestPadSize:4;    // Destination data padding size
    u8    SetNum;           // Array set number
    u8    CheckOffset;      // Priority check data offset
    void *CheckStartp;      // Priority check data start address
    u32   CheckMask;        // Mask for priority check data
} OamSortSetParam;
typedef  vl OamSortSetParam    vOamSortSetParam;


// OBJ Affine Transformation Source Data Structure
typedef struct {
    s16 RatioX;             // Scaling Ratio
    s16 RatioY;
    u16 Theta;              // Rotation Angle (0 - 255) << 8
} ObjAffineSrcData;
typedef  vl ObjAffineSrcData   vObjAffineSrcData;

// OBJ Affine Transformation Destination Data Structure
typedef struct {
    s16 H_DiffX;            // Line Direction X Coordinate Difference
    s16 V_DiffX;            // Vertical Direction X Coordinate Difference
    s16 H_DiffY;            // Line Direction Y Coordinate Difference
    s16 V_DiffY;            // Vertical Direction Y Coordinate Difference
} ObjAffineDestData;
typedef  vl ObjAffineDestData  vObjAffineDestData;


// Color Palette Structure
typedef struct {
    u16 Red:5;              // Red
    u16 Green:5;            // Green
    u16 Blue:5;             // Blue
    u16 Dummy_15:1;
} PlttData;
typedef  vl PlttData    vPlttData;


// Window Control Structure
typedef struct {
    u8  Bg0_On:1;           // BG 0 ON
    u8  Bg1_On:1;           // BG 1 ON
    u8  Bg2_On:1;           // BG 2 ON
    u8  Bg3_On:1;           // BG 3 ON
    u8  Obj_On:1;           // OBJ ON
    u8  Blend_On:1;         // Color Special Effect ON
    u8  Dummy_7_6:2;
} WindCnt;
typedef  vl WindCnt     vWindCnt;


// Sound Control Structure
typedef struct {
    u8  So1_Level:3;        // S01 Output Level
    u8  So1_Vin_On:1;       // Vin -> S01 ON
    u8  So2_Level:3;        // S02 Output Level
    u8  So2_Vin_On:1;       // Vin -> S02 ON
    u8  So1_Sound1_On:1;    // Sound 1 -> S01 ON
    u8  So1_Sound2_On:1;    // Sound 2 -> S01 ON
    u8  So1_Sound3_On:1;    // Sound 3 -> S01 ON
    u8  So1_Sound4_On:1;    // Sound 4 -> S01 ON
    u8  So2_Sound1_On:1;    // Sound 1 -> S02 ON
    u8  So2_Sound2_On:1;    // Sound 2 -> S02 ON
    u8  So2_Sound3_On:1;    // Sound 3 -> S02 ON
    u8  So2_Sound4_On:1;    // Sound 4 -> S02 ON
    u8  Sound_1_4_Mix:2;    // DMG Compatible Sound Mix Ratio
    u8  DirectA_Mix:1;      // Direct Sound A Mix Ratio
    u8  DirectB_Mix:1;      // Direct Sound B Mix Ratio
    u8  Dummy_23_20:4;
    u8  So1_DirectA_On:1;   // Direct Sound A -> S01 ON
    u8  So2_DirectA_On:1;   // Direct Sound A -> S02 ON
    u8  DirectA_Timer:1;    // Direct Sound A Timer Select
    u8  FifoA_Reset:1;      // Direct Sound A FIFO Reset
    u8  So1_DirectB_On:1;   // Direct Sound B -> S01 ON
    u8  So2_DirectB_On:1;   // Direct Sound B -> S02 ON
    u8  DirectB_Timer:1;    // Direct Sound B Timer Select
    u8  FifoB_Reset:1;      // Direct Sound B FIFO Reset
    u8  Sound1_On:1;        // Sound 1 ON
    u8  Sound2_On:1;        // Sound 2 ON
    u8  Sound3_On:1;        // Sound 3 ON
    u8  Sound4_On:1;        // Sound 4 ON
    u8  Dummy_38_36:3;
    u8  Sound_1_4_On:1;     // DMG Compatible Sound ON
    u8  Dummy_47_40;
    u16 Dummy_63_48;
    u16 BiasLevel:10;       // BIAS Level
    u16 Dummy_77_74:4;
    u16 OutFrequency:2;     // Replay Frequency
} SoundCnt;
typedef  vl SoundCnt     vSoundCnt;

#define ST_SOUND_DMG_MIX_1_4        0       // DMG compatible sound mixing ratio 1/4
#define ST_SOUND_DMG_MIX_2_4        1       //                          2/4
#define ST_SOUND_DMG_MIX_FULL       2       //                          full range
#define ST_SOUND_DIRECT_MIX_1_2     0       // Direct sound mixing ratio 1/2
#define ST_SOUND_DIRECT_MIX_FULL    1       //                          full range


// Sound 1 Control Structure
typedef struct {
    u8  SweepShift:3;       // Sweep Shift Number
    u8  SweepUpDownt:1;     // Sweep Up/Down
    u8  SweepTime:3;        // Sweep Time
    u8  Dummy_7:1;
    u8  Dummy_15_8;
    u8  Counts:6;           // Sound Length (Count Number)
    u8  Duty:2;             // Waveform Duty
    u8  EnvSteps:3;         // Envelope Step Number
    u8  EnvUp_Down:1;       // Envelope UP/DOWN
    u8  EnvInitData:4;      // Envelope Inial Value
    u16 Frequency:11;       // Frequency
    u16 Dummy_45_43:3;
    u16 Counter_On:1;       // Counter ON
    u16 Start:1;            // Start
} Sound1Cnt;
typedef  vl Sound1Cnt    vSound1Cnt;

// Sound 2 Control Structure
typedef struct {
    u8  Counts:6;           // Sound Length (Count Number)
    u8  Duty:2;             // Waveform Duty
    u8  EnvSteps:3;         // Envelope Step Number
    u8  EnvUp_Down:1;       // Envelope UP/DOWN
    u8  EnvInitData:4;      // Envelope Initial Value
    u16 Dummy_31_16;
    u16 Frequency:11;       // Frequency
    u16 Dummy_45_43:3;
    u16 Counter_On:1;       // Counter ON
    u16 Start:1;            // Start
} Sound2Cnt;
typedef  vl Sound2Cnt    vSound2Cnt;

#define ST_SOUND_SWEEP_UP           0       // Sweep addition
#define ST_SOUND_SWEEP_DOWN         1       //          subtraction
#define ST_SOUND_DUTY_1_8           0       // Waveform duty 1/8
#define ST_SOUND_DUTY_2_8           1       //                  2/8
#define ST_SOUND_DUTY_4_8           2       //                  4/8
#define ST_SOUND_DUTY_6_8           3       //                  6/8
#define ST_SOUND_ENV_UP             1       // Envelope UP
#define ST_SOUND_ENV_DOWN           0       //              DOWN


// Sound 3 Control Structure
typedef struct {
    u8  Dummy_6_0:5;
    u8  Connect:1;          // Waveform RAM Connect
    u8  Bank:1;             // Waveform RAM Bank
    u8  On:1;               // Sound 3 ON
    u8  Dummy_15_8;
    u8  Counts;             // Sound Length (Count Number)
    u8  Dummy_28_24:5;
    u8  OutputLevel:3;      // Output Level
    u16 Frequency:11;       // Frequency
    u16 Dummy_45_43:3;
    u16 Counter_On:1;       // Counter ON
    u16 Start:1;            // Start
} Sound3Cnt;
typedef  vl Sound3Cnt    vSound3Cnt;

#define ST_SOUND_3_LEVEL_0_4        0       // No sound 3 output
#define ST_SOUND_3_LEVEL_FULL       1       //                 4/4
#define ST_SOUND_3_LEVEL_2_4        2       //                 2/4
#define ST_SOUND_3_LEVEL_1_4        3       //                 1/4
#define ST_SOUND_3_LEVEL_3_4        4       //                 3/4


// Sound 4 Control Structure
typedef struct {
    u8  Counts:6;           // Sound Length (Count Number)
    u8  Dummy_15_14:2;
    u8  EnvSteps:3;         // Envelope Step Number
    u8  EnvUp_Down:1;       // Envelope UP/DOWN
    u8  EnvInitData:4;      // Envelope Initial Value
    u16 Dummy_31_16;
    u8  PreScaler:3;        // Prescaler Select
    u8  PolySteps:1;        // Polynomical/Counter Step Number Select
    u8  PolyShift:4;        // Polynomical/Counter Shift Number
    u8  Dummy45_40:6;
    u8  Counter_On:1;       // Counter ON
    u8  Start:1;            // Start
} Sound4Cnt;
typedef  vl Sound4Cnt    vSound4Cnt;

#define ST_SOUND_4_POLYSTEP_15      0       // Sound 4 polynomical counter 15 steps
#define ST_SOUND_4_POLYSTEP_7       1       //                                     7 steps


// Normal SIO Control Structure
typedef struct {
    u16 Sck_I_O:1;          // Clock I/O Select
    u16 Sck:1;              // Internal Clock Select
    u16 AckRecv:1;          // Transfer Enable Flag Receive
    u16 AckSend:1;          // Transfer Enable Flag Send
    u16 Dummy_6_4:3;
    u16 Enable:1;           // SIO Enable
    u16 Dummy_11_8:4;
    u16 Mode:2;             // Communication Mode Select
    u16 IF_Enable:1;        // Interrupt Request Enable
    u16 Dammy_15:1;
    u8  Data;               // Data
    u8  Dummy_31_24;
} SioNormalCnt;
typedef  vl SioNormalCnt    vSioNormalCnt;

#define ST_SIO_8BIT_MODE            0       // Normal 8-bit communication mode
#define ST_SIO_32BIT_MODE           1       // Normal 32-bit communication mode

#define ST_SIO_SCK_OUT              0       // Select external clock
#define ST_SIO_SCK_IN               1       // Select internal clock
#define ST_SIO_IN_SCK_256K          0       // Select internal clock 256KHz
#define ST_SIO_IN_SCK_2M            1       //                  Select 2MHz 


// Multi-play SIO Control Structure
typedef struct {
    u16 BaudRate:2;         // Baud Rate
    u16 SI:1;               // SI Terminal
    u16 SD:1;               // SD Terminal
    u16 ID:2;               // ID
    u16 Error:1;            // Error Detect
    u16 Enable:1;           // SIO Enable
    u16 Dummy_11_8:4;
    u16 Mode:2;             // Communication Mode Select
    u16 IF_Enable:1;        // Interrupt Request Enable
    u16 Dammy_15:1;
    u16 Data;               // Data
} SioMultiCnt;
typedef  vl SioMultiCnt     vSioMultiCnt;

#define ST_SIO_MULTI_MODE           2       // Multi-play communication mode

#define ST_SIO_9600_BPS             0       // Baud rate 9600 bps
#define ST_SIO_38400_BPS            1       //          38400 bps
#define ST_SIO_57600_BPS            2       //          57600 bps
#define ST_SIO_115200_BPS           3       //        115200 bps
#define ST_SIO_MULTI_PARENT         1       // Multi-play communication  Connect master
#define ST_SIO_MULTI_CHILD          0       //                  Connect slave


// UART - SIO Control Structure
typedef struct {
    u16 BaudRate:2;         // Baud Rate
    u16 Cts_Enable:1;       // Send Signal Enable
    u16 ParitySelect:1;     // Parity Even/Odd
    u16 TransDataFull:1;    // Transmit Data Full
    u16 RecvDataEmpty:1;    // Receive Data Empty
    u16 Error:1;            // Error Detect
    u16 Length:1;           // Data Length
    u16 Fifo_Enable:1;      // FIFO Enable
    u16 Parity_Enable:1;    // Parity Enable
    u16 Trans_Enable:1;     // Transmitter Enable
    u16 Recv_Enable:1;      // Receiver Enable
    u16 Mode:2;             // Communication Mode Select
    u16 IF_Enable:1;        // Interrupt Request Enable
    u16 Dammy_15:1;
    u8  Data;               // Data
    u8  Dummy_31_24;
} SioUartCnt;
typedef  vl SioUartCnt		vSioUartCnt;

#define ST_SIO_UART_MODE            3       // UART communication mode

#define ST_SIO_UART_7BIT            0       // UART communication data length 7 bits
#define ST_SIO_UART_8BIT            1       //                       8 bits
#define ST_SIO_PARITY_EVEN          0       // Even parity
#define ST_SIO_PARITY_ODD           1       // Odd parity


// JOY Bus Communication Control Structure
typedef struct {
    u8  IF_Reset:1;         // JOY Bus Reset Interrupt Request
    u8  IF_Recv:1;          // JOY Bus Received Interrupt Request
    u8  IF_Send:1;          // JOY Bus Sent Interrupt Request
    u8  Dummy_5_3:3;
    u8  IF_Enable:1;        // Interrupt Request Enable
    u8  Dummy_7:1;
} JoyCnt;
typedef  vl JoyCnt     vJoyCnt;

// JOY Bus Communication Status Structure
typedef struct {
    u8  Dummy_0:1;
    u8  Recv:1;             // Receive Status
    u8  Dummy_2:1;
    u8  Send:1;             // Send Status
    u8  Flags:2;            // General Flag
    u8  Dummy_7_6:2;
} JoyStat;
typedef  vl JoyStat    vJoyStat;


// General Input/Output Control Structure
typedef struct {
    u8  SC:1;               // Data
    u8  SD:1;
    u8  SI:1;
    u8  SO:1;
    u8  SC_I_O:1;           // I/O Select
    u8  SD_I_O:1;
    u8  SI_I_O:1;
    u8  SO_I_O:1;
    u8  IF_Enable:1;        // Interrupt Request Enable
    u8  Dummy_13_9:5;
    u8  SioModeMaster:2;    // SIO Mode Master
} RCnt;
typedef  vl RCnt      vRCnt;

#define ST_R_SIO_MASTER_MODE        0       // SIO master mode
#define ST_R_DIRECT_MODE            2       // General input/output communication mode
#define ST_R_JOY_MODE               3       // JOY communication mode

#define ST_R_IN                     0       // Select input
#define ST_R_OUT                    1       // Select output


// DMA Control Structure
typedef struct {
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
} DmaCnt;
typedef  vl DmaCnt    vDmaCnt;

#define ST_DMA_TIMMING_IMM          0       // Start immediately
#define ST_DMA_TIMMING_V_BLANK      1       // Start V blank
#define ST_DMA_TIMMING_H_BLANK      2       // Start H blank
#define ST_DMA_TIMMING_DISP         3       // Start display
#define ST_DMA_TIMMING_SOUND        3       // Start sound FIFO request
#define ST_DMA_16BIT_BUS            0       // Select bus size 16 bits
#define ST_DMA_32BIT_BUS            1       // Select bus size 32 bits
#define ST_DMA_INC                  0       // Select address increment
#define ST_DMA_DEC                  1       // Select address decrement
#define ST_DMA_FIX                  2       // Select address fix
#define ST_DMA_RELOAD               3       // Select address increment/reload


// Timer Control Structure
typedef struct {
    u16 Count;              // Count Number
    u16 PreScaler:2;        // Prescaler Select
    u16 Connect:1;          // Lower Timer Connect
    u16 Dummy_5_3:3;
    u16 IF_Enable:1;        // Interrupt Request Enable
    u16 Enable:1;           // Timer Enable
    u16 Dummy_15_8:8;
} TimerCnt;
typedef  vl TimerCnt    vTimerCnt;

#define ST_TMR_PRESCALER_1CK        0        // Prescaler 1 clock
#define ST_TMR_PRESCALER_64CK       1        //            64 clocks
#define ST_TMR_PRESCALER_256CK      2        //          256 clocks
#define ST_TMR_PRESCALER_1024CK     3        //        1024 clocks


// Key Data Structure
typedef struct {
    u16 A:1;                // A
    u16 B:1;                // B
    u16 Select:1;           // SELECT
    u16 Start:1;            // START
    u16 Plus_R:1;           // Right
    u16 Plus_L:1;           // Left
    u16 Plus_U:1;           // Higher
    u16 Plus_D:1;           // Lower
    u16 R:1;                // R
    u16 L:1;                // L
    u16 Dummy_15_10:6;
} KeyData;
typedef  vl KeyData    vKeyData;

// Key Control Structure
typedef struct {
    u16 Sel_A:1;            // Select A Button
    u16 Sel_B:1;            // Select B Button
    u16 Sel_Select:1;       // Select SELECT Button
    u16 Sel_Start:1;        // Select START Button
    u16 Sel_Plus_R:1;       // Select Right Key
    u16 Sel_Plus_L:1;       // Select Left Key
    u16 Sel_Plus_U:1;       // Select Up Key
    u16 Sel_Plus_D:1;       // Select Down Key
    u16 Sel_R:1;            // Select R Button
    u16 Sel_L:1;            // Select L Button
    u16 Dummy_13_10:4;
    u16 IF_Enable:1;        // Interrupt Request Enable
    u16 IntrType:1;         // Interrupt Type Select
} KeyCnt;
typedef  vl KeyCnt    vKeyCnt;

#define ST_KEY_OR_INTR              0        //   Normal key interrupt
#define ST_KEY_AND_INTR             1        // AND key interrupt


// Game Pak Wait Control Structure
typedef struct {
    u16 Sram:2;             // SRAM Wait
    u16 Rom0_1st:2;         // ROM 0 1st Wait
    u16 Rom0_2nd:1;         //          2nd Wait
    u16 Rom1_1st:2;         // ROM 1 1st Wait
    u16 Rom1_2nd:1;         //          2nd Wait
    u16 Rom2_1st:2;         // ROM 2 1st Wait
    u16 Rom2_2nd:1;         //          2nd Wait
    u16 OutClock:2;         // Output Clock Select
    u16 Dummy_13:1;
    u16 PrefetchEnale:1;    // Prefetch Buffer Enable
    u16 CassetteType:1;     // Game Pak Type
} CstWaitCnt;
typedef  vl CstWaitCnt    vCstWaitCnt;

#define ST_CST_SRAM_4WAIT           0        // SRAM  4 wait
#define ST_CST_SRAM_3WAIT           1        //                 3 wait
#define ST_CST_SRAM_2WAIT           2        //                 2 wait
#define ST_CST_SRAM_8WAIT           3        //                 8 wait
#define ST_CST_ROM_1ST_4WAIT        0        // ROM  1st 4 wait
#define ST_CST_ROM_1ST_3WAIT        1        //                 3 wait
#define ST_CST_ROM_1ST_2WAIT        2        //                 2 wait
#define ST_CST_ROM_1ST_8WAIT        3        //                 8 wait
#define ST_CST_ROM0_2ND_2WAIT       0        // ROM 0 2nd 2 wait
#define ST_CST_ROM0_2ND_1WAIT       1        //                 1 wait
#define ST_CST_ROM1_2ND_4WAIT       0        // ROM 1 2nd 4 wait
#define ST_CST_ROM1_2ND_1WAIT       1        //                 1 wait
#define ST_CST_ROM2_2ND_8WAIT       0        // ROM 2 2nd 8 wait
#define ST_CST_ROM2_2ND_1WAIT       1        //                 1 wait

#define ST_CST_PHI_OUT_NONE         0        //  terminal output clock Lo fix
#define ST_CST_PHI_OUT_4MCK         1        //                    4MHz
#define ST_CST_PHI_OUT_8MCK         2        //                    8MHz
#define ST_CST_PHI_OUT_16MCK        3        //                  16MHz
#define ST_CST_AGB                  0        // AGB game pak
#define ST_CST_CGB                  1        // CGB game pak


// Bit Compress Data Expansion Parameter
typedef struct {
    u16 SrcNum;             // Source Data Byte Size
    u8  SrcBitNum;          // 1 Source Data Bit Number
    u8  DestBitNum;         // 1 Destination Data Bit Number
    u32 DestOffset:31;      // Number added to Source Data
    u32 DestOffset0_On:1;   // Flag to add/not add Offset to 0 Data
} BitUnPackParam;
typedef  vl BitUnPackParam    vBitUnPackParam;


#ifdef __cplusplus
}      /* extern "C" */
#endif

#endif /* _AGB_TYPES_H */
