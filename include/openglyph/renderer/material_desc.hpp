#pragma once

#include <khepri/renderer/material_desc.hpp>

#include <variant>

namespace openglyph::renderer {

/**
 * Description of a material
 */
struct MaterialDesc
{
    /// Value of a material shader property
    using PropertyValue = std::variant<std::int32_t, float, khepri::Vector2f, khepri::Vector3f,
                                       khepri::Vector4f, khepri::Matrixf, std::string>;

    using AlphaBlendMode = khepri::renderer::MaterialDesc::AlphaBlendMode;

    /// Description of a material shader property
    struct Property
    {
        /// Property name
        std::string name;

        /// Default value of the property if none is provided by the mesh instance
        PropertyValue default_value;
    };

    /// Name of the material
    std::string name;

    /// Type of alpha blending to use when rendering with this material
    AlphaBlendMode alpha_blend_mode{AlphaBlendMode::none};

    /// Enable depth-buffer test when rendering this material
    bool depth_enable{true};

    /// Name of the shader of this material
    std::string shader;

    /// Shader properties of this material
    std::vector<Property> properties;
};

} // namespace openglyph::renderer
