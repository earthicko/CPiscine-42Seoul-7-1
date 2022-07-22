from random_file_creator import RandomFileCreator, TEST_CASE_DIR
import os
import subprocess
from consts import verbose, stop_on_ko, timeout, args, size, file_name
from tester import tester

def test_02_single_file(file_type):
    print("**Test 02, single file input")
    file_sizes_list = [[file_size] for file_size in range(0, size.file_max, size.file_step)]
    flags = []
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)

def test_02_multiple_files(file_type):
    print("**Test 02, multiple files input")
    file_sizes_list = [[file_size, file_size * 2, file_size * 3] for file_size in range(0, size.file_max, size.file_step)]
    flags = []
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)

def test_02_multiple_files_with_args(file_type):
    print("**Test 02, multiple files input with args")
    file_sizes_list = [[file_size, file_size * 2, file_size * 3] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["-c", "10"]
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)
    file_sizes_list = [[file_size, file_size * 2, file_size * 3] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["-c", "500"]
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)

def test_02_error_files(file_type):
    print("**Test 02, multiple files input with non-existent file")
    file_sizes_list = [[file_size, file_size * 2] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["non-existence"]
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)

def test_02_multiple_files_with_error_files_with_args(file_type):
    print("**Test 02, multiple files input with non-existent file")
    file_sizes_list = [[file_size, file_size * 2] for file_size in range(0, size.file_max, size.file_step)]
    flags = ["-c", "10", "nonexistence", "nofile", "void"]
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)
    flags = ["nonexistence", "-c", "200", "nofile", "void"]
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)
    flags = ["nonexistence", "nofile", "-c", "300", "void"]
    tester(file_type, "./ex02", "tail", "./ft_tail", file_sizes_list, flags)