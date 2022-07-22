from random_file_creator import RandomFileCreator, TEST_CASE_DIR
import os
import subprocess
from consts import verbose, stop_on_ko, timeout, args, size, file_name
from tester import tester

def test_03_single_file(file_type):
    print("**Test 03, single file input")
    file_sizes_list = [[file_size] for file_size in range(0, size.file_max, size.file_step)]
    flags = []
    tester(file_type, "./ex03", "hexdump", "./ft_hexdump", file_sizes_list, flags)

def test_03_multiple_files(file_type):
    print("**Test 03, multiple files input")
    file_sizes_list = [[file_size, file_size * 2, file_size * 3] for file_size in range(0, size.file_max, size.file_step)]
    flags = []
    tester(file_type, "./ex03", "hexdump", "./ft_hexdump", file_sizes_list, flags)

def test_03_multiple_files_with_args(file_type):
    print("**Test 03, multiple files input with args")
    file_sizes_list = [[file_size, file_size * 2, file_size * 3] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["-C"]
    tester(file_type, "./ex03", "hexdump", "./ft_hexdump", file_sizes_list, flags)

def test_03_error_files(file_type):
    print("**Test 03, multiple files input with non-existent file")
    file_sizes_list = [[file_size, file_size * 2] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["non-existence"]
    tester(file_type, "./ex03", "hexdump", "./ft_hexdump", file_sizes_list, flags)

def test_03_multiple_files_with_error_files_with_args(file_type):
    print("**Test 03, multiple files input with non-existent file")
    file_sizes_list = [[file_size, file_size * 2] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["-C", "nonexistence", "nofile", "void"]
    tester(file_type, "./ex03", "hexdump", "./ft_hexdump", file_sizes_list, flags)
    flags = ["nonexistence", "-C", "nofile", "void"]
    tester(file_type, "./ex03", "hexdump", "./ft_hexdump", file_sizes_list, flags)
    flags = ["nonexistence", "nofile", "-C", "void"]
    tester(file_type, "./ex03", "hexdump", "./ft_hexdump", file_sizes_list, flags)