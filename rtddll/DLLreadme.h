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
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:����IC 
//-------------------------------------------------
void RTD2758_Run(void);

//--------------------------------------------------
// Description  : Stop IC
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:ֹͣ����IC  
//�����й�Gamma�Ĳ�������ֹͣ����IC
//-------------------------------------------------
void RTD2758_Stop(void);

//--------------------------------------------------
// Description  : Reset IC
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:����IC  
//-------------------------------------------------
void RTD2758_Reset(void);

//--------------------------------------------------
// Description  : Enable or Disable Gamma
// Input Value  : bool enable
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:�򿪻��߹ر�Gamma ����
//����:enable :ѡ��򿪻��߹ر�
//-------------------------------------------------
void Set_GammaEnable(bool enable);

//--------------------------------------------------
// Description  : Read  Gamma data which  is currently in use 
// Input Value  : arry: data buffer to save the read data
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:��ȡ����ʹ�õ�Gamma������
//����:arry :����ȡ��Gamma���ݴ���arry������
//arry������Ҫ6156 BYTE �ռ�
//-------------------------------------------------
void Read_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Read  R,G,B Gamma data which  is currently in use 
// Input Value  : type: choose R,G or B data   
//			    arry: data buffer to save the read data
// Output Value : None
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
// Input Value  : arry: data buffer to write
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:д��Gamma���ݲ�ʹ��
//����: arry:��arry�д洢������д��
//arry�����ṩ6156 BYTE 
//-------------------------------------------------
void Write_GammaTable(BYTE *arry);

//--------------------------------------------------
// Description  : Write R,G,B Gamma data to use 
// Input Value  : type: choose R,G or B data   
//			    arry: data buffer to write
// Output Value : None
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
// Input Value  : gammaID: GammaTable id
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:����ָ����Gamma������
//����: gammaID: �����ı��ID ��Χ:0~7
//-------------------------------------------------
void DDCCI_EraseGamma(BYTE gammaID);

//--------------------------------------------------
// Description  : Write Gamma data to flash
// Input Value  : gammabuff: data buffer to write
//			    gammaID: GammaTable id
// Output Value : TRUE for write success and FALSE for write fail
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
// Input Value  : bool enable
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:�򿪻��߹ر�Gamma ����
//����:enable :ѡ��򿪻��߹ر�
//-------------------------------------------------
void DDCCI_EnableGamma(bool isenable);

//--------------------------------------------------
// Description  :  enable Gamma and choose Gamma data to use. 
// Input Value  :  gammaID: GammaTable id
// Output Value : None
//--------------------------------------------------
//-------------------------------------------------
//˵��:ʹ��ָ����gamma����
//����:gammaID :���ID ��Χ:0~7
//-------------------------------------------------
void DDCCI_SetGamma(BYTE gammaID);

