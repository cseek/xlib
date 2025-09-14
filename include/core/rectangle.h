/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:32:12
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:12:22
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "core/shape.h"

namespace Aurson {
    class Rectangle : public Shape {
    public:
        ~Rectangle() override = default;
        auto draw() -> std::string override {
            return "┌──────────────┐\n"
                   "│              │\n"
                   "│              │\n"
                   "└──────────────┘";
        }
    };
} // namespace Aurson

#endif // __RECTANGLE_H__