#include "CaptureImage.h"
#include "CaptureVideo.h"
#include <iostream>

int main() {
    unsigned int choice;
    std::cout << "Options:\n1. Capture Front Image\n2. Capture Back Image\n"
    "3. Capture Video\n4. Capture Video for Specific Duration\n5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
        captureImage(true);
        break;

        case 2:
        captureImage(false);
        break;

        case 3:
        captureVideo();
        break;

        case 4:
        {
            int time = 0;
            std::cout << "Enter duration of recording in seconds: ";
            std::cin >> time;

            captureVideo(time);
            break;
        }

        default:
        std::cout << "Invalid Choice!\n";
    }

    return 0;
}
