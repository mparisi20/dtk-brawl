#include <gf/gf_archive.h>
#include <types.h>

void* gfArchiveFileHeader::getDataChunk() {
    u32 offset = 0;
    switch (unk4) {
        case 0x101: {
            offset = 0x40;
            break;
        }
        case 0x100: {
            offset = 0x20;
            break;
        }
        default: {
            break;
        }
    }
    return reinterpret_cast<u8*>(this) + offset;
}
