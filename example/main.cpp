/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-12 19:19:25
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:17:58
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#include "xlib/xlib_api.h"
#include <iostream>

void show_shape(XlibInterface *interface, XlibShapeType type) {
    XlibHandle *handle = interface->init_shape(
        type,
        [](const char *content) {
            std::cout << content << std::endl;
        });
    if (!handle) {
        std::cerr << "Failed to init shape, ret: " << std::endl;
        return;
    }
    if (XLIB_RTCODE_OK != interface->show_shape(handle)) {
        std::cerr << "Failed to show shape" << std::endl;
        return;
    }
    interface->deinit_shape(handle);
}

int main() {
    XlibInterface *interface = get_xlib_interface();
    if (!interface) {
        std::cerr << "Failed to get xlib interface" << std::endl;
        return -1;
    }

    show_shape(interface, XLIB_POINT);
    show_shape(interface, XLIB_LINE);
    show_shape(interface, XLIB_TRIANGLE);
    show_shape(interface, XLIB_RECTANGLE);
    show_shape(interface, XLIB_CIRCLE);

    drop_xlib_interface(interface);

    return 0;
}