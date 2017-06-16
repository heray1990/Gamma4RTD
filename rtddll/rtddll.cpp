// rtddll.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "rtddll.h"
//#include "ftd2xx.h"
#include "windows.h"

DWORD dwCount;
DWORD devIndex = 0;
DWORD dwNumBytesToSend = 0; 	//Index of output buffer
DWORD dwNumBytesSent = 0, 	dwNumBytesRead = 0, dwNumInputBuffer = 0;
char Buf[64];
FT_STATUS ftStatus;			//Status defined in D2XX to indicate operation result
FT_HANDLE ftHandle;			//Handle of FT2232H device port
BYTE OutputBuffer[1024];		//Buffer to hold MPSSE commands and data to be sent to FT2232H
BYTE InputBuffer[1024];		//Buffer to hold Data bytes to be read from FT2232H
DWORD dwClockDivisor = 0x004A;   //200khz

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	HINSTANCE hDllInst = LoadLibrary("ftd2xx.DLL");
	if(hDllInst)
	{
		FT_Write = (FUN_FT_Write)GetProcAddress(hDllInst,"FT_Write");
		FT_Read = (FUN_FT_Read)GetProcAddress(hDllInst,"FT_Read");
		FT_ListDevices = (FUN_FT_ListDevices)GetProcAddress(hDllInst,"FT_ListDevices");
		FT_OpenEx = (FUN_FT_OpenEx)GetProcAddress(hDllInst,"FT_OpenEx");
		FT_ResetDevice = (FUN_FT_ResetDevice)GetProcAddress(hDllInst,"FT_ResetDevice");
		FT_GetQueueStatus = (FUN_FT_GetQueueStatus)GetProcAddress(hDllInst,"FT_GetQueueStatus");
		FT_SetUSBParameters = (FUN_FT_SetUSBParameters)GetProcAddress(hDllInst,"FT_SetUSBParameters");
		FT_SetChars = (FUN_FT_SetChars)GetProcAddress(hDllInst,"FT_SetChars");
		FT_SetTimeouts = (FUN_FT_SetTimeouts)GetProcAddress(hDllInst,"FT_SetTimeouts");
		FT_SetLatencyTimer = (FUN_FT_SetLatencyTimer)GetProcAddress(hDllInst,"FT_SetLatencyTimer");
		FT_SetBitMode = (FUN_FT_SetBitMode)GetProcAddress(hDllInst,"FT_SetBitMode");

	}

    switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
			break;
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			FreeLibrary(hDllInst);
			break;
    }
    return TRUE;
}


// This is an example of an exported variable
RTDDLL_API int TempGamma[6120];

RTDDLL_API int __stdcall getvar(void)
{
	return 25;
}

// This is an example of an exported function.
RTDDLL_API int __stdcall fnRtddll(void)
{
	return 42;
}

// This is my test 

RTDDLL_API FUN_FT_Write getfun_FT_Write(void)
{
	return FT_Write;
}

RTDDLL_API void HighSpeedSetI2CStart(void)
{
	DWORD dwCount;
    for(dwCount=0; dwCount < 4; dwCount++)	// Repeat commands to ensure the minimum period of the start hold time ie 600ns is achieved
    {
        OutputBuffer[dwNumBytesToSend++] = '\x80';	//Command to set directions of lower 8 pins and force value on bits set as output
        OutputBuffer[dwNumBytesToSend++] = '\x03';  //Set SDA, SCL high, WP disabled by SK, DO at bit ¡®1¡¯, GPIOL0 at bit ¡®0¡¯
        OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯
    }
    for(dwCount=0; dwCount < 4; dwCount++)	// Repeat commands to ensure the minimum period of the start setup time ie 600ns is achieved
    {
        OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
        OutputBuffer[dwNumBytesToSend++] = '\x01'; 	//Set SDA low, SCL high, WP disabled by SK at bit ¡®1¡¯, DO, GPIOL0 at bit ¡®0¡¯
        OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯
    }
    OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
    OutputBuffer[dwNumBytesToSend++] = '\x00'; 	//Set SDA, SCL low high, WP disabled by SK, DO, GPIOL0 at bit ¡®0¡¯
    OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯
}

