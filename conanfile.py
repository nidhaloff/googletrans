from conans import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake
from conan.tools.layout import cmake_layout


class TranslatorsConan(ConanFile):
    name = "translators"
    version = "0.1.0"

    # dependencies
    requires = "cpr/1.6.2"

    # Optional metadata
    license = "MIT"
    author = "Nidhal Baccouri nidhalbacc@gmail.com"
    description = "A flexible free and unlimited python tool to translate between different languages in a simple way using multiple translators."
    topics = ("cpp", "translation", "translator", "google translator", "googletrans")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    generators = "cmake", "gcc"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["translators"]
