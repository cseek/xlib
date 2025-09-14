/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 15:26:03
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:23:33
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#include "xlib/xlib_api.h"
#include "core/circle.h"
#include "core/context.h"
#include "core/line.h"
#include "core/macros.h"
#include "core/point.h"
#include "core/rectangle.h"
#include "core/triangle.h"
#include "xlib/common.h"
#include <iostream>

static void print_version_info() {
    std::cout << "             ___ __         "   << std::endl;
    std::cout << "      __ __ / (_) /         "   << std::endl;
    std::cout << "      \\ \\ // / / _ \\     "   << std::endl;
    std::cout << "     /_\\_\\/_/_/_.__/      "   << std::endl;
    std::cout << "────────────────────────────"   << std::endl;
    std::cout << "[AppName   ] : " << APP_NAME    << std::endl;
    std::cout << "[BuildDate ] : " << BUILD_DATE  << std::endl;
    std::cout << "[AppVersion] : " << APP_VERSION << std::endl;
    std::cout << "[CommitHash] : " << GIT_HASH    << std::endl;
    std::cout << "─────────────────────────────"  << std::endl;
}

static void create_shape(Aurson::Context *context) {
    switch (context->shape_type) {
    case XlibShapeType::XLIB_POINT:
        context->shape = new Aurson::Point();
        break;

    case XlibShapeType::XLIB_LINE:
        context->shape = new Aurson::Line();
        break;

    case XlibShapeType::XLIB_TRIANGLE:
        context->shape = new Aurson::Triangle();
        break;

    case XlibShapeType::XLIB_RECTANGLE:
        context->shape = new Aurson::Rectangle();
        break;

    case XlibShapeType::XLIB_CIRCLE:
        context->shape = new Aurson::Circle();
        break;

    default:
        context->shape = nullptr;
        break;
    }
}

static auto init_shape(XlibShapeType type, ContentCallback *ccbk) -> XlibHandle * {
    auto context = new Aurson::Context();
    if (!context) {
        return nullptr;
    }
    context->shape_type = type;
    context->ccbk = ccbk;
    create_shape(context);

    return static_cast<XlibHandle *>(context);
}

static auto show_shape(XlibHandle *handle) -> XlibRetcode {
    auto context = static_cast<Aurson::Context *>(handle);
    CHECK_TRUE(context, XLIB_RTCODE_HANDLE_INVALID);
    CHECK_TRUE(context->shape, XLIB_RTCODE_SHAPE_INVALID);
    if (context->ccbk) {
        context->ccbk(context->shape->draw().c_str());
        return XlibRetcode::XLIB_RTCODE_OK;
    }
    return XlibRetcode::XLIB_RTCODE_FAIL;
}

static auto deinit_shape(XlibHandle *handle) -> XlibRetcode {
    auto context = static_cast<Aurson::Context *>(handle);
    if (context) {
        delete context;
        context = nullptr;
    }

    return XLIB_RTCODE_OK;
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

XLIB_API void drop_xlib_interface(XlibInterface *object) {
    if (object) {
        delete object;
        object = nullptr;
    }
}
