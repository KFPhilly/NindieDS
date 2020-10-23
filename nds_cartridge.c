#include "common/log.h"
#include "nds_cartridge.h"

void nds_cart_get_type(nds_cartridge* cart)
{
    // We assume for now that ROM is not encrypted.
    cart->type = CART_DUMPED;
}

nds_cartridge* nds_cart_open(char* rom_path)
{
    // TODO: sanitize cartridge header, decrypt
    nds_cartridge* cart = malloc(sizeof(nds_cartridge));
    FILE* rom_handle = fopen(rom_path, "rb");

    if (rom_handle == NULL) {
        LOG(LOG_ERROR, "fopen: %s", rom_path);
        free(cart);
        return NULL;
    }
    
    if (fread(&cart->header, sizeof(nds_header), 1, rom_handle) != 1) {
        LOG(LOG_ERROR, "fread: %s", rom_path);
        fclose(rom_handle);
        free(cart);
        return NULL;
    }
    
    cart->rom_handle = rom_handle;
    nds_cart_get_type(cart);
    
    return cart;
}

void nds_cart_close(nds_cartridge* cart)
{
    fclose(cart->rom_handle);
    free(cart);
}
