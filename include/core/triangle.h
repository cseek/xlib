/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:30:12
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:12:27
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "core/shape.h"

namespace Aurson {
    class Triangle : public Shape {
    public:
        ~Triangle() override = default;
        auto draw() -> std::string override {
            return "     /\\     \n"
                   "    /  \\    \n"
                   "   /    \\   \n"
                   "  /      \\  \n"
                   " /________\\ ";
        }
    };
} // namespace Aurson
#endif // __TRIANGLE_H__