RTDDLL_API void HighSpeedSetI2CStop()
{
    DWORD dwCount;
    for(dwCount=0; dwCount<4; dwCount++)	// Repeat commands to ensure the minimum period of the stop setup time ie 600ns is achieved
    {
        OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
        OutputBuffer[dwNumBytesToSend++] = '\x01'; 	//Set SDA low, SCL high, WP disabled by SK at bit ¡®1¡¯, DO, GPIOL0 at bit ¡®0¡¯
        OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯
    }
    for(dwCount=0; dwCount<4; dwCount++)	// Repeat commands to ensure the minimum period of the stop hold time ie 600ns is achieved
    {
        OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
        OutputBuffer[dwNumBytesToSend++] = '\x03'; 	//Set SDA, SCL high, WP disabled by SK, DO at bit ¡®1¡¯, GPIOL0 at bit ¡®0¡¯
        OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯
    }
    //Tristate the SCL, SDA pins
    OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
    OutputBuffer[dwNumBytesToSend++] = '\x00'; 	//Set WP disabled by GPIOL0 at bit 0¡¯
    OutputBuffer[dwNumBytesToSend++] = '\x10';	//Set GPIOL0 pins as output with bit ¡¯1¡¯, SK, DO and other pins as input with bit ¡®0¡¯
}

RTDDLL_API bool SendByteAndCheckACK(BYTE dwDataSend)
{
    FT_STATUS ftStatus = FT_OK;
    OutputBuffer[dwNumBytesToSend++] = MSB_FALLING_EDGE_CLOCK_BYTE_OUT; 	//clock data byte out on ¨Cve Clock Edge MSB first
    OutputBuffer[dwNumBytesToSend++] = '\x00';
    OutputBuffer[dwNumBytesToSend++] = '\x00';	//Data length of 0x0000 means 1 byte data to clock out
    OutputBuffer[dwNumBytesToSend++] = dwDataSend;	//Set control byte, bit 4-7 of ¡®1010¡¯ as 24LC02 control code, bit 1-3 as block select bits  //which is don¡¯t care here, bit 0 of ¡®0¡¯ represent Write operation
    //Get Acknowledge bit
    OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
    OutputBuffer[dwNumBytesToSend++] = '\x00'; 	//Set SCL low, WP disabled by SK, GPIOL0 at bit ¡®0¡¯
    OutputBuffer[dwNumBytesToSend++] = '\x11';	//Set SK, GPIOL0 pins as output with bit ¡¯1¡¯, DO and other pins as input with bit ¡®0¡¯
    OutputBuffer[dwNumBytesToSend++] = MSB_RISING_EDGE_CLOCK_BIT_IN; 	//Command to scan in acknowledge bit , -ve clock Edge MSB first
    OutputBuffer[dwNumBytesToSend++] = '\x0';	//Length of 0x0 means to scan in 1 bit

    OutputBuffer[dwNumBytesToSend++] = '\x87';	//Send answer back immediate command
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);		//Send off the commands
    dwNumBytesToSend = 0;			//Clear output buffer
    //Check if ACK bit received, may need to read more times to get ACK bit or fail if timeout
    ftStatus = FT_Read(ftHandle, InputBuffer, 1, &dwNumBytesRead);  	//Read one byte from device receive buffer
    if ((ftStatus != FT_OK) || (dwNumBytesRead == 0))
    {
        //qDebug()<<"fail to get ACK when send control byte 1 [Program Section]";
        return false; //Error, can't get the ACK bit
    }
    //qDebug()<<dwNumBytesRead;

    OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
    OutputBuffer[dwNumBytesToSend++] = '\x02'; 	//Set SDA high, SCL low, WP disabled by SK at bit '0', DO, GPIOL0 at bit '1'
    OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯
    return true;
}

