#include "baseEntity.h"

bool BaseEntity::overlaps(BaseEntity* other) {
    return !(
        other->x            >= x + w ||
        other->x + other->w <= x     ||
        other->y            >= y + h ||
        other->y + other->h <= y
    );
}
