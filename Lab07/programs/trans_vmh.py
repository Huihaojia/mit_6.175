#!/usr/bin/env python3

import sys

if len(sys.argv) != 3:
    print('Usage: ./trans_vmh [input vmh] [output vmh]')
    raise

in_file = sys.argv[1]
out_file = sys.argv[2]

with open(in_file, 'r') as fin:
    lines = fin.readlines()

with open(out_file, 'w') as fout:
    # fout.write(lines[0]);
    line_num = 0
    inst_line = ''
    for i in range(1, len(lines)):
        val = lines[i][:-1].rstrip('\n')
        inst_line = val + inst_line
        # fout.write(val[8:]);
        # fout.write(val[:8]);    
        line_num += 1    
        if(line_num == 8):
            line_num = 0    
            fout.write(inst_line);     
            fout.write('\n');       
            inst_line = ''