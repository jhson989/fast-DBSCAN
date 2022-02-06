from distutils.core import Extension, setup
from Cython.Build import cythonize
import pathlib

ext_modules = [
    Extension("fastDBSCAN",
              sources=["fastDBSCAN.pyx"],
              libraries=["fastDBSCAN"],
              library_dirs=[ str(pathlib.Path().resolve()) ],
              include_dirs=[ str(pathlib.Path().resolve())+"/../../include/" ],
              language="c++",
              )
]

setup(
    name="fastDBSCAN",
    ext_modules=cythonize(ext_modules)
    )