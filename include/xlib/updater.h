/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-19 15:42:08
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
#ifndef __UPDATER_H__
#define __UPDATER_H__

#include <stdint.h>

#define XLIB_API __attribute__((visibility("default")))

typedef void Private;
typedef void(ProgressCallback)(float progress);
typedef struct Updater Updater;

typedef enum {
    OK = 0,               // Success
    FAIL = -1,            // General failure
    UPDATER_INVALID = -2, // Invalid Updater instance
    MODULE_INVALID = -3   // Module invalid
} RetCode;

typedef enum {
    MODULE_TYPE_CAMERA = 0,
    MODULE_TYPE_LIDAR
} ModuleType;

typedef struct {
    char version[100];
} ModuleInfo;

struct Updater {
    RetCode (*init)(Updater *self, ProgressCallback *callback);
    RetCode (*get_module_info)(Updater *self, ModuleInfo *_module_info);
    RetCode (*update)(Updater *self, const char *package);
    RetCode (*deinit)(Updater *self);
    Private  *private_;
};
#endif // __UPDATER_H__