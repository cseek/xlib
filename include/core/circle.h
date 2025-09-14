/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:11:55
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "core/shape.h"

namespace Aurson {
    class Circle : public Shape {
    public:
        ~Circle() override = default;
        auto draw() -> std::string override {
            return "     ...     \n"
                   "   .     .   \n"
                   "  .       .  \n"
                   "  .       .  \n"
                   "   .     .   \n"
                   "     ...     ";
        }
    };
} // namespace Aurson
#endif // __CIRCLE_H__