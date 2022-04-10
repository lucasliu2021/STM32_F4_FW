# 更新日志
---
2022-04-10

发现串口中断无法进入，标志位没有变化。

---
## 2022-04-09

1. 添加图库照片
2. 添加蓝牙游戏
3. 添加音乐
4. 添加电子书
5. 添加设置(目前仅有蜂鸣器开关)
6. 修复调光bug
7. 修复按键后抖
8. 完善信号发生器添加选择可在后台继续发生波形，并且可使用本机示波器测量。
9. 添加四种基本波形、分别是正弦波、矩形波、三角波、脉冲波
10. 波形函数并未完善，需要通过傅里叶变换合成。
11. 所有功能基本完工。对于手机app配套开发，由于没有时间，不在研究
12. 后续仅进行小BUG修复以及功能完善。不再进行二次开发。
    Memory region         Used Size  Region Size  %age Used
    RAM:        9936 B       128 KB      7.58%
    CCMRAM:          0 GB        64 KB      0.00%
    FLASH:      456928 B       512 KB     87.15%

---
## 2022-04-08

1. 大改动、精简main文件（只保留头文件以及main_task函数调用）
2. 初始化和回调函数单独源文件
3. 更改PWM调光频率和占空比
4. 添加DSP和串口
5. printf等函数重定向
6. 蓝牙功能调用增加模块连接状态识别
7. 优化import、代码清理、优化目录结构
8. 压缩绘图函数
9. 添加快速傅里叶变换
10. 删除typedefine宏定义
11. 直接更改HAL_GPIO_EXTI_IRQHandler，按键消抖。
    Memory region         Used Size  Region Size  %age Used
    RAM:        9832 B       128 KB      7.50%
    CCMRAM:          0 GB        64 KB      0.00%
    FLASH:      209624 B       512 KB     39.98%

---
## 2022-03-27

Memory region         Used Size  Region Size  %age Used
RAM:        4280 B       128 KB      3.27%
CCMRAM:          0 GB        64 KB      0.00%
FLASH:      318288 B       512 KB     60.71%

---
## 2022-03-26
1. 使用switch结构替换菜单控制

2. 优化APP图标显示方式，降低FLASH占用

3. 添加秒表功能

4. 添加亮度控制（使用1khz 定时器9）

5. 添加图库

6. 添加蓝牙连接
   Memory region         Used Size  Region Size  %age Used
   RAM:        4288 B       128 KB      3.27%
   CCMRAM:          0 GB        64 KB      0.00%
   FLASH:      318240 B       512 KB     60.70%
   
---




