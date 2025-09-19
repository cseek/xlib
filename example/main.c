/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-19 15:55:27
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
#include "xlib/updater_factory.h"
#include <stdio.h>

void progress_callback(float progress) {}

int main() {
    ModuleInfo info;
    Updater *updater = NULL;

    updater = updater_create(MODULE_TYPE_CAMERA);
    updater->init(updater, progress_callback);
    updater->get_module_info(updater, &info);
    updater->update(updater, "/tmp/package/example.zip");
    updater->deinit(updater);
    updater_destroy(updater);
    updater = NULL;

    return 0;
}