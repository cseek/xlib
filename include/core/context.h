/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 15:26:03
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:12:10
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __CONTEXT_H__
#define __CONTEXT_H__

#include "xlib/common.h"
#include "core/shape.h"

namespace Aurson {
    struct Context {
        XlibShapeType shape_type;
        ContentCallback *ccbk;
        Shape *shape;
    };
} // namespace Aurson

#endif // __CONTEXT_H__