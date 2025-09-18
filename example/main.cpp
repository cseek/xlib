/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-18 18:33:57
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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
    if (XLIB_RETCODE_OK != interface->show_shape(handle)) {
        std::cerr << "Failed to show shape" << std::endl;
        return;
    }
    interface->deinit_shape(&handle);
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

    drop_xlib_interface(&interface);

    return 0;
}