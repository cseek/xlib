/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 15:26:03
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-18 15:11:22
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#include "xlib/xlib_api.h"
#include "core/macros.h"
#include "core/painter.h"
#include "xlib/common.h"
#include <iostream>

static void print_version_info() {
    std::cout << "             ___ __         " << std::endl;
    std::cout << "      __ __ / (_) /         " << std::endl;
    std::cout << "      \\ \\ // / / _ \\     " << std::endl;
    std::cout << "     /_\\_\\/_/_/_.__/      " << std::endl;
    std::cout << "────────────────────────────" << std::endl;
    std::cout << "[AppName   ] : " << APP_NAME << std::endl;
    std::cout << "[BuildDate ] : " << BUILD_DATE << std::endl;
    std::cout << "[AppVersion] : " << APP_VERSION << std::endl;
    std::cout << "[CommitHash] : " << GIT_HASH << std::endl;
    std::cout << "─────────────────────────────" << std::endl;
}

static auto init_shape(XlibShapeType type, ContentCallback *ccbk) -> XlibHandle {
    return static_cast<XlibHandle>(new Aurson::Painter(type, ccbk));
}

static auto show_shape(XlibHandle *handle) -> XlibRetcode {
    CHECK_TRUE(handle && *handle, XLIB_RETCODE_HANDLE_INVALID);
    return static_cast<Aurson::Painter *>(*handle)->paint();
}

static auto deinit_shape(XlibHandle *handle) -> XlibRetcode {
    CHECK_TRUE(handle && *handle, XLIB_RETCODE_HANDLE_INVALID);
    delete static_cast<Aurson::Painter *>(*handle);
    *handle = nullptr;
    return XLIB_RETCODE_OK;
}

XLIB_API auto get_xlib_interface() -> XlibInterface * {
    print_version_info();
    // clang-format off
    return new XlibInterface({
        .init_shape   = init_shape,
        .show_shape   = show_shape,
        .deinit_shape = deinit_shape
    });
    // clang-format on
}

XLIB_API void drop_xlib_interface(XlibInterface **interface) {
    if (interface && *interface) {
        delete *interface;
        *interface = nullptr;
    }
}
