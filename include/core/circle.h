/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-18 15:18:00
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