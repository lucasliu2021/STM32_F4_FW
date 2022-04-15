//
// Created by lucas on 2022/4/15.
//
#include "wareroom.h"
#include "w25qxx.h"

// 把图像读取到数组
unsigned char flash_buffer[40960];

unsigned char *ware_room_read(uint8_t num)
{
    W25qxx_ReadBlock(flash_buffer, num, 0, 40960);
    return flash_buffer;
}

// 把图像写入flash
void ware_room_write()
{
/*    W25qxx_EraseBlock(1);
    W25qxx_WriteBlock(gImage_first,1,0,40960);
    W25qxx_EraseBlock(2);
    W25qxx_WriteBlock(gImage_second,2,0,40960);
    W25qxx_EraseBlock(3);
    W25qxx_WriteBlock(gImage_third,3,0,40960);
    W25qxx_EraseBlock(4);
    W25qxx_WriteBlock(gImage_1,4,0,40960);
    W25qxx_EraseBlock(5);
    W25qxx_WriteBlock(gImage_2,5,0,40960);
    W25qxx_EraseBlock(6);
    W25qxx_WriteBlock(gImage_3,6,0,40960);
    W25qxx_EraseBlock(7);
    W25qxx_WriteBlock(gImage_4,7,0,40960);
    W25qxx_EraseBlock(8);
    W25qxx_WriteBlock(gImage_5,8,0,40960);*/
}





