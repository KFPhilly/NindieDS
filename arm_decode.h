#ifndef _ARM_DECODE_H_
#define _ARM_DECODE_H_

#include "arm_global.h"

typedef enum {
    ARM_1,
    ARM_2,
    ARM_3,
    ARM_4,
    ARM_5,
    ARM_6,
    ARM_7,
    ARM_8,
    ARM_9,
    ARM_10,
    ARM_11,
    ARM_12,
    ARM_13,
    ARM_14,
    ARM_15,
    ARM_16,
    ARM_ERROR
} arm_instruction;

typedef enum {
    THUMB_1,
    THUMB_2,
    THUMB_3,
    THUMB_4,
    THUMB_5,
    THUMB_6,
    THUMB_7,
    THUMB_8,
    THUMB_9,
    THUMB_10,
    THUMB_11,
    THUMB_12,
    THUMB_13,
    THUMB_14,
    THUMB_15,
    THUMB_16,
    THUMB_17,
    THUMB_18,
    THUMB_19,
    THUMB_ERROR
} thumb_instruction;

arm_instruction arm_decode(u32 instruction);
thumb_instruction arm_decode_thumb(u16 instruction);

#endif