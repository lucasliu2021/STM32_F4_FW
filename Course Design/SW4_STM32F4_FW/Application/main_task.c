
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
    //切换清屏
    if (clear == 1)
    {
        Lcd_Clear(BLACK);
        clear = 0;

    }
    //背景显示
    if (mode < 4 && open == 1)
    {
        show_menu(gImage_first, open);
    } else if (mode < 8 && open == 1)
    {
        show_menu(gImage_second, open);
    }
    //任务选择
    switch (mode)
    {
        case 0:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(1);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                temperature();//温度测试
            }
            //推出任务
            out(back);
            break;
        case 1:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(2);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                screen = 1;
                screen_light();//进入屏幕亮度调节函数
            }
            //推出任务
            out(back);
            if (back == 1)
            {
                screen = 0;
            }
            break;
        case 2:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(3);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                screen = 1;
                signal_generation();
            }
            //推出任务
            out(back);
            if (back == 1)
            {
                screen = 0;
            }
            break;
        case 3:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(4);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                oscilloscope();
            }
            //推出任务
            out(back);
            break;
        case 4:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(1);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                stopwatch();
            }
            //推出任务
            out(back);
            if (back == 1)
            {
                watch_init();
            }
            break;
        case 5:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(2);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                gallery();//图库app
            }
            //推出任务
            out(back);
            break;
        case 6:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(3);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                bth_game();//蓝牙游戏
            }
            //推出任务
            out(back);
            break;
        case 7:
            //任务选中框
            if (open == 1 && enter == 0)
            {
                SPB_Task(4);
            }
            //进入任务执行
            if (inside(enter) == 1)
            {
                about();
            }
            //推出任务
            out(back);
            break;
        default:
            break;
    }
}

/*//状态栏
if (open != 0)
{
    bar_timer();
}*/
void out(uint8_t out)//推出函数
{
    //推出任务
    if (out == 1)
    {
        if (open != 1)
        {
            Lcd_Clear(BLACK);
        }
        open = 1;
    }
}

uint8_t inside(uint8_t inside)//进入函数
{
    uint8_t stop = 0;
    //进入任务执行
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

void SPB_Task(uint8_t place)//选择框函数
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