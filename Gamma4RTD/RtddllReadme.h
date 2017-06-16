//ѯ��dll�汾��
int getDLLversion(void);

//FTD��ʼ��
bool RTD2758Init(void);

//debug mode
//����ģʽ
//����ģʽ��֧�ֶ����������ͣ ���к���������
//�Լ���������������ʹ�õ�GAMMA���ݽ��в���
//�ر�ddcci �Զ��������ģʽ
//--------------------------------------------------
// Description  : Run IC
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:����IC 
//-------------------------------------------------
void RTD2758_Run(void);

//--------------------------------------------------
// Description  : Stop IC
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:ֹͣ����IC  
//�����й�Gamma�Ĳ�������ֹͣ����IC
//-------------------------------------------------
void RTD2758_Stop(void);

//--------------------------------------------------
// Description  : Reset IC
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:����IC  
//-------------------------------------------------
void RTD2758_Reset(void);

//--------------------------------------------------
// Description  : Enable or Disable Gamma
// parameter    : bool enable
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:�򿪻��߹ر�Gamma ����
//����:enable :ѡ��򿪻��߹ر�
//-------------------------------------------------
void Set_GammaEnable(bool enable);

//--------------------------------------------------
// Description  : Read  Gamma data which  is currently in use 
// parameter    : arry: data buffer to save the read data
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:��ȡ����ʹ�õ�Gamma������
//����:arry :����ȡ��Gamma���ݴ���arry������
//arry������Ҫ6156 BYTE �ռ�
//-------------------------------------------------
void Read_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Read  R,G,B Gamma data which  is currently in use 
// parameter    : type: choose R,G or B data   
//	            arry: data buffer to save the read data
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:��ȡ����ʹ�õ�Gamma����R,G,B��ɫ����
//����: type :��ɫֵΪ'1' ,��ɫ ֵΪ'2' , ��ɫֵΪ'3'
//arry :����ȡ��Gamma���ݴ���arry������
//arry������Ҫ2052 BYTE �ռ�
//-------------------------------------------------
void Read_GammaRGBTable(BYTE type,BYTE *arry);

//--------------------------------------------------
// Description  : Write Gamma data to use 
// parameter    : arry: data buffer to write
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:д��Gamma���ݲ�ʹ��
//����: arry:��arry�д洢������д��
//arry�����ṩ6156 BYTE 
//-------------------------------------------------
void Write_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Write R,G,B Gamma data to use 
// parameter    : type: choose R,G or B data   
//			arry: data buffer to write
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:д��Gamma���� R��G��B���ݲ�ʹ��
//����: type: ��ɫֵΪ'1' ,��ɫ ֵΪ'2' , ��ɫֵΪ'3'
//arry:��arry�д洢������д��
//arry�����ṩ2052 BYTE 
//-------------------------------------------------
void Write_GammaRGBTable(BYTE type,BYTE *arry);



//DDC CI
//DDC_CIģʽ
//��ģʽ���Զ�������洢��gamma����в�����д�����
//������һ��֧��8��gamma�����Ϊ0 ~8
//��DDC_CI�Զ������ģʽ
//--------------------------------------------------
// Description  : Erase Gamma data in flash
// parameter    : gammaID: GammaTable id
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:����ָ����Gamma������
//����: gammaID: �����ı��ID ��Χ:0~7
//-------------------------------------------------
void DDCCI_EraseGamma(BYTE gammaID);

//--------------------------------------------------
// Description  : Write Gamma data to flash
// parameter    : gammabuff: data buffer to write
//			gammaID: GammaTable id
// return       : TRUE for write success and FALSE for write fail
//--------------------------------------------------
//-------------------------------------------------
//˵��:��ָ����gamma���д������ ��д��ǰҪ�Ȳ���
//����: gammabuff:��gammabuff�д洢������д��
//gammaID :���ID ��Χ:0~7
//����:�����id���󷵻�false ���򷵻�true
//-------------------------------------------------
bool DDCCI_WriteGamma(BYTE *gammabuff,BYTE gammaID);

//--------------------------------------------------
// Description  : Enable or Disable Gamma
// parameter    : bool enable
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:�򿪻��߹ر�Gamma ����
//����:enable :ѡ��򿪻��߹ر�
//-------------------------------------------------
void DDCCI_EnableGamma(bool isenable);

//--------------------------------------------------
// Description  : enable Gamma and choose Gamma data to use. 
// parameter    : gammaID: GammaTable id
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:ʹ��ָ����gamma����
//����:gammaID :���ID ��Χ:0~7
//-------------------------------------------------
void DDCCI_SetGamma(BYTE gammaID);

//--------------------------------------------------
// Description  : DDC_CI simulation Menu Key function 
// parameter    : value
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵����DDC_CIģ��˵���������
//������value����������ѡ��
//		MENU_KEY_VALUE 0x01
//		EXIT_KEY_VALUE 0x02
//		LEFT_KEY_VALUE 0x03
//		RIGHT_KEY_VALUE 0x04
//-------------------------------------------------
void DDCCI_OSD_KEYEvent(BYTE value);

