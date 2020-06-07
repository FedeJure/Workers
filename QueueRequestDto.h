#ifndef QUEUE_REQUEST_H_
#define QUEUE_REQUEST_H_
#include <stdint.h>
#include "./Material.h"

struct QueueRequestDto {
    Material type;
    uint32_t count;

    QueueRequestDto(Material providedType, uint32_t providedCount) {
        type = providedType;
        count = providedCount;
    }
};

#endif
