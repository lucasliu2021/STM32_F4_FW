//
// Created by lucas on 2022/3/26.
//

#include "gallery.h"
#include "GUI.h"
#include "delay.h"
#include "wareroom.h"
void gallery()
{
    for (uint8_t i = 0; i < 5; i++)
    {
        show_pic_custm(binDisplay("PICTURE/1.bin"));
        delay_ms(1000);
        show_pic_custm(binDisplay("PICTURE/2.bin"));
        delay_ms(1000);
        show_pic_custm(binDisplay("PICTURE/3.bin"));
        delay_ms(1000);
        show_pic_custm(binDisplay("PICTURE/4.bin"));
        delay_ms(1000);
        show_pic_custm(binDisplay("PICTURE/5.bin"));
        delay_ms(3000);
    }
//    if (HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_2)==0||HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3)==0)
//    {
//        if (a<6){
//            a++;
//        }else
//        {
//            a=0;
//        }
//    }
//    switch (a)
//    {
//        case 5:
//        case 0:show_pic_custm(binDisplay("PICTURE/1.bin"));
//            break;
//        case 1:show_pic_custm(binDisplay("PICTURE/2.bin"));
//            break;
//        case 2:show_pic_custm(binDisplay("PICTURE/3.bin"));
//            break;
//        case 3:show_pic_custm(binDisplay("PICTURE/4.bin"));
//            break;
//        case 4:show_pic_custm(binDisplay("PICTURE/5.bin"));
//            break;
//        case 5:
//        default:
//            break;
//    }

}