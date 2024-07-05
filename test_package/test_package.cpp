#include <khepri/application/console_logger.hpp>
#include <khepri/log/log.hpp>
#include <khepri/version.hpp>
#include <openglyph/version.hpp>

#include <iostream>

int main()
{
    khepri::application::ConsoleLogger logger;
    khepri::log::Logger log("TestLogger");
    log.info("OpenGlyph version: {}", khepri::to_string(openglyph::version()));
    log.info("Khepri version: {}", khepri::to_string(khepri::version()));
    return 0;
}
