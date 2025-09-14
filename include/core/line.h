/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:28:55
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:12:13
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __LINE_H__
#define __LINE_H__

#include "core/shape.h"

namespace Aurson {
    class Line : public Shape {
    public:
        ~Line() override = default;
        auto draw() -> std::string override {
            return "──────────────────";
        }
    };
} // namespace Aurson

#endif // __LINE_H__