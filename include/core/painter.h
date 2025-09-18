/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-18 15:18:15
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
#ifndef __PAINTER_H__
#define __PAINTER_H__

#include "core/circle.h"
#include "core/line.h"
#include "core/macros.h"
#include "core/point.h"
#include "core/rectangle.h"
#include "core/shape.h"
#include "core/triangle.h"
#include "xlib/common.h"

namespace Aurson {
    class Painter {
    public:
        Painter(const XlibShapeType &shape_type, ContentCallback *ccbk)
            : shape_(nullptr),
              ccbk_(ccbk) {
            create_shape(shape_type);
        }
        ~Painter() = default;
        auto paint() -> XlibRetcode {
            CHECK_TRUE(shape_, XLIB_RETCODE_SHAPE_INVALID);
            CHECK_TRUE(ccbk_, XLIB_RETCODE_CALLBACK_INVALID);
            ccbk_(shape_->draw().c_str());

            return XLIB_RETCODE_OK;
        }

    private:
        void create_shape(const XlibShapeType &shape_type) {
            switch (shape_type) {
            case XlibShapeType::XLIB_POINT:
                shape_ = new Point();
                break;

            case XlibShapeType::XLIB_LINE:
                shape_ = new Line();
                break;

            case XlibShapeType::XLIB_TRIANGLE:
                shape_ = new Triangle();
                break;

            case XlibShapeType::XLIB_RECTANGLE:
                shape_ = new Rectangle();
                break;

            case XlibShapeType::XLIB_CIRCLE:
                shape_ = new Circle();
                break;

            default:
                shape_ = nullptr;
                break;
            }
        }

    private:
        Shape *shape_;
        ContentCallback *ccbk_;
    };
} // namespace Aurson

#endif // __PAINTER_H__