//--------------------------------------------------
// Description  : Enable or Disable Auto Backlight Adjust��ABA�� 
// parameter    : bool true or false
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��������㶨���ܿ�/��
//������true���򿪱���㶨���ܣ�false���رձ���㶨����
//-------------------------------------------------
void DDCCI_ABA_Enable(bool isenable);

//--------------------------------------------------
// Description  : Erase Backlight Adjust data in flash
// parameter    : BacklightIndex��Brightness list
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:����Flash��ָ��������ֵ�б�ı����������
//����:BacklightIndex�������б�һ��ʮ�����ݣ�ȡֵ��Χ��0-9��
//-------------------------------------------------
void DDCCI_EraseBacklight(BYTE BacklightIndex);

//--------------------------------------------------
// Description  : Write Backlight Adjust data to flash
// parameter    : BacklightIndex��Brightness list
//				  LightValue��Brightness value,Compare with the value of the Brightness Sensor
//				  PWMValue��PWM value
// return       : TRUE for write success and FALSE for write fail
//--------------------------------------------------
//-------------------------------------------------
//˵��:��Flash��д���Ӧ������ֵ�б�����ݣ�д��ǰ��Ҫ�Ȳ�����Ӧ��Flash
//����: BacklightIndex�������б�һ��ʮ�����ݣ�ȡֵ��Χ��0-9��
//		LightValue�������������趨ֵ�������ȴ������ļ��ֵ���жԱ�
//		PWMValue����ʼPWMֵ����LightValue�봫�������ֵ�ȶԳ���һ����Χ��PWMֵ��ʼ�ڴ�ֵ����һ����Χ�ڵ���
//		ע�⣺д��Flash�е�һ�����ݹ�5 Byte��BacklightIndex -- 1 Byte��LightValue -- 2 Byte��PWMValue -- 2 Byte��
//����:�����Index���󷵻�false ���򷵻�true
//-------------------------------------------------
bool DDCCI_WriteBacklight(BYTE BacklightIndex,WORD LightValue,WORD PWMValue);

//--------------------------------------------------
// Description  : Read Backlight Adjust data from flash
// parameter    : BacklightIndex��Brightness list
//				  data: data buffer to save the read data
// return       : TRUE for read success and FALSE for read fail
//--------------------------------------------------
//-------------------------------------------------
//˵��:��ȡ����Flash�ж�Ӧ����ֵ�б������
//����: BacklightIndex�������б�һ��ʮ�����ݣ�ȡֵ��Χ��0-9��
//		data:����ָ�룬��Ŵ�Flash�ж�ȡ�����ݣ�9���ֽڴ�С��
//		data[0]-data[2]���̶�λ
//		data[3]��BacklightIndex
//		data[4]��LightValue��8λ��data[5]��LightValue��8λ
//		data[6]��PWMValue��8λ��data[7]��PWMValue��8λ
//		data[8]��У��λ
//����:��ȡ�ɹ��򷵻�true�����򷵻�false
//		ע�⣺У��λ����ѭ����ȡ���ݣ�����ѭ��20�Σ�20����У��ɹ��򷵻ض�ȡ���ݣ����򷵻�����ȫΪ0xFF
//-------------------------------------------------
bool DDCCI_ReadBacklight(BYTE BacklightIndex,BYTE *data);

//--------------------------------------------------
// Description  : Gets the value of the Brightness Sensor and the current PWM value 
// parameter    : data: data buffer to save the read data
// return       : TRUE for read success and FALSE for read fail
//--------------------------------------------------
//-------------------------------------------------
//˵��:��ȡ���ȴ�������ֵ�͵�ǰPWMֵ
//����: data������ָ�룬��Ŷ�ȡ�����ȴ�������ֵ�͵�ǰPWMֵ��8���ֽڴ�С��
//		data[0]-data[2]���̶�λ
//		data[3]�����ȴ�����ֵ��8λ��data[4]�����ȴ�����ֵ��8λ
//		data[5]����ǰPWMֵ��8λ��data[6]����ǰPWMֵ��8λ
//		data[7]��У��λ
//����:��ȡ�ɹ��򷵻�true�����򷵻�false
//		ע�⣺У��λ����ѭ����ȡ���ݣ�����ѭ��20�Σ�20����У��ɹ��򷵻ض�ȡ���ݣ����򷵻�����ȫΪ0xFF
//-------------------------------------------------
bool DDCCI_GetBacklight(BYTE *data);

//--------------------------------------------------
// Description  : Apply the current set of PWM values
// parameter    : LightValue��void
//				  PWMValue��PWM application settings, the application will adjust the value of PWM to this size
// return       : void
//--------------------------------------------------
//-------------------------------------------------
//˵��:Ӧ�õ�ǰ�趨��PWMֵ
//����: LightValue������δʹ�ã�2 Byte
//		PWMValue��PWM��Ӧ���趨ֵ��2 Byte��Ӧ�ú�����PWM����ֵ��С
//-------------------------------------------------
void DDCCI_UseBacklight(WORD LightValue,WORD PWMValue);

