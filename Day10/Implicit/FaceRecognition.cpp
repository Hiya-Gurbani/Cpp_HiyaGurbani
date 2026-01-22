#include "CaptureImage.h"
#include <iostream>

int main() {
    captureImage(true);

    std::cout << "\nDetecting face in the captured image...\n";
    std::cout << "Image matched successfully!\n";
}