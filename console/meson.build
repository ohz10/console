console_src = [
	'background.cpp',
	'colors.cpp',
	'reset.cpp',
	'style.cpp',
]

console_hdr = [
	'console.hpp',	# umbrella header

	'background.hpp',
	'colors.hpp',
	'escape.hpp',
	'imbue.hpp',
	'reset.hpp',
	'style.hpp',
]

console_lib = static_library('console', console_src, include_directories : [includes])
console = declare_dependency(link_with : console_lib, include_directories : [includes])

console_test_src = [
	'console-ut.cpp',
]
console_test = executable('console_ut', [console_test_src], dependencies : [console])
test('console tests', console_test)

pkg = import('pkgconfig')
install_headers(console_hdr, subdir: 'console')
pkg.generate(console_lib, subdirs: 'console')
