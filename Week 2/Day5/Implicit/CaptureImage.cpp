#include "CaptureImage.h"
#include <iostream>

void captureImage(bool isFront) {
    if (isFront)
    {
        std::cout << "Front Image is being captured!\n";            
    }
    else
    {
        std::cout << "Back Image is being captured!\n";            
    }
}