RTDDLL_API void I2C_Write(BYTE deviceID, BYTE addr, BYTE *buffer)
{
    HighSpeedSetI2CStart();
    SendByteAndCheckACK(deviceID);
    SendByteAndCheckACK(addr);
    SendByteAndCheckACK(*buffer);
    HighSpeedSetI2CStop();
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);
    dwNumBytesToSend = 0;			//Clear output buffer
}
RTDDLL_API void I2C_WriteBlock(BYTE deviceID, WORD addr, WORD lenth ,BYTE *buffer)
{
	HighSpeedSetI2CStart();
	SendByteAndCheckACK(deviceID);
	SendByteAndCheckACK(addr);
	while(lenth--)
	{
		SendByteAndCheckACK(*buffer++);
	}
	HighSpeedSetI2CStop();
	ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);
	dwNumBytesToSend = 0;			//Clear output buffer
}
RTDDLL_API void RTD2785_WriteByte(BYTE dat,BYTE addr1,BYTE addr2)
{
    I2C_Write(0x6A,0x03,&dat);
    I2C_Write(0x6A,0x01,&addr1);
    I2C_Write(0x6A,0x3B,&addr2);
}
RTDDLL_API BYTE I2C_Read(BYTE deviceID, BYTE addr)
{
    HighSpeedSetI2CStart();
    SendByteAndCheckACK(deviceID-1);
    SendByteAndCheckACK(addr);
    HighSpeedSetI2CStart();
    SendByteAndCheckACK(deviceID);

    OutputBuffer[dwNumBytesToSend++] = '\x81';	//Send answer back immediate command

    OutputBuffer[dwNumBytesToSend++] = MSB_FALLING_EDGE_CLOCK_BYTE_IN; 	//clock data byte out on ¨Cve Clock Edge MSB first
    OutputBuffer[dwNumBytesToSend++] = '\x00';
    OutputBuffer[dwNumBytesToSend++] = '\x00';	//Data length of 0x0000 means 1 byte data to clock out

    OutputBuffer[dwNumBytesToSend++] = '\x87';	//Send answer back immediate command

    //NACK
    OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
    OutputBuffer[dwNumBytesToSend++] = '\x03'; 	//Set SDA high, SCL low, WP disabled by SK at bit '0', DO, GPIOL0 at bit '1'
    OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯

    HighSpeedSetI2CStop();
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);		//Send off the commands
    dwNumBytesToSend = 0;			//Clear output buffer

    ftStatus = FT_GetQueueStatus(ftHandle, &dwNumInputBuffer);
    if(dwNumInputBuffer == 0)
    {
        //qDebug()<<"again";
        OutputBuffer[dwNumBytesToSend++] = '\x87';	//Send answer back immediate command
        ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);		//Send off the commands
        dwNumBytesToSend = 0;			//Clear output buffer
        Sleep(5);
        ftStatus = FT_GetQueueStatus(ftHandle, &dwNumInputBuffer);
    }
    ftStatus = FT_Read(ftHandle, InputBuffer, dwNumInputBuffer, &dwNumBytesRead);  	//Read one byte from device receive buffer
    //qDebug()<<dwNumBytesRead<<"|"<<InputBuffer[dwNumBytesRead-1];

    return InputBuffer[dwNumBytesRead-1];

}
RTDDLL_API BYTE DDC_Read(BYTE deviceID, BYTE addr)
{
    HighSpeedSetI2CStart();
    SendByteAndCheckACK(deviceID);
    SendByteAndCheckACK(addr);
    HighSpeedSetI2CStart();
    SendByteAndCheckACK(deviceID+1);

    OutputBuffer[dwNumBytesToSend++] = '\x81';	//Send answer back immediate command

    OutputBuffer[dwNumBytesToSend++] = MSB_FALLING_EDGE_CLOCK_BYTE_IN; 	//clock data byte out on ¨Cve Clock Edge MSB first
    OutputBuffer[dwNumBytesToSend++] = '\x00';
    OutputBuffer[dwNumBytesToSend++] = '\x00';	//Data length of 0x0000 means 1 byte data to clock out

    OutputBuffer[dwNumBytesToSend++] = '\x87';	//Send answer back immediate command

    //NACK
    OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
    OutputBuffer[dwNumBytesToSend++] = '\x03'; 	//Set SDA high, SCL low, WP disabled by SK at bit '0', DO, GPIOL0 at bit '1'
    OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯

    HighSpeedSetI2CStop();
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);		//Send off the commands
    dwNumBytesToSend = 0;			//Clear output buffer

    ftStatus = FT_GetQueueStatus(ftHandle, &dwNumInputBuffer);
    if(dwNumInputBuffer == 0)
    {
        //qDebug()<<"again";
        OutputBuffer[dwNumBytesToSend++] = '\x87';	//Send answer back immediate command
        ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);		//Send off the commands
        dwNumBytesToSend = 0;			//Clear output buffer
        Sleep(5);
        ftStatus = FT_GetQueueStatus(ftHandle, &dwNumInputBuffer);
    }
    ftStatus = FT_Read(ftHandle, InputBuffer, dwNumInputBuffer, &dwNumBytesRead);  	//Read one byte from device receive buffer
    //qDebug()<<dwNumBytesRead<<"|"<<InputBuffer[dwNumBytesRead-1];

    return InputBuffer[dwNumBytesRead-1];

}
RTDDLL_API BYTE RTD2785_ReadByte(BYTE addr1,BYTE addr2)
{
    I2C_Write(0x6A,0x01,&addr1);
    I2C_Write(0x6A,0x3A,&addr2);
    return I2C_Read(0x6B,0x08);
}

