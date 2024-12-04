#ifndef _TUSB_CONFIG_H_
#define _TUSB_CONFIG_H_

#define CFG_TUSB_MCU OPT_MCU_STM32F1
#define CFG_TUSB_RHPORT0_MODE (OPT_MODE_DEVICE | OPT_MODE_FULL_SPEED)
#define CFG_TUD_ENDPOINT0_SIZE 64

// 根据需求启用支持的类
#define CFG_TUD_ENABLED          1                 //是否启用设备栈
#define CFG_TUD_CDC              1                 //是否启用CDC类
#define CFG_TUD_MSC              0                 //是否启用MSC类
#define CFG_TUD_HID              1                 //是否启用HID类
#define CFG_TUD_MIDI             0                 //是否启用MIDI类
#define CFG_TUD_VENDOR           0                 //是否启用VENDOR类

//新增宏定义
#define CFG_TUD_CDC_RX_BUFSIZE 512              // CDC 接收端点缓冲区大小
#define CFG_TUD_CDC_TX_BUFSIZE 512              // CDC 发送端点缓冲区大小
#define CFG_TUD_HID_EP_BUFSIZE  64              // HID 端点缓冲区大小

#endif