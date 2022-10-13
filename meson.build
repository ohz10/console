project('console', 'cpp', version : '0.0.0', default_options : ['cpp_std=c++20', 'werror=true', 'warning_level=3'])

conf_data = configuration_data()
conf_data.set('version', meson.project_version())

subdir('_dependencies')
subdir('_includes')

subdir('console')