RTDDLL_API bool __stdcall RTD2758Init(void)
{
	ftStatus = FT_ListDevices((PVOID)devIndex,&Buf, FT_LIST_BY_INDEX|FT_OPEN_BY_SERIAL_NUMBER);
    ftStatus = FT_OpenEx((PVOID)Buf, FT_OPEN_BY_SERIAL_NUMBER, &ftHandle);
    if (ftStatus != FT_OK)
    {
            return false;
    }
    else
	{
		ftStatus |= FT_ResetDevice(ftHandle); 	//Reset USB device
        //Purge USB receive buffer first by reading out all old data from FT2232H receive buffer
        ftStatus |= FT_GetQueueStatus(ftHandle, &dwNumInputBuffer);	 // Get the number of bytes in the FT2232H receive buffer
        if ((ftStatus == FT_OK) && (dwNumInputBuffer > 0))
            FT_Read(ftHandle, &InputBuffer, dwNumInputBuffer, &dwNumBytesRead);  	//Read out the data from FT2232H receive buffer
        ftStatus |= FT_SetUSBParameters(ftHandle, 65536, 65535);	//Set USB request transfer size
        ftStatus |= FT_SetChars(ftHandle, false, 0, false, 0);	 //Disable event and error characters
        ftStatus |= FT_SetTimeouts(ftHandle, 0, 5000);		//Sets the read and write timeouts in milliseconds for the FT2232H
        ftStatus |= FT_SetLatencyTimer(ftHandle, 16);		//Set the latency timer
        ftStatus |= FT_SetBitMode(ftHandle, 0x0, 0x00); 		//Reset controller
        ftStatus |= FT_SetBitMode(ftHandle, 0x0, 0x02);	 	//Enable MPSSE mode
        if (ftStatus != FT_OK)
        {
           return false;
        }
    }
	Sleep(30);
    //////////////////////////////////////////////////////////////////
    // Synchronize the MPSSE interface by sending bad command ¡®0xAA¡¯
    //////////////////////////////////////////////////////////////////
    OutputBuffer[dwNumBytesToSend++] = '\xAA';		//Add BAD command ¡®0xAA¡¯
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);	// Send off the BAD commands
    dwNumBytesToSend = 0;			//Clear output buffer
    do{
        ftStatus = FT_GetQueueStatus(ftHandle, &dwNumInputBuffer);	 // Get the number of bytes in the device input buffer
    }while ((dwNumInputBuffer == 0) && (ftStatus == FT_OK));   	//or Timeout

    bool bCommandEchod = false;
    ftStatus = FT_Read(ftHandle, &InputBuffer, dwNumInputBuffer, &dwNumBytesRead);  //Read out the data from input buffer
    for (dwCount = 0; dwCount < dwNumBytesRead - 1; dwCount++)	//Check if Bad command and echo command received
    {
        if ((InputBuffer[dwCount] == BYTE('\xFA')) && (InputBuffer[dwCount+1] == BYTE('\xAA')))
        {
            bCommandEchod = true;
            break;
        }
    }
    if (bCommandEchod == false)
    {
        return false;
    }

    ////////////////////////////////////////////////////////////////////
    //Configure the MPSSE for I2C
    //////////////////////////////////////////////////////////////////
    OutputBuffer[dwNumBytesToSend++] = '\x8A'; 	//Ensure disable clock divide by 5 for 60Mhz master clock
    OutputBuffer[dwNumBytesToSend++] = '\x97';	 //Ensure turn off adaptive clocking
    OutputBuffer[dwNumBytesToSend++] = '\x8D'; 	//Enable 3 phase data clock, used by I2C to allow data on both clock edges
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);	// Send off the commands
    dwNumBytesToSend = 0;			//Clear output buffer
    OutputBuffer[dwNumBytesToSend++] = '\x80'; 	//Command to set directions of lower 8 pins and force value on bits set as output
    OutputBuffer[dwNumBytesToSend++] = '\x03'; 	//Set SDA, SCL high, WP disabled by SK, DO at bit ¡®1¡¯, GPIOL0 at bit ¡®0¡¯
    OutputBuffer[dwNumBytesToSend++] = '\x13';	//Set SK,DO,GPIOL0 pins as output with bit ¡¯1¡¯, other pins as input with bit ¡®0¡¯
    // The SK clock frequency can be worked out by below algorithm with divide by 5 set as off
    // SK frequency  = 60MHz /((1 +  [(1 +0xValueH*256) OR 0xValueL])*2)
    OutputBuffer[dwNumBytesToSend++] = '\x86'; 			//Command to set clock divisor
    OutputBuffer[dwNumBytesToSend++] = dwClockDivisor & '\xFF';	//Set 0xValueL of clock divisor
    OutputBuffer[dwNumBytesToSend++] = (dwClockDivisor >> 8) & '\xFF';	//Set 0xValueH of clock divisor
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);	// Send off the commands
    dwNumBytesToSend = 0;			//Clear output buffer
    Sleep(20);		//Delay for a while

    //Turn off loop back in case
    OutputBuffer[dwNumBytesToSend++] = '\x85';		//Command to turn off loop back of TDI/TDO connection
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);	// Send off the commands
    dwNumBytesToSend = 0;			//Clear output buffer
    Sleep(30);		//Delay for a while

	return true;
}

