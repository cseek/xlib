/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:26:48
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:12:18
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __POINT_H__
#define __POINT_H__

#include "core/shape.h"

namespace Aurson {
    class Point : public Shape {
    public:
        ~Point() override = default;
        auto draw() -> std::string override {
            return ".";
        }
    };
} // namespace Aurson
#endif // __POINT_H__