console_src = [
    'background.cpp',
    'colors.cpp',
	'counter.cpp',
    'cursor.cpp',
    'line.cpp',
	'position.cpp',
	'progress_indicator.cpp',
	'progress_bar.cpp',
    'reset.cpp',
    'screen.cpp',
    'spinner.cpp',
    'style.cpp',
]

console_hdr = [
    'console.hpp',  # umbrella header

    'background.hpp',
    'colors.hpp',
	'console_color.hpp',
	'counter.hpp',
    'cursor.hpp',
    'escape.hpp',
    'imbue.hpp',
    'line.hpp',
	'position.hpp',
	'progress_indicator.hpp',
	'progress_bar.hpp',
    'reset.hpp',
    'screen.hpp',
    'spinner.hpp',
    'style.hpp',
]

console_lib = static_library('console', console_src, include_directories : [includes])
console = declare_dependency(link_with : console_lib, include_directories : [includes])

console_test = executable('console_ut', ['console-ut.cpp'], dependencies : [console])
test('console tests', console_test)

progress_test = executable('progress_ut', ['progress-ut.cpp'], dependencies : [console])
test('progress tests', progress_test)

pkg = import('pkgconfig')
install_headers(console_hdr, subdir: 'console')
pkg.generate(console_lib, subdirs: 'console', description: 'A library for manipulating console output')
