#pragma once

#include <openglyph/renderer/render_model.hpp>

#include <khepri/scene/behavior.hpp>

namespace openglyph {

class RenderBehavior : public khepri::scene::Behavior
{
public:
    struct Type
    {
        std::string model_name;
    };

    explicit RenderBehavior(const renderer::RenderModel& model) : m_model(model) {}

    const auto& model() const noexcept
    {
        return m_model;
    }

private:
    const renderer::RenderModel& m_model;
};

} // namespace openglyph
