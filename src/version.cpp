#include <khepri/version_info.hpp>

namespace openglyph {

namespace {
const ::khepri::VersionInfo build_version_info{OPENGLYPH_VERSION_MAJOR, OPENGLYPH_VERSION_MINOR,
                                               OPENGLYPH_VERSION_PATCH, OPENGLYPH_VERSION_STRING,
                                               OPENGLYPH_VERSION_CLEAN, OPENGLYPH_VERSION_COMMIT};
}

const ::khepri::VersionInfo& version() noexcept
{
    return build_version_info;
}

} // namespace openglyph
