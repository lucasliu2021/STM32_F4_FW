
#include "main.h"

//Ƕ��ʽ������
//�Ա���վ��http://mcudev.taobao.com


//==================================����л���������ʾ=======================================//
//��Lcd_Driver.hͷ�ļ����޸ĺ�#define USE_HORIZONTAL ֵΪ0ʹ������ģʽ.1,ʹ�ú���ģʽ
//===========================ģ��SPI��������==========================================//


//����LCD�ĳߴ�

#if USE_HORIZONTAL==1	//ʹ�ú���
#define X_MAX_PIXEL	        160
#define Y_MAX_PIXEL	        128
#else
#define X_MAX_PIXEL	        128
#define Y_MAX_PIXEL	        160
#endif