RTDDLL_API void __stdcall RTD2758_Run(void)
{
	BYTE runcode = 0x00;
    I2C_Write(0x6A,0x80,&runcode);
}

RTDDLL_API void __stdcall RTD2758_Stop(void)
{
	BYTE stopcode = 0x01;
    I2C_Write(0x6A,0x80,&stopcode);
}

RTDDLL_API void __stdcall RTD2758_Reset(void)
{
	BYTE code1 = 0x80, code2 = 0x46;
	I2C_Write(0x94,0x6F,&code1);
	I2C_Write(0x94,0xEE,&code2);
}

RTDDLL_API void __stdcall Set_GammaEnable(bool enable)
{
	BYTE stopcode = 0x01;
    I2C_Write(0x6A,0x80,&stopcode);
	if(enable)
		RTD2785_WriteByte(0x60,0x00,0x67);
	else
		RTD2785_WriteByte(0x20,0x00,0x67);
    ftStatus = FT_Write(ftHandle, OutputBuffer, dwNumBytesToSend, &dwNumBytesSent);		//Send off the commands
    dwNumBytesToSend = 0;			//Clear output buffer
}

RTDDLL_API void __stdcall Read_GammaTable(BYTE *arry)
{
	int i;
    BYTE stopcode = 0x01;
    I2C_Write(0x6A,0x80,&stopcode);

    //start
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);

    //set red
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x80,0x00,0x67);
    //read
    for(i = 0;i < 2052;i++)
    {
        arry[i] = RTD2785_ReadByte(0x00,0x66);
    }

    //set green
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x90,0x00,0x67);
    //read
    for(i = 2052;i < 4104;i++)
    {
        arry[i] = RTD2785_ReadByte(0x00,0x66);
    }

    //set blue
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0xA0,0x00,0x67);
    //read
    for(i = 4104;i < 6156;i++)
    {
        arry[i] = RTD2785_ReadByte(0x00,0x66);
    }

    //end
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x60,0x00,0x67);
}

