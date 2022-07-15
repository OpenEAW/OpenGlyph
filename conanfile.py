from conans import ConanFile, CMake, tools
from conan.tools.cmake import cmake_layout, CMakeToolchain
import re

class OpenGlyphConan(ConanFile):
    name = "openglyph"
    license = "MIT"
    homepage = "https://github.com/OpenEaW/OpenGlyph"
    url = "https://github.com/OpenEaW/OpenGlyph"
    description = "An open-source game engine compatible with Petroglyph's GlyphX assets"

    def set_version(self):
        git = tools.Git(folder=self.recipe_folder)

        self.version = "0.0.0"
        try:
            GIT_SHORT_HASH_LENGH=12
            latest_tag = git.run("describe --tags --abbrev=0").strip()
            result = re.match(r"v?(\d+.\d+.\d+)", latest_tag)
            if result:
                self.version = "{}".format(result.group(1))
        except Exception:
            pass

        try:
            # Store the short Git version because Conan has a limit of the length of the version string
            self.version += "+{}".format(git.get_revision()[:GIT_SHORT_HASH_LENGH])
            if not git.is_pristine():
                self.version += ".dirty"
        except Exception:
            pass

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    generators = "CMakeDeps"

    requires = [
        ("khepri/[<1.0]"),
        ("rapidxml/1.13"),
    ]

    exports_sources = "CMakeLists.txt", "include/*", "src/*"

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        # Propagate version info into CMake
        version_info = self._parse_version(self.version)
        if version_info:
            tc.variables['OPENGLYPH_VERSION_MAJOR'] = version_info['major']
            tc.variables['OPENGLYPH_VERSION_MINOR'] = version_info['minor']
            tc.variables['OPENGLYPH_VERSION_PATCH'] = version_info['patch']
            tc.variables['OPENGLYPH_VERSION_COMMIT'] = version_info['commit']
            tc.variables['OPENGLYPH_VERSION_CLEAN'] = str(version_info['clean']).lower()
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["OpenGlyph"]

    @staticmethod
    def _parse_version(version):
        result = re.match(r"(\d+).(\d+).(\d+)\+([a-fA-F0-9]+)(\.dirty)?", version)
        if result:
            return {
                'major': int(result.group(1)),
                'minor': int(result.group(2)),
                'patch': int(result.group(3)),
                'commit': result.group(4),
                'clean': (result.group(5) is None)
            }
