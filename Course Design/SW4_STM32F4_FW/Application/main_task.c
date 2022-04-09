
//
// Created by lucas on 2022/3/24.
//
#include "main_task.h"
#include "first_init.h"
#include "pic.h"

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
        show_menu(gImage_first, open);
    } else if (mode < 8 && open == 1)
    {
        show_menu(gImage_second, open);
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
                screen = 1;
                screen_light();//������Ļ���ȵ��ں���
            }
            //�Ƴ�����
            out(back);
            if (back == 1)
            {
                screen = 0;
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
                screen = 1;
                signal_generation();
            }
            //�Ƴ�����
            out(back);
            if (back == 1)
            {
                screen = 0;
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
                bth_game();//������Ϸ
            }
            //�Ƴ�����
            out(back);
            break;
        case 7:
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