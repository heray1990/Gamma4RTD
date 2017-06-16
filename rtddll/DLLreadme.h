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
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:运行IC 
//-------------------------------------------------
void RTD2758_Run(void);

//--------------------------------------------------
// Description  : Stop IC
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:停止运行IC  
//所有有关Gamma的操作均会停止运行IC
//-------------------------------------------------
void RTD2758_Stop(void);

//--------------------------------------------------
// Description  : Reset IC
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:重启IC  
//-------------------------------------------------
void RTD2758_Reset(void);

//--------------------------------------------------
// Description  : Enable or Disable Gamma
// Input Value  : bool enable
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:打开或者关闭Gamma 功能
//参数:enable :选择打开或者关闭
//-------------------------------------------------
void Set_GammaEnable(bool enable);

//--------------------------------------------------
// Description  : Read  Gamma data which  is currently in use 
// Input Value  : arry: data buffer to save the read data
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:读取正在使用的Gamma表数据
//参数:arry :将读取的Gamma数据存在arry数组中
//arry至少需要6156 BYTE 空间
//-------------------------------------------------
void Read_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Read  R,G,B Gamma data which  is currently in use 
// Input Value  : type: choose R,G or B data   
//			    arry: data buffer to save the read data
// Output Value : None
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
// Input Value  : arry: data buffer to write
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:写入Gamma数据并使用
//参数: arry:将arry中存储的数据写入
//arry至少提供6156 BYTE 
//-------------------------------------------------
void Write_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Write R,G,B Gamma data to use 
// Input Value  : type: choose R,G or B data   
//			    arry: data buffer to write
// Output Value : None
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
// Input Value  : gammaID: GammaTable id
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:擦除指定的Gamma表数据
//参数: gammaID: 擦除的表格ID 范围:0~7
//-------------------------------------------------
void DDCCI_EraseGamma(BYTE gammaID);

//--------------------------------------------------
// Description  : Write Gamma data to flash
// Input Value  : gammabuff: data buffer to write
//			    gammaID: GammaTable id
// Output Value : TRUE for write success and FALSE for write fail
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
// Input Value  : bool enable
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:打开或者关闭Gamma 功能
//参数:enable :选择打开或者关闭
//-------------------------------------------------
void DDCCI_EnableGamma(bool isenable);

//--------------------------------------------------
// Description  :  enable Gamma and choose Gamma data to use. 
// Input Value  :  gammaID: GammaTable id
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//说明:使用指定的gamma数据
//参数:gammaID :表格ID 范围:0~7
//-------------------------------------------------
void DDCCI_SetGamma(BYTE gammaID);

