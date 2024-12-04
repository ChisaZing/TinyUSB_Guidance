#include "user_entrance.h"
#include <tusb.h>
#include <class/cdc/cdc_device.h>
#include <class/hid/hid_device.h>

tusb_desc_device_t const tusb_desc_device = {
        .bLength =                      0x12,
        .bDescriptorType =              TUSB_DESC_DEVICE,
        .bcdUSB =                       0x0200,
        .bDeviceClass =                 0xEF,
        .bDeviceSubClass =              0x02,
        .bDeviceProtocol =              0x01,
        .bMaxPacketSize0 =              64U,
        .idVendor =                     0x0483,
        .idProduct =                    0x0001,
        .bcdDevice =                    0x0001,
        .iManufacturer =                0x01,
        .iProduct =                     0x02,
        .iSerialNumber =                0x03,
        .bNumConfigurations =           0x01,
};

uint8_t const*  tud_descriptor_device_cb()
{
    return (uint8_t const*)&tusb_desc_device;
}

uint8_t const hid_report_desc[] =
        {
                0x05, 0x01,        // Usage Page (Generic Desktop)
                0x09, 0x06,        // Usage (Keyboard)
                0xA1, 0x01,        // Collection (Application)

                // 修饰键（如 Ctrl、Shift 等）
                0x05, 0x07,        // Usage Page (Keyboard/Keypad)
                0x19, 0xE0,        // Usage Minimum (Left Control)
                0x29, 0xE7,        // Usage Maximum (Right GUI)
                0x15, 0x00,        // Logical Minimum (0)
                0x25, 0x01,        // Logical Maximum (1)
                0x75, 0x01,        // Report Size (1)
                0x95, 0x08,        // Report Count (8)
                0x81, 0x02,        // Input (Data, Var, Abs)

                // 保留字节
                0x95, 0x01,        // Report Count (1)
                0x75, 0x08,        // Report Size (8)
                0x81, 0x01,        // Input (Cnst, Ary, Abs)

                // 按键数组
                0x95, 0x06,        // Report Count (6)
                0x75, 0x08,        // Report Size (8)
                0x15, 0x00,        // Logical Minimum (0)
                0x25, 0x65,        // Logical Maximum (101)
                0x05, 0x07,        // Usage Page (Keyboard/Keypad)
                0x19, 0x00,        // Usage Minimum (Reserved)
                0x29, 0x65,        // Usage Maximum (Keyboard Application)
                0x81, 0x00,        // Input (Data, Ary, Abs)

                0xC0               // End Collection
        };

#define CONFIG_TOTAL_LEN (TUD_CONFIG_DESC_LEN+TUD_CDC_DESC_LEN+TUD_HID_DESC_LEN)
uint8_t const desc_configuration[] = {
        // 配置描述符
        TUD_CONFIG_DESCRIPTOR(1, 3, 0, CONFIG_TOTAL_LEN, 0, 100),
        // CDC 接口描述符
        TUD_CDC_DESCRIPTOR(0, 3, 0x81, 8, 0x02, 0x82, 64),
        // HID接口描述符
        TUD_HID_DESCRIPTOR(2, 3, HID_ITF_PROTOCOL_KEYBOARD, sizeof(hid_report_desc), 0x84, 8, 10)
};
uint8_t const* tud_descriptor_configuration_cb(uint8_t index)
{
    return desc_configuration;
}

uint8_t const* tud_hid_descriptor_report_cb(uint8_t itf){
    return hid_report_desc;
}

void tud_hid_set_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
    //处理接收到的报文
}

uint16_t tud_hid_get_report_cb(uint8_t instance, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
{
    return 0;
}

uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
    return NULL;
}


void task_entry()
{
    tusb_init();
    while(true){
        tud_task();
    }
}
