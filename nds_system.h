
#ifndef _NDS_SYSTEM_H_
#define _NDS_SYSTEM_H_

#include "common/system_descriptor.h"
#include "arm/arm_cpu.h"
#include "nds_mmu.h"
#include "nds_cartridge.h"

/*typedef struct {
    char* bios7;
    char* bios9;
    char* firmware;
    bool hle;
} nds_config;*/

typedef struct {
    arm_cpu* arm7;
    arm_cpu* arm9;
    nds_mmu* mmu;
    nds_cartridge* cart;
} nds_system;

extern system_descriptor nds_descriptor;

void nds_init(nds_system* system);
nds_system* nds_make(nds_cartridge* cart);
void nds_free(nds_system* system);
void nds_frame(nds_system* system);

#endif
