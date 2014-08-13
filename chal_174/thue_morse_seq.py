"""Generates the Thue-Morse sequence, a binary sequence that never repeats."""

import sys

def thue_morse(binstr):
    toggled = ['1' if c == '0' else '0' for c in binstr]
    return binstr + ''.join(toggled)

def main(nth_order):
	bit_str = '0'
	for i in range(nth_order):
	    print(i, bit_str, sep=', ')
	    bit_str = thue_morse(bit_str)

if __name__ == '__main__':
	nth_order = 7
	if len(sys.argv) > 1:
		nth_order = int(sys.argv[1])
	status = main(nth_order)
	sys.exit(status)
