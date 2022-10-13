include_array = ['.', '..']

sys = target_machine.system()
if sys == 'openbsd' or sys == 'freebsd' or sys == 'netbsd' or sys == 'dragonfly'
	include_array += '/usr/local/include'
endif

includes = include_directories(include_array)
