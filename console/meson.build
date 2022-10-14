console_src = [
	'background.cpp',
	'colors.cpp',
	'cursor.cpp',
	'line.cpp',
	'reset.cpp',
	'screen.cpp',
	'spinner.cpp',
	'style.cpp',
]

console_hdr = [
	'console.hpp',	# umbrella header

	'background.hpp',
	'colors.hpp',
	'cursor.hpp',
	'escape.hpp',
	'imbue.hpp',
	'line.hpp',
	'reset.hpp',
	'screen.hpp',
	'spinner.hpp',
	'style.hpp',
]

console_lib = static_library('console', console_src, include_directories : [includes])
console = declare_dependency(link_with : console_lib, include_directories : [includes])

console_test = executable('console_ut', ['console-ut.cpp'], dependencies : [console])
test('console tests', console_test)

spinner_test = executable('spinner_ut', ['spinner-ut.cpp'], dependencies : [console])
test('spinner tests', spinner_test)

pkg = import('pkgconfig')
install_headers(console_hdr, subdir: 'console')
pkg.generate(console_lib, subdirs: 'console', description: 'A library for manipulating console output')
