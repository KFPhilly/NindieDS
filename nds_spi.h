#ifndef _NDS_SPI_H_
#define _NDS_SPI_H_

#include "common/types.h"
#include "nds_firmware.h"

typedef enum {
    BAUD_4MHZ = 0,
    BAUD_2MHZ = 1,
    BAUD_1MHZ = 2,
    BAUD_512KHZ = 3
} nds_baud_rate;

typedef enum {
    SPI_POWERMAN = 0,
    SPI_FIRMWARE = 1,
    SPI_TOUCHSCR = 2,
    SPI_RESERVED = 3
} nds_spi_device;

typedef struct {
    // SPICNT
    nds_spi_device device_old;
    nds_spi_device device;
    nds_baud_rate baud_rate;
    bool busy;
    bool bugged;
    bool ireq;
    bool enable;
    bool cs_hold;

    // Slave devices
    nds_firmware firmware;
} nds_spi_bus;

void nds_spi_init(nds_spi_bus* spi_bus);
void nds_spi_update_cs(nds_spi_bus* spi_bus);
u8 nds_spi_read(nds_spi_bus* spi_bus);
void nds_spi_write(nds_spi_bus* spi_bus, u8 value);

#endif
