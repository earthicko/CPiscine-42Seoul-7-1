from random_file_creator import RandomFileCreator, TEST_CASE_DIR
import random
import os
import subprocess
from consts import timeout, stop_on_ko, verbose, args, size, file_name
from tester import tester

def test_01_single_file(file_type):
    print("**Test 01, single file input")
    file_sizes_list = [[file_size] for file_size in range(0, size.file_max, size.file_step)]
    flags = []
    tester(file_type, "./ex01", "cat", "./ft_cat", file_sizes_list, flags)

def test_01_multiple_files(file_type):
    print("**Test 01, multiple files input")
    file_sizes_list = [[file_size, file_size * 2, file_size * 3] for file_size in range(0, size.file_max, size.file_step)]
    flags = []
    tester(file_type, "./ex01", "cat", "./ft_cat", file_sizes_list, flags)

def test_01_error_files(file_type):
    print("**Test 01, multiple files input with non-existent file")
    file_sizes_list = [[file_size, file_size * 2] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["non-existence"]
    tester(file_type, "./ex01", "cat", "./ft_cat", file_sizes_list, flags)
