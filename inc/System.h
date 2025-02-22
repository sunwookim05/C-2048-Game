#include "main.h"

#ifndef __SYSTEM_H
#define __SYSTEM_H

struct __stdin_t;

#pragma pack(push, 1)
/**
 * The {@code System} class contains several useful class fields
 * and methods. It cannot be instantiated.
 *
 * Among the facilities provided by the {@code System} class
 * are standard input, standard output, and error output streams;
 * access to externally defined properties and environment
 * variables; a means of loading files and libraries; and a utility
 * method for quickly copying a portion of an array.
 *
 * @since   1.0
 */
typedef struct SYSTEM{
    struct stdout_t{
        /**
        * @brief System out print function
        * @param format
        * @return void
        */
        void (*printf)(const String, ...);
        /** 
        * @brief System out println function
        * @param format
        * @return void
        */
        void (*println)(const String, ...);
    }out;
    struct __stdin_t{
        int32_t (*read)();
    } in;
}SYSTEM;
#pragma pack(pop)

#endif