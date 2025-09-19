/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-19 15:54:15
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
#include "core/macros.h"
#include "core/updater_impl.h"
#include "xlib/updater_factory.h"
#include "xlib/updater.h"
#include <iostream>

static void print_version_info() {
    std::cout << "             ___ __         " << std::endl;
    std::cout << "      __ __ / (_) /         " << std::endl;
    std::cout << "      \\ \\ // / / _ \\     " << std::endl;
    std::cout << "     /_\\_\\/_/_/_.__/      " << std::endl;
    std::cout << "────────────────────────────" << std::endl;
    std::cout << "[AppName   ] : " << APP_NAME << std::endl;
    std::cout << "[BuildDate ] : " << BUILD_DATE << std::endl;
    std::cout << "[AppVersion] : " << APP_VERSION << std::endl;
    std::cout << "[CommitHash] : " << GIT_HASH << std::endl;
    std::cout << "─────────────────────────────" << std::endl;
}

static auto init(Updater *self, ProgressCallback *callback) -> RetCode {
    CHECK_TRUE(self, UPDATER_INVALID);
    CHECK_TRUE(self->private_, UPDATER_INVALID);
    return static_cast<Xlib::UpdaterImpl *>(self->private_)->init(callback);
}

static auto get_module_info(Updater *self, ModuleInfo *_module_info) -> RetCode {
    CHECK_TRUE(self, UPDATER_INVALID);
    CHECK_TRUE(self->private_, UPDATER_INVALID);
    return static_cast<Xlib::UpdaterImpl *>(self->private_)->get_module_info(_module_info);
}

static auto update(Updater *self, const char *package) -> RetCode {
    CHECK_TRUE(self, UPDATER_INVALID);
    CHECK_TRUE(self->private_, UPDATER_INVALID);
    return static_cast<Xlib::UpdaterImpl *>(self->private_)->update(package);
}

static auto deinit(Updater *self) -> RetCode {
    CHECK_TRUE(self, UPDATER_INVALID);
    CHECK_TRUE(self->private_, UPDATER_INVALID);
    return static_cast<Xlib::UpdaterImpl *>(self->private_)->deinit();
}

XLIB_API auto updater_create(ModuleType module_type) -> Updater * {
    // clang-format off
    return new Updater({
        .init            = init,
        .get_module_info = get_module_info,
        .update          = update,
        .deinit          = deinit,
        .private_        = new Xlib::UpdaterImpl(module_type)
    });
    // clang-format on
}

XLIB_API void updater_destroy(Updater *updater) {
    if (!updater) {
        return;
    }
    if (updater->private_) {
        delete static_cast<Xlib::UpdaterImpl *>(updater->private_);
    }
    delete updater;
}
