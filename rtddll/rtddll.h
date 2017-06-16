
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the RTDDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// RTDDLL_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef RTDDLL_EXPORTS
#define RTDDLL_API __declspec(dllexport)
#else
#define RTDDLL_API __declspec(dllimport)
#endif
#include "ftd2xx.h"

#define DLL_VERSION_VALUE   1

const BYTE AA_ECHO_CMD_1 = '\xAA';
const BYTE AB_ECHO_CMD_2 = '\xAB';
const BYTE BAD_COMMAND_RESPONSE = '\xFA';

const BYTE MSB_VEDGE_CLOCK_IN_BIT = '\x22';
const BYTE MSB_EDGE_CLOCK_OUT_BYTE = '\x11';
const BYTE MSB_EDGE_CLOCK_IN_BYTE = '\x24';

const BYTE MSB_FALLING_EDGE_CLOCK_BYTE_IN = '\x24';
const BYTE MSB_FALLING_EDGE_CLOCK_BYTE_OUT = '\x11';
const BYTE MSB_DOWN_EDGE_CLOCK_BIT_IN = '\x26';
const BYTE MSB_UP_EDGE_CLOCK_BYTE_IN = '\x20';
const BYTE MSB_UP_EDGE_CLOCK_BYTE_OUT = '\x10';
const BYTE MSB_RISING_EDGE_CLOCK_BIT_IN = '\x22';

#define _DDCCI_OPCODE_GAMMA_ERASE		0xAA // 擦除flash指定页
#define _DDCCI_OPCODE_GAMMA_SETDATA		0x10 // 指定地址写flash
#define _DDCCI_OPCODE_GAMMA_GETDATA		0x11 // 指定地址读flash
#define _DDCCI_OPCODE_GAMMA_USEDATA		0x12 // 使用flash中储存的gamma值
#define _DDCCI_OPCODE_GAMMA_DISABLE     0x1F // 关闭gamma功能
#define _DDCCI_OPCODE_GAMMA_ENABLE      0x20 // 开启gamma功能

#define _DDCCI_OPCODE_BACKLIGHT_ERASE				0x00
#define _DDCCI_OPCODE_BACKLIGHT_SETFLASHDATA		0x01
#define _DDCCI_OPCODE_BACKLIGHT_GETFLASHDATA		0x02
#define _DDCCI_OPCODE_BACKLIGHT_GETDATA				0x03
#define _DDCCI_OPCODE_BACKLIGHT_USEDATA				0x04

#define _DDCCI_VIRTUAL_HOST_ADDRESS		0x50//DDC校验和

enum GAMMA_RGB_TYPE
{
	GAMMA_RED = 1,
	GAMMA_GREEN,
	GAMMA_BLUE,
};


typedef FT_STATUS (WINAPI *FUN_FT_Write)(FT_HANDLE, LPVOID,DWORD,LPDWORD);
typedef FT_STATUS (WINAPI *FUN_FT_ListDevices)(PVOID,PVOID,DWORD);
typedef FT_STATUS (WINAPI *FUN_FT_OpenEx)(PVOID,DWORD,FT_HANDLE*);
typedef FT_STATUS (WINAPI *FUN_FT_ResetDevice)( FT_HANDLE );
typedef FT_STATUS (WINAPI *FUN_FT_GetQueueStatus)(FT_HANDLE,DWORD *);
typedef FT_STATUS (WINAPI *FUN_FT_Read)(FT_HANDLE,LPVOID,DWORD,LPDWORD);
typedef FT_STATUS (WINAPI *FUN_FT_SetUSBParameters)(FT_HANDLE,ULONG,ULONG);
typedef FT_STATUS (WINAPI *FUN_FT_SetChars)(FT_HANDLE,UCHAR,UCHAR,UCHAR,UCHAR);
typedef FT_STATUS (WINAPI *FUN_FT_SetTimeouts)(FT_HANDLE,ULONG,ULONG);
typedef FT_STATUS (WINAPI *FUN_FT_SetLatencyTimer)(FT_HANDLE,UCHAR);
typedef FT_STATUS (WINAPI *FUN_FT_SetBitMode)(FT_HANDLE,UCHAR,UCHAR);

