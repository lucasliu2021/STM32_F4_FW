//
// Created by lucas on 2022/3/24.
//
#include "main_task.h"
#include "first_init.h"

uint8_t open = 1;
uint8_t place = 0;



void out(uint8_t out);

uint8_t inside(uint8_t enter);

void SPB_Task(uint8_t place);

void main_task(uint8_t mode, uint8_t back, uint8_t enter)
{
    //�л�����
    if (clear == 1)
    {
        Lcd_Clear(BLACK);
        clear = 0;

    }
    //������ʾ
    if (mode < 4 && open == 1)
    {
        show_menu(binDisplay("SYSTEM/desktop1.bin"), open);
    } else if (mode < 8 && open == 1)
    {
        show_menu(binDisplay("SYSTEM/desktop2.bin"), open);
    } else if (mode < 12 && open == 1)
    {
        show_menu(binDisplay("SYSTEM/desktop3.bin"), open);
    }
    //����ѡ��
    switch (mode)
    {
        case 0:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(1);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                temperature();//�¶Ȳ���
            }
            //�Ƴ�����
            out(back);
            break;
        case 1:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(2);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                select_within_screen = 1;
                screen_light();//������Ļ���ȵ��ں���
            }
            //�Ƴ�����
            out(back);
            if (back == 1)
            {
                select_within_screen = 0;
            }
            break;
        case 2:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(3);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                select_within_signal = 1;
                signal_generation();
            }
            //�Ƴ�����
            out(back);
            if (back == 1)
            {
                select_within_signal = 0;
            }
            break;
        case 3:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(4);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                oscilloscope();
            }
            //�Ƴ�����
            out(back);
            break;
        case 4:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(1);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                stopwatch();
            }
            //�Ƴ�����
            out(back);
            if (back == 1)
            {
                watch_init();
            }
            break;
        case 5:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(2);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                gallery();//ͼ��app
            }
            //�Ƴ�����
            out(back);
            break;
        case 6:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(3);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                Bluetooth_communication();//������Ϸ
            }
            //�Ƴ�����
            out(back);
            break;
        case 7://����
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(4);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                Gui_DrawFont_GBK16(0, 80, WHITE, BLACK, "Undeveloped");
            }
            //�Ƴ�����
            out(back);
            break;
        case 8://������Ϸ
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(1);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                Gui_DrawFont_GBK16(0, 80, WHITE, BLACK, "Undeveloped");
            }
            //�Ƴ�����
            out(back);
            break;
        case 9://������
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(2);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                Gui_DrawFont_GBK16(0, 80, WHITE, BLACK, "Undeveloped");
            }
            //�Ƴ�����
            out(back);
            break;
        case 10://����
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(3);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                select_within_setting = 1;
                setting();
            }
            //�Ƴ�����
            out(back);
            if (back == 1)
            {
                select_within_setting = 0;
            }
            break;
        case 11:
            //����ѡ�п�
            if (open == 1 && enter == 0)
            {
                SPB_Task(4);
            }
            //��������ִ��
            if (inside(enter) == 1)
            {
                about();
            }
            //�Ƴ�����
            out(back);
            break;
        default:
            break;
    }
}

/*//״̬��
if (open != 0)
{
    bar_timer();
}*/
void out(uint8_t out)//�Ƴ�����
{
    //�Ƴ�����
    if (out == 1)
    {
        if (open != 1)
        {
            Lcd_Clear(BLACK);
        }
        open = 1;
    }
}

uint8_t inside(uint8_t inside)//���뺯��
{
    uint8_t stop = 0;
    //��������ִ��
    if (inside == 1)
    {
        if (open != 0)
        {
            Lcd_Clear(BLACK);
        }
        open = 0;
        stop = 1;
    }
    return stop;

}

void SPB_Task(uint8_t place)//ѡ�����
{
    switch (place)
    {
        case 1:
            DisplayButtonUp(5, 25, 60, 90);
            break;
        case 2:
            DisplayButtonUp(70, 25, 120, 90);
            break;
        case 3:
            DisplayButtonUp(5, 90, 60, 155);
            break;
        case 4:
            DisplayButtonUp(70, 90, 120, 155);
            break;
        default:
            break;
    }
}