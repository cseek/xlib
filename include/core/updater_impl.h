/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-19 15:41:00
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
#ifndef __UPDATER_IMPL_H__
#define __UPDATER_IMPL_H__

#include "core/camera.h"
#include "core/lidar.h"
#include "core/module.h"
#include "xlib/updater.h"
#include <memory>

namespace Xlib {
    class UpdaterImpl {
    public:
        UpdaterImpl(ModuleType module_type) {
            switch (module_type) {
            case MODULE_TYPE_CAMERA:
                module_ = std::make_unique<Camera>();
                break;

            case MODULE_TYPE_LIDAR:
                module_ = std::make_unique<Lidar>();
                break;

            default:
                break;
            }
        }
        ~UpdaterImpl() = default;
        auto init(ProgressCallback *callback) -> RetCode {
            return OK;
        }
        auto get_module_info(ModuleInfo *_module_info) -> RetCode {
            return OK;
        }
        auto update(const char *package) -> RetCode {
            return OK;
        }
        auto deinit() -> RetCode {
            return OK;
        }

    private:
        std::unique_ptr<Module> module_;
    };
} // namespace Xlib
#endif // __UPDATER_IMPL_H__