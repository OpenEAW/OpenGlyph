cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(OpenGlyph CXX)

# External libraries
find_package(khepri REQUIRED)
find_package(rapidxml REQUIRED)

add_library(${PROJECT_NAME}
    src/assets/asset_cache.cpp
    src/assets/asset_loader.cpp
    src/assets/io/map.cpp
    src/game/game_object_type_store.cpp
    src/game/scene_renderer.cpp
    src/game/scene.cpp
    src/io/chunk_reader.cpp
    src/renderer/io/material.cpp
    src/renderer/io/model.cpp
    src/renderer/material_store.cpp
    src/renderer/model_creator.cpp
    src/parser/parsers.cpp
    src/parser/xml_parser.cpp
    src/version.cpp
)

set_property(
  SOURCE src/version.cpp
  APPEND
  PROPERTY COMPILE_DEFINITIONS
  OPENGLYPH_VERSION_MAJOR=${OPENGLYPH_VERSION_MAJOR}
  OPENGLYPH_VERSION_MINOR=${OPENGLYPH_VERSION_MINOR}
  OPENGLYPH_VERSION_PATCH=${OPENGLYPH_VERSION_PATCH}
  OPENGLYPH_VERSION_STRING="${OPENGLYPH_VERSION_MAJOR}.${OPENGLYPH_VERSION_MINOR}.${OPENGLYPH_VERSION_PATCH}"
  OPENGLYPH_VERSION_COMMIT="${OPENGLYPH_VERSION_COMMIT}"
  OPENGLYPH_VERSION_CLEAN=${OPENGLYPH_VERSION_CLEAN}
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    khepri::khepri
  PRIVATE
    rapidxml::rapidxml
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

export(TARGETS ${PROJECT_NAME} NAMESPACE OpenGlyph:: FILE OpenGlyphTargets.cmake)

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME})
install(DIRECTORY include/openglyph DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT ${PROJECT_NAME} DESTINATION lib)
