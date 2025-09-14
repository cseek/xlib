/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:24:53
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 17:28:02
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>

namespace Aurson {
    class Shape {
    public:
        virtual ~Shape() = default;
        virtual auto draw() -> std::string = 0;
    };
} // namespace Aurson
#endif // __SHAPE_H__