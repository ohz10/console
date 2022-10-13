#!/usr/bin/env python3
import os.path
import subprocess
import sys
import re

# compile regex once
filename_pattern = re.compile('\s*\'([a-zA-Z0-9_\-\\\/]+\.(hpp|cpp))\'\s*,\s*$')	
end_pattern = re.compile('\s*\]\s*$')

def usage(program):
	print(f"Usage: {program} <meson_file> <src_group> [<src_group> ...]")

def create_group_regex(groups):
	group_regex = ''
	for index,group in enumerate(groups):
		group_regex += group
		if index < len(groups) - 1:
			group_regex += '|'

	return re.compile(f'\s*({group_regex})\s*=\s*\[\s*$')
	
def is_begin_group(line, group_pattern):
	m = group_pattern.match(line)
	return True if m else False

def is_end_group(line):
	return True if end_pattern.match(line) else False

def extract_filename(line):
	m = filename_pattern.match(line)
	return m.group(1) if m else ''

def filter_empty_filenames(files):
	return filter(lambda a: a != '', files)

def find_filenames(lines, groups):
	group_regex = create_group_regex(groups)
	filenames = []
	in_group = False
	
	for line in lines:
		if is_end_group(line):
			in_group = False
			continue

		if is_begin_group(line,group_regex):
			in_group = True
			continue

		if in_group:
			filenames.append(extract_filename(line))

	return filenames

def write_cppcheck_file(base_path, filenames):
	cppcheck_file = 'cppcheck_files.txt'

	ofile = open(cppcheck_file, 'w')
	ofile.writelines([ f'{file}\n' for file in [ os.path.join(base_path, file) for file in filenames ]])

	return cppcheck_file

def cppcheck(check_file):
	return ['cppcheck', f'--file-list={check_file}']

def exec_cppcheck(cppcheck_file):
	popen = subprocess.Popen(cppcheck(cppcheck_file), universal_newlines=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
	for stdout_line in iter(popen.stdout.readline, ''):
		yield stdout_line.rstrip()

	popen.stdout.close()
	return_code = popen.wait()

	if return_code:
		sys.exit(return_code)

if __name__ == "__main__":
	if len(sys.argv) == 2 and sys.argv[1] == '--help':
		usage(sys.argv[0])
		exit()

	if len(sys.argv) < 2:
		usage(sys.argv[0])
		exit()

	lines = open(sys.argv[1], 'r').readlines()
	check_files = filter_empty_filenames(find_filenames(lines, sys.argv[1:]))
	cppcheck_file = write_cppcheck_file(os.path.dirname(sys.argv[1]), check_files)

	for line in exec_cppcheck(cppcheck_file):
		print(line)
