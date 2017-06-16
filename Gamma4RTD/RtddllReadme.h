//询问dll版本号
int getDLLversion(void);

//FTD初始化
bool RTD2758Init(void);

//debug mode
//调试模式
//调试模式下支持对驱动板的暂停 运行和重启操作
//以及对驱动板内正在使用的GAMMA数据进行操作
//关闭ddcci 自动进入调试模式
//--------------------------------------------------
// Description  : Run IC
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:运行IC 
//-------------------------------------------------
void RTD2758_Run(void);

//--------------------------------------------------
// Description  : Stop IC
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:停止运行IC  
//所有有关Gamma的操作均会停止运行IC
//-------------------------------------------------
void RTD2758_Stop(void);

//--------------------------------------------------
// Description  : Reset IC
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:重启IC  
//-------------------------------------------------
void RTD2758_Reset(void);

//--------------------------------------------------
// Description  : Enable or Disable Gamma
// parameter    : bool enable
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:打开或者关闭Gamma 功能
//参数:enable :选择打开或者关闭
//-------------------------------------------------
void Set_GammaEnable(bool enable);

//--------------------------------------------------
// Description  : Read  Gamma data which  is currently in use 
// parameter    : arry: data buffer to save the read data
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:读取正在使用的Gamma表数据
//参数:arry :将读取的Gamma数据存在arry数组中
//arry至少需要6156 BYTE 空间
//-------------------------------------------------
void Read_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Read  R,G,B Gamma data which  is currently in use 
// parameter    : type: choose R,G or B data   
//	            arry: data buffer to save the read data
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:读取正在使用的Gamma表中R,G,B颜色数据
//参数: type :红色值为'1' ,绿色 值为'2' , 蓝色值为'3'
//arry :将读取的Gamma数据存在arry数组中
//arry至少需要2052 BYTE 空间
//-------------------------------------------------
void Read_GammaRGBTable(BYTE type,BYTE *arry);

//--------------------------------------------------
// Description  : Write Gamma data to use 
// parameter    : arry: data buffer to write
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:写入Gamma数据并使用
//参数: arry:将arry中存储的数据写入
//arry至少提供6156 BYTE 
//-------------------------------------------------
void Write_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Write R,G,B Gamma data to use 
// parameter    : type: choose R,G or B data   
//			arry: data buffer to write
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:写入Gamma表中 R或G或B数据并使用
//参数: type: 红色值为'1' ,绿色 值为'2' , 蓝色值为'3'
//arry:将arry中存储的数据写入
//arry至少提供2052 BYTE 
//-------------------------------------------------
void Write_GammaRGBTable(BYTE type,BYTE *arry);



//DDC CI
//DDC_CI模式
//该模式可以对驱动板存储的gamma表进行擦除和写入操作
//驱动板一共支持8张gamma表格编号为0 ~8
//打开DDC_CI自动进入该模式
//--------------------------------------------------
// Description  : Erase Gamma data in flash
// parameter    : gammaID: GammaTable id
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:擦除指定的Gamma表数据
//参数: gammaID: 擦除的表格ID 范围:0~7
//-------------------------------------------------
void DDCCI_EraseGamma(BYTE gammaID);

//--------------------------------------------------
// Description  : Write Gamma data to flash
// parameter    : gammabuff: data buffer to write
//			gammaID: GammaTable id
// return       : TRUE for write success and FALSE for write fail
//--------------------------------------------------
//-------------------------------------------------
//说明:向指定的gamma表格写入数据 在写入前要先擦除
//参数: gammabuff:将gammabuff中存储的数据写入
//gammaID :表格ID 范围:0~7
//返回:传入的id有误返回false 否则返回true
//-------------------------------------------------
bool DDCCI_WriteGamma(BYTE *gammabuff,BYTE gammaID);

//--------------------------------------------------
// Description  : Enable or Disable Gamma
// parameter    : bool enable
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:打开或者关闭Gamma 功能
//参数:enable :选择打开或者关闭
//-------------------------------------------------
void DDCCI_EnableGamma(bool isenable);

//--------------------------------------------------
// Description  : enable Gamma and choose Gamma data to use. 
// parameter    : gammaID: GammaTable id
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:使用指定的gamma数据
//参数:gammaID :表格ID 范围:0~7
//-------------------------------------------------
void DDCCI_SetGamma(BYTE gammaID);

