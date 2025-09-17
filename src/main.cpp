// stl
#include <chrono>

// zpp-lib
#include "zpp_include/thread.hpp"
#include "zpp_include/this_thread.hpp"
#include "zpp_include/digital_out.hpp"

void blink() {
    zpp_lib::DigitalOut led(zpp_lib::DigitalOut::PinName::LED0);
    using namespace std::literals;
    static std::chrono::milliseconds blinkInterval = 1000ms;

    while (true) {
        led = !led;
        zpp_lib::ThisThread::sleep_for(blinkInterval);
    }
}

int main(void) {
    zpp_lib::Thread thread;
    auto res = thread.start(blink);
    if (! res) {
        return -1;
    }
    res = thread.join();
    if (! res) {
        return -1;
    }
    return 0;
}