FUN_FT_Write FT_Write = NULL;
FUN_FT_Read FT_Read = NULL;
FUN_FT_ListDevices FT_ListDevices = NULL;
FUN_FT_OpenEx FT_OpenEx = NULL;
FUN_FT_ResetDevice FT_ResetDevice = NULL;
FUN_FT_GetQueueStatus FT_GetQueueStatus = NULL;
FUN_FT_SetUSBParameters FT_SetUSBParameters = NULL;
FUN_FT_SetChars FT_SetChars = NULL;
FUN_FT_SetTimeouts FT_SetTimeouts = NULL;
FUN_FT_SetLatencyTimer FT_SetLatencyTimer = NULL;
FUN_FT_SetBitMode FT_SetBitMode = NULL;



extern "C" RTDDLL_API int __stdcall fnRtddll(void);

extern "C" RTDDLL_API int __stdcall getvar(void);

extern "C" RTDDLL_API FUN_FT_Write getfun_FT_Write(void);

extern "C" RTDDLL_API void HighSpeedSetI2CStart(void);

extern "C" RTDDLL_API void HighSpeedSetI2CStop(void);

extern "C" RTDDLL_API bool SendByteAndCheckACK(BYTE dwDataSend);

extern "C" RTDDLL_API void I2C_Write(BYTE deviceID, BYTE addr, BYTE *buffer);
extern "C" RTDDLL_API void I2C_WriteBlock(BYTE deviceID, WORD addr, WORD lenth ,BYTE *buffer);
extern "C" RTDDLL_API void RTD2785_WriteByte(BYTE dat,BYTE addr1,BYTE addr2);
extern "C" RTDDLL_API BYTE I2C_Read(BYTE deviceID, BYTE addr);
extern "C" RTDDLL_API BYTE RTD2785_ReadByte(BYTE addr1,BYTE addr2);

extern "C" RTDDLL_API bool __stdcall RTD2758Init(void);

extern "C" RTDDLL_API void __stdcall RTD2758_Run(void);
extern "C" RTDDLL_API void __stdcall RTD2758_Stop(void);
extern "C" RTDDLL_API void __stdcall RTD2758_Reset(void);

//debug mode
extern "C" RTDDLL_API void __stdcall Set_GammaEnable(bool enable);
extern "C" RTDDLL_API void __stdcall Read_GammaTable(BYTE *arry);
extern "C" RTDDLL_API void __stdcall Read_GammaRGBTable(BYTE type,BYTE *arry);
extern "C" RTDDLL_API void __stdcall Write_GammaTable(BYTE *arry);
extern "C" RTDDLL_API void __stdcall Write_GammaRGBTable(BYTE type,BYTE *arry);

//DDC CI
extern "C" RTDDLL_API void __stdcall DDCCI_EraseGamma(BYTE gammaID);
extern "C" RTDDLL_API bool __stdcall DDCCI_WriteGamma(BYTE *gammabuff,BYTE gammaID);
extern "C" RTDDLL_API void __stdcall DDCCI_EnableGamma(bool isenable);
extern "C" RTDDLL_API void __stdcall DDCCI_SetGamma(BYTE gammaID);
extern "C" RTDDLL_API void __stdcall DDCCI_ABA_Enable(bool isenable);
extern "C" RTDDLL_API void __stdcall DDCCI_ABA_SetValue(WORD value);
extern "C" RTDDLL_API void __stdcall DDCCI_ABA_GetValue(BYTE *data);
extern "C" RTDDLL_API void __stdcall DDCCI_EraseBacklight(BYTE BacklightIndex);
extern "C" RTDDLL_API bool __stdcall DDCCI_WriteBacklight(BYTE BacklightIndex,WORD LightValue,WORD PWMValue);
extern "C" RTDDLL_API void __stdcall DDCCI_ReadBacklight(BYTE BacklightIndex,BYTE *data);
extern "C" RTDDLL_API void __stdcall DDCCI_GetBacklight(BYTE *data);
extern "C" RTDDLL_API void __stdcall DDCCI_UseBacklight(WORD LightValue,WORD PWMValue);

//KEY
extern "C" RTDDLL_API void __stdcall DDCCI_OSD_KEYEvent(BYTE value);

//version
extern "C" RTDDLL_API int __stdcall getDLLversion(void);

//DDC校验和
extern "C" RTDDLL_API BYTE DDCCI_CheckSum(BYTE *data);