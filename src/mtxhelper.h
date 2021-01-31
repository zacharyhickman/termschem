#ifndef __MTXHELPER_H__
#define __MTXHELPER_H__

#ifdef __cplusplus
extern "C" {
#endif

/** 
 * @file mtxhelper.h
 * @brief A set of macros that help create, init, and control mutexes with variables.
 *
 * @author Zachary T. Hickman (zhickman)
 * @bug No known bugs.
 */

#include <pthread.h>

#define DECLARE_MUTEX_EXTERN(type, name) \
	extern type name; 

#define DECLARE_MUTEX_VAR(type, name) \
	volatile type name; \
	pthread_mutex_t name_mutex;

#define INIT_VAR_MUTEX(name) \
	pthread_mutex_init(&name_mutex, NULL);

#define LOCK_VAR_MUTEX(name) \
	pthread_mutex_lock(&name_mutex);

#define UNLOCK_VAR_MUTEX(name) \
	pthread_mutex_unlock(&name_mutex);

#define SET_MUTEX_VAR(name, value) \
	LOCK_VAR_MUTEX(name) \
	name = value; \
	UNLOCK_VAR_MUTEX(name)

#ifdef __cplusplus
}
#endif

#endif
