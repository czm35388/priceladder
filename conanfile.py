from conans import ConanFile

class Priceladder(ConanFile):
    name = "Priceladder"
    version = "0.0.1"
    generators = "cmake"
    url = "https://github.com/czm35388/priceladder"
    license = "MIT"
    author = "czm35388"

    settings = "os", "compiler", "build_type", "arch"

    def requirements(self):
        self.requires("qt/5.15.3")