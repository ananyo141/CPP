#!/usr/bin/env python3

import os
import argparse
import random
from abc import ABC, abstractmethod

# Abstract Base Class to check argument
class Checker(ABC):
    def __call__(self, arg):
        try:
            return self.checker(arg)
        except Exception as exc:
            self.handle(str(exc))

    @abstractmethod
    def checker(self, arg):
        " Subclass this method to validate argument "

    @staticmethod
    def handle(errmsg):
         raise argparse.ArgumentTypeError(errmsg) from None

class CheckPositive(Checker):
    def checker(self, arg):
        num = int(arg)
        assert num > 0, 'MIN should be positive int'
        return num

class CheckInputFile(Checker):
    def checker(self, fname):
        assert os.path.isfile(fname), \
        f"{fname} either doesn't exist or isn't readable"
        return fname

class CheckOutputFile(Checker):
    def checker(self, fname):
        try:
            open(fname, 'w').write('Testing')
            os.unlink(fname)
            return fname
        except: 
            raise Exception(f"Output file {fname} not writable")

def main():
    import re, sys

    # Add cmdline parsing rules
    parser = argparse.ArgumentParser()
    parser.add_argument('dict_file',   help='Use this file to select words', 
                        type=CheckInputFile())
    parser.add_argument('-n', '--num', help='Choose number of words',
                        default=26, type=CheckPositive())
    parser.add_argument('-o', '--output-file', help='Optional OutputFile',
                        default=None, type=CheckOutputFile())
    parser.add_argument('--min', help='Minimum number of letters',
                        default=3, type=CheckPositive())
    args = parser.parse_args()

    # read and build random words
    with open(args.dict_file) as infile:
        # to escape literal {, use {{ in place of {
        # i.e, f-string uses { and r-string uses {{
        words = re.findall(fr'\w{{{args.min},}}', infile.read())
        randomWords = random.sample(words, min(len(words), args.num))

    # select output stream (if output file not given, use stdout)
    outfile = open(args.output_file, 'w') if args.output_file \
                                          else sys.stdout
    # write output
    for word in randomWords: 
        print(word.lower(), file=outfile)

    if args.output_file:
        print(f"Output file '{args.output_file}' saved with "
              f"{len(randomWords)} words from file '{args.dict_file}'")

if __name__ == '__main__':
    main()

