#pragma once

namespace openglyph {

struct Map
{
    struct Header
    {
        // Map format version
        std::uint32_t version{0};
    };

    struct Skydome
    {
        std::string name;
        float       scale;
        float       tilt;
        float       z_angle;
    };

    struct Environment
    {
        std::string            name;
        std::array<Skydome, 2> skydomes;
    };

    Header header;

    std::vector<Environment> environments;
    std::uint32_t            active_environment;
};

} // namespace openglyph
