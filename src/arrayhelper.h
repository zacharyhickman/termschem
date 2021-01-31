#ifndef __ARRAYHELPER_H__
#define __ARRAYHELPER_H__

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * @file arrayhelper.h
 * @brief A set of macros that help manage arrays.
 *
 * @author Zachary T. Hickman (zhickman)
 * @bug No known bugs.
 */

#define ARRAY_SIZE(array) \
	(sizeof(array) / sizeof(array[0]))

#ifdef __cplusplus
}
#endif

#endif