//--------------------------------------------------
// Description  : DDC_CI simulation Menu Key function 
// parameter    : value
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明：DDC_CI模拟菜单按键功能
//参数：value：按键功能选择
//		MENU_KEY_VALUE 0x01
//		EXIT_KEY_VALUE 0x02
//		LEFT_KEY_VALUE 0x03
//		RIGHT_KEY_VALUE 0x04
//-------------------------------------------------
void DDCCI_OSD_KEYEvent(BYTE value);

//--------------------------------------------------
// Description  : Enable or Disable Auto Backlight Adjust（ABA） 
// parameter    : bool true or false
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明：背光恒定功能开/关
//参数：true：打开背光恒定功能；false：关闭背光恒定功能
//-------------------------------------------------
void DDCCI_ABA_Enable(bool isenable);

//--------------------------------------------------
// Description  : Erase Backlight Adjust data in flash
// parameter    : BacklightIndex：Brightness list
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:擦除Flash中指定的亮度值列表的背光调节数据
//参数:BacklightIndex：亮度列表，一共十组数据，取值范围：0-9。
//-------------------------------------------------
void DDCCI_EraseBacklight(BYTE BacklightIndex);

//--------------------------------------------------
// Description  : Write Backlight Adjust data to flash
// parameter    : BacklightIndex：Brightness list
//				  LightValue：Brightness value,Compare with the value of the Brightness Sensor
//				  PWMValue：PWM value
// return       : TRUE for write success and FALSE for write fail
//--------------------------------------------------
//-------------------------------------------------
//说明:在Flash中写入对应的亮度值列表的数据，写入前需要先擦除对应的Flash
//参数: BacklightIndex：亮度列表，一共十组数据，取值范围：0-9。
//		LightValue：传感器亮度设定值，与亮度传感器的监测值进行对比
//		PWMValue：初始PWM值，当LightValue与传感器监测值比对超过一定范围后PWM值开始在此值上下一定范围内调节
//		注意：写入Flash中的一组数据共5 Byte，BacklightIndex -- 1 Byte，LightValue -- 2 Byte，PWMValue -- 2 Byte。
//返回:传入的Index有误返回false 否则返回true
//-------------------------------------------------
bool DDCCI_WriteBacklight(BYTE BacklightIndex,WORD LightValue,WORD PWMValue);

//--------------------------------------------------
// Description  : Read Backlight Adjust data from flash
// parameter    : BacklightIndex：Brightness list
//				  data: data buffer to save the read data
// return       : TRUE for read success and FALSE for read fail
//--------------------------------------------------
//-------------------------------------------------
//说明:读取存入Flash中对应亮度值列表的数据
//参数: BacklightIndex：亮度列表，一共十组数据，取值范围：0-9。
//		data:数组指针，存放从Flash中读取的数据，9个字节大小。
//		data[0]-data[2]：固定位
//		data[3]：BacklightIndex
//		data[4]：LightValue高8位，data[5]：LightValue低8位
//		data[6]：PWMValue高8位，data[7]：PWMValue低8位
//		data[8]：校验位
//返回:读取成功则返回true，否则返回false
//		注意：校验位错误将循环读取数据，设置循环20次，20次内校验成功则返回读取数据，否则返回数据全为0xFF
//-------------------------------------------------
bool DDCCI_ReadBacklight(BYTE BacklightIndex,BYTE *data);

//--------------------------------------------------
// Description  : Gets the value of the Brightness Sensor and the current PWM value 
// parameter    : data: data buffer to save the read data
// return       : TRUE for read success and FALSE for read fail
//--------------------------------------------------
//-------------------------------------------------
//说明:获取亮度传感器的值和当前PWM值
//参数: data：数组指针，存放读取的亮度传感器的值和当前PWM值，8个字节大小。
//		data[0]-data[2]：固定位
//		data[3]：亮度传感器值高8位，data[4]：亮度传感器值低8位
//		data[5]：当前PWM值高8位，data[6]：当前PWM值低8位
//		data[7]：校验位
//返回:读取成功则返回true，否则返回false
//		注意：校验位错误将循环读取数据，设置循环20次，20次内校验成功则返回读取数据，否则返回数据全为0xFF
//-------------------------------------------------
bool DDCCI_GetBacklight(BYTE *data);

//--------------------------------------------------
// Description  : Apply the current set of PWM values
// parameter    : LightValue：void
//				  PWMValue：PWM application settings, the application will adjust the value of PWM to this size
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//说明:应用当前设定的PWM值
//参数: LightValue：保留未使用，2 Byte
//		PWMValue：PWM的应用设定值，2 Byte，应用后会调节PWM到此值大小
//-------------------------------------------------
void DDCCI_UseBacklight(WORD LightValue,WORD PWMValue);

