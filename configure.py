import os
import sys

projectdir = os.path.dirname(os.path.realpath(__file__))
sys.path.insert(0, os.path.join(projectdir, 'vendor', 'ninja'))
sys.path.insert(0, os.path.join(projectdir, 'scripts'))

from procdraw import buildgen

BUILD_DIR = 'build'
BUILD_FILENAME = 'build.ninja'

build = buildgen.Build()

build.builddir = BUILD_DIR
build.cppflags = '/nologo /EHsc /DUNICODE /D_UNICODE'
build.linkflags = '/nologo'

build.add_source_set('procdraw_sources',
    sources = [
        'src/Color.cpp',
        'src/D3D11Graphics.cpp',
        'src/Interpreter.cpp',
        'src/Printer.cpp',
        'src/ProcdrawApp.cpp',
        'src/ProcdrawMath.cpp',
        'src/Reader.cpp',
        'src/VirtualMachine.cpp',
        'src/WinUtils.cpp'
    ]
)

build.add_executable('Procdraw',
    sources = ['winmain/WinMain.cpp'],
    deps = ['procdraw_sources'],
    include_dirs = ['src'],
    libs = ['d3d11.lib', 'D3DCompiler.lib']
)

buildgen.generate_ninja(build, open(BUILD_FILENAME, 'w'))