RTDDLL_API void __stdcall Read_GammaRGBTable(BYTE type,BYTE *arry)
{
	int i;
	BYTE stopcode = 0x01,typecode;
    I2C_Write(0x6A,0x80,&stopcode);

	switch(type)
	{
	case GAMMA_RED:
		typecode = 0x80;
		break;
	case GAMMA_GREEN:
		typecode = 0x90;
		break;
	case GAMMA_BLUE:
		typecode = 0xA0;
		break;
	default:
		return;
	}

	//start
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);

    //set color
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(typecode,0x00,0x67);
    //read
    for(i = 0;i < 2052;i++)
    {
        arry[i] = RTD2785_ReadByte(0x00,0x66);
    }

	//end
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x60,0x00,0x67);
}

RTDDLL_API void __stdcall Write_GammaTable(BYTE *arry)
{
	int i;
	BYTE stopcode = 0x01;
    I2C_Write(0x6A,0x80,&stopcode);
    //start
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x01,0x00,0x67);

    //set red
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x80,0x00,0x67);
    //write
    for(i = 0;i < 2052;i++)
    {
        RTD2785_WriteByte(arry[i],0x00,0x66);
    }
    //set green
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x90,0x00,0x67);
    //write
    for(i = 2052;i < 4104;i++)
    {
        RTD2785_WriteByte(arry[i],0x00,0x66);
    }
    //set blue
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0xA0,0x00,0x67);
    //write
    for(i = 4104;i < 6156;i++)
    {
        RTD2785_WriteByte(arry[i],0x00,0x66);
    }

    //end
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x60,0x00,0x67);//gamma enable

}

RTDDLL_API void __stdcall Write_GammaRGBTable(BYTE type,BYTE *arry)
{
	int i;
	BYTE stopcode = 0x01,typecode;
    I2C_Write(0x6A,0x80,&stopcode);

	switch(type)
	{
	case GAMMA_RED:
		typecode = 0x80;
		break;
	case GAMMA_GREEN:
		typecode = 0x90;
		break;
	case GAMMA_BLUE:
		typecode = 0xA0;
		break;
	default:
		return;
	}

	 //start
    RTD2785_WriteByte(0x20,0x00,0x67);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x09,0xD0);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x01,0x00,0x67);

	//set color
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(0x10,0x00,0x67);
    RTD2785_WriteByte(0x00,0x00,0x67);
    RTD2785_WriteByte(typecode,0x00,0x67);
    //write
    for(i = 0;i < 2052;i++)
    {
        RTD2785_WriteByte(arry[i],0x00,0x66);
    }
}

RTDDLL_API void __stdcall DDCCI_EraseGamma(BYTE gammaID)
{
	BYTE sendbuf[4];
	sendbuf[0] = 2;
	sendbuf[1] = 0xAA;
	sendbuf[2] = _DDCCI_OPCODE_GAMMA_ERASE;
	sendbuf[3] = gammaID;
	I2C_WriteBlock(0x6E,0x00,4,sendbuf);
}

