//
// Created by lucas on 2022/3/26.
//

#include "gallery.h"
#include "GUI.h"
#include "delay.h"
#include "wareroom.h"
void gallery()
{
    for (uint8_t i = 4; i < 9; i++)
    {
        show_pic_custm(ware_room_read(i));
        delay_ms(2000);
    }
}