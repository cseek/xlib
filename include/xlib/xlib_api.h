/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 17:33:37
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-18 16:31:22
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
#ifndef __XLIB_API_H__
#define __XLIB_API_H__

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

XLIB_API XlibInterface * get_xlib_interface();
XLIB_API void drop_xlib_interface(XlibInterface **interface);

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // __XLIB_API_H__