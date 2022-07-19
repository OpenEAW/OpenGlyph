#include <openglyph/game/behaviors/render_behavior.hpp>
#include <openglyph/game/scene.hpp>
#include <openglyph/renderer/io/model.hpp>

namespace openglyph {

Scene::Scene(AssetCache& asset_cache, const GameObjectTypeStore& game_object_types,
             Environment environment)
    : m_game_object_types(game_object_types), m_environment(std::move(environment))
{
    const auto& create_game_object = [&](const openglyph::GameObjectType& type) {
        auto object = std::make_shared<khepri::scene::SceneObject>();
        if (const auto* render_model = asset_cache.get_render_model(type.space_model_name)) {
            object->create_behavior<openglyph::RenderBehavior>(*render_model);
        }
        return object;
    };

    if (auto* type = m_game_object_types.get(m_environment.skydomes[0].name)) {
        add_object(create_game_object(*type));
    }
    if (auto* type = m_game_object_types.get(m_environment.skydomes[1].name)) {
        add_object(create_game_object(*type));
    }
}

Scene::~Scene() = default;

} // namespace openglyph
