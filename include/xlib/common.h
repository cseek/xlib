/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 15:26:03
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 18:07:18
 * @Description:
 * Copyright (c) 2025 by Aurson, All Rights Reserved.
 */
#ifndef __COMMON_H__
#define __COMMON_H__
#ifdef __GNUC__
#define PACKED __attribute__((packed))
#else
#define PACKED
#endif

#define XLIB_API __attribute__((visibility("default")))

typedef void XlibHandle;
typedef void(ContentCallback)(const char *content);

typedef enum {
    XLIB_RTCODE_OK = 0,
    XLIB_RTCODE_FAIL,
    XLIB_RTCODE_HANDLE_INVALID,
    XLIB_RTCODE_SHAPE_INVALID
} XlibRetcode;

typedef enum {
    XLIB_POINT = 0,
    XLIB_LINE,
    XLIB_TRIANGLE,
    XLIB_RECTANGLE,
    XLIB_CIRCLE,
} XlibShapeType;

typedef struct {
    XlibHandle *(*init_shape)(XlibShapeType type, ContentCallback *ccbk);
    XlibRetcode (*show_shape)(XlibHandle *handle);
    XlibRetcode (*deinit_shape)(XlibHandle *handle);
} XlibInterface;
#endif // __COMMON_H__