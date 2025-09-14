/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 15:25:39
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 16:53:37
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __XLIB_API_H__
#define __XLIB_API_H__
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#include "common.h"

XLIB_API auto get_xlib_interface() -> XlibInterface *;
XLIB_API void drop_xlib_interface(XlibInterface *interface);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __XLIB_API_H__