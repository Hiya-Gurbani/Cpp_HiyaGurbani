#include "rescue.h"

int main() {
    logInfo("Rescue tool starting...");

    if (checkDisk()) {
        logInfo("Disk found!");
    } else {
        logError("Disk not found!");
    }

    logInfo("Rescue tool finished.");
    return 0;
}
