#!/usr/bin/env python3
import subprocess
import sys
import re

def usage(program):
	print(f"Usage: {program} [--release]")

def git_describe():
	return ['git','describe','--long']

def meson_rewrite(version):
	return ['meson', 'rewrite', 'kwargs', 'set', 'project', '/', 'version', version]

def semver(is_release):
	pattern = re.compile('^(\d+\.\d+\.\d+)-(\d+)-(.*)$')
	m = pattern.match(subprocess.run(git_describe(), capture_output=True).stdout.decode(encoding='utf-8'))

	if is_release:
		return m.group(1)
	else:
		return m.group(1) + '-' + m.group(2) + '+' + m.group(3)

if __name__ == "__main__":
	if len(sys.argv) == 2 and sys.argv[1] == '--help':
		usage(sys.argv[0])
		exit()

	is_release = False
	if len(sys.argv) == 2:
		is_release = sys.argv[1] == '--release'

	if len(sys.argv) > 2:
		usage(sys.argv[0])
		exit()

	subprocess.run(meson_rewrite(semver(is_release)))