RTDDLL_API bool __stdcall DDCCI_WriteGamma(BYTE *gammabuff,BYTE gammaID)
{
	WORD offset = 0;
	BYTE sendbuf[128];
	if(gammaID > 7)return false;
	while(offset<6156)
	{
		sendbuf[1] = 0xAA;//ddcci command code
		sendbuf[2] = _DDCCI_OPCODE_GAMMA_SETDATA;//ddc gamma command code
		sendbuf[3] = offset/0x100;//offset high
		sendbuf[4] = offset%0x100;//offset low
		sendbuf[5] = gammaID;//gammatable id 0~3
		//gamma data
		if(offset<6100)
		{
			memcpy(sendbuf+6,gammabuff + offset,100);
			offset+=100;
			sendbuf[0] = 104;//lenth
		}
		else
		{
			memcpy(sendbuf+6,gammabuff + offset,56);
			offset+=56;
			sendbuf[0] = 60;//lenth
		}
		I2C_WriteBlock(0x6E,0x00,sendbuf[0]+3,sendbuf);
		Sleep(300);
	}
	return true;
}

RTDDLL_API void __stdcall DDCCI_EnableGamma(bool isenable)
{
	BYTE sendbuf[3];
	sendbuf[0] = 2;
	sendbuf[1] = 0xAA;
	
	if(isenable)sendbuf[2] = _DDCCI_OPCODE_GAMMA_ENABLE;
	else sendbuf[2] = _DDCCI_OPCODE_GAMMA_DISABLE;
	
	I2C_WriteBlock(0x6E,0x00,3,sendbuf);
}

RTDDLL_API void __stdcall DDCCI_SetGamma(BYTE gammaID)
{
	BYTE sendbuf[4];
	sendbuf[0] = 2;
	sendbuf[1] = 0xAA;
	sendbuf[2] = _DDCCI_OPCODE_GAMMA_USEDATA;
	sendbuf[3] = gammaID;
	I2C_WriteBlock(0x6E,0x00,4,sendbuf);
}

RTDDLL_API void __stdcall DDCI_ReadGamma(void)
{
	
}

RTDDLL_API int __stdcall getDLLversion(void)
{
	return DLL_VERSION_VALUE;
}

//auto backlight adjust
RTDDLL_API void __stdcall DDCCI_ABA_Enable(bool isenable)
{
	BYTE sendbuf[4];
	sendbuf[0] = 2;
	sendbuf[1] = 0xA0;
	sendbuf[2] = 0x02;
	
	if(isenable)sendbuf[3] = 0x01;
	else sendbuf[3] = 0x00;
	
	I2C_WriteBlock(0x6E,0x00,4,sendbuf);
}

RTDDLL_API void __stdcall DDCCI_ABA_SetValue(WORD value)
{
	BYTE sendbuf[5];
	sendbuf[0] = 3;
	sendbuf[1] = 0xA0;
	sendbuf[2] = 0x01;
	
	sendbuf[3] = value>>8;
	sendbuf[4] = value;
	
	I2C_WriteBlock(0x6E,0x00,5,sendbuf);
}

RTDDLL_API void __stdcall DDCCI_ABA_GetValue(BYTE *data)
{
	BYTE sendbuf[3],i;
	sendbuf[0] = 1;
	sendbuf[1] = 0xA0;
	sendbuf[2] = 0x03;//query value command
	
	I2C_WriteBlock(0x6E,0x00,3,sendbuf);

	Sleep(10);

	for(i = 0;i<5;i++)
		data[i] = DDC_Read(0x6E,0x00);
	
}

RTDDLL_API void __stdcall DDCCI_OSD_KEYEvent(BYTE value)
{
	BYTE sendbuf[3];
	sendbuf[0] = 1;//length
	sendbuf[1] = 0xB0;//keyevent command
	sendbuf[2] = value;//key data
	
	I2C_WriteBlock(0x6E,0x00,3,sendbuf);
}

