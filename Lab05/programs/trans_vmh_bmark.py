#!/usr/bin/env python3

import sys

if len(sys.argv) != 3:
	print('Usage: ./trans_vmh [input vmh] [output vmh]')
	raise

in_file = sys.argv[1]
out_file = sys.argv[2]

with open(in_file, 'r') as fin:
	lines = fin.readlines()

# orig vmh is 8B per line, we transfer it to 64B per line
if ((len(lines) - 1) % 8) != 0:
	print('ERROR: size not 64B aligned')

with open(out_file, 'w') as fout:
	fout.write(lines[0])
	for i in range(1, len(lines), 4):
		val = lines[i][:-1].rstrip('\n')
		fout.write(val[8:] + '\n')
		fout.write(val[:8] + '\n')
		# val = ''
		# for j in range(0, 4):
		# 	val += lines[i + j]
		# fout.write(val + '\n')




