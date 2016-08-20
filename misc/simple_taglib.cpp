#include <iostream>

#include <taglib/fileref.h>

int main() {
    TagLib::FileRef track("Walton-Bulldoze.mp3");

    TagLib::String artist = track.tag()->artist();

    auto trtag = track.tag();
    std::cout << "hit men ikke lenger" << std::endl;
    auto title = trtag->title();

    std::cout << "hei" << std::endl;
    std::cout << title << " " << artist << std::endl;

    return 0;
}