RTDDLL_API void __stdcall DDCCI_EraseBacklight(BYTE BacklightIndex)
{
	BYTE sendbuf[4];
	sendbuf[0] = 2;
	sendbuf[1] = 0xBB;
	sendbuf[2] = _DDCCI_OPCODE_BACKLIGHT_ERASE;
	sendbuf[3] = BacklightIndex;

	I2C_WriteBlock(0x6E,0x00,4,sendbuf);
}

RTDDLL_API bool __stdcall DDCCI_WriteBacklight(BYTE BacklightIndex,WORD LightValue,WORD PWMValue)
{
	BYTE sendbuf[8];
	if(BacklightIndex > 9)return false;
	sendbuf[0] = 6;//lenth
	sendbuf[1] = 0xBB;//ddcci command code
	sendbuf[2] = _DDCCI_OPCODE_BACKLIGHT_SETFLASHDATA;//
	sendbuf[3] = BacklightIndex;
	sendbuf[4] = LightValue>>8;
	sendbuf[5] = LightValue;
	sendbuf[6] = PWMValue>>8;
	sendbuf[7] = PWMValue;

	I2C_WriteBlock(0x6E,0x00,8,sendbuf);
	Sleep(10);
	return true;
}

RTDDLL_API void __stdcall DDCCI_ReadBacklight(BYTE BacklightIndex,BYTE *data)
{
	BYTE sendbuf[4],i,j,CheckSum;
	sendbuf[0] = 2;//lenth
	sendbuf[1] = 0xBB;//ddcci command code
	sendbuf[2] = _DDCCI_OPCODE_BACKLIGHT_GETFLASHDATA;//
	sendbuf[3] = BacklightIndex;
	for(j=0;j<20;j++)
	{
		I2C_WriteBlock(0x6E,0x00,4,sendbuf);
		Sleep(10);
		for(i = 0;i<9;i++)
			data[i] = DDC_Read(0x6E,0x00);
		CheckSum = DDCCI_CheckSum(data);
		if(data[8]==CheckSum)
			break;
	}
}

RTDDLL_API void __stdcall DDCCI_GetBacklight(BYTE *data)
{
	BYTE sendbuf[3],i,j,CheckSum;
	sendbuf[0] = 1;
	sendbuf[1] = 0xBB;
	sendbuf[2] = _DDCCI_OPCODE_BACKLIGHT_GETDATA;//query value command
	for(j=0;j<20;j++)
	{
		I2C_WriteBlock(0x6E,0x00,3,sendbuf);
		Sleep(10);
		for(i = 0;i<8;i++)
			data[i] = DDC_Read(0x6E,0x00);
		CheckSum = DDCCI_CheckSum(data);
		if(data[7]==CheckSum)
			break;
	}
}

RTDDLL_API void __stdcall DDCCI_UseBacklight(WORD LightValue,WORD PWMValue)
{
	BYTE sendbuf[7];
	sendbuf[0] = 5;
	sendbuf[1] = 0xBB;
	sendbuf[2] = _DDCCI_OPCODE_BACKLIGHT_USEDATA;//query value command
	sendbuf[3] = LightValue>>8;
	sendbuf[4] = LightValue;
	sendbuf[5] = PWMValue>>8;
	sendbuf[6] = PWMValue;

	I2C_WriteBlock(0x6E,0x00,7,sendbuf);
}

RTDDLL_API BYTE DDCCI_CheckSum(BYTE *data)
{
	BYTE Count = 0;
	BYTE CheckLen = 0;
	BYTE Sum = _DDCCI_VIRTUAL_HOST_ADDRESS;

	CheckLen = ((data[1])&0x7F)+2;

	for(Count = 0;Count < CheckLen; Count++)
	{
		Sum = Sum ^ data[Count];
	}

	return Sum;
}
