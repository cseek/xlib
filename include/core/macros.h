/*
 * @Author: aurson jassimxiong@gmail.com
 * @Date: 2025-09-14 15:26:03
 * @LastEditors: aurson jassimxiong@gmail.com
 * @LastEditTime: 2025-09-14 17:24:24
 * @Description: 
 * Copyright (c) 2025 by Aurson, All Rights Reserved. 
 */
#ifndef __MACROS_H__
#define __MACROS_H__

/**
 * @description: 如果 condition 不满足，则 return_value
 */
#define CHECK_TRUE(condition, return_value) \
    do                                      \
    {                                       \
        if (!(condition))                   \
        {                                   \
            return return_value;            \
        }                                   \
    } while (0)

#endif // __MACROS_H__