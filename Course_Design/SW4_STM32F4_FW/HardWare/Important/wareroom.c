//
// Created by lucas on 2022/4/15.
//
#include "wareroom.h"
#include "w25qxx.h"

// 把图像读取到缓冲数组
unsigned char flash_buffer[40960];

unsigned char *ware_room_read(uint8_t num)
{
    W25qxx_ReadBlock(flash_buffer, num, 0, 40960);
    return flash_buffer;
}

// 把图像写入flash
void ware_room_write()
{
/*
    W25qxx_EraseBlock(1);
    W25qxx_WriteBlock(gImage_first,1,0,40960);
*/
}





