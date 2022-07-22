import tester01
import tester02
import tester03
import consts

if __name__ == "__main__":
    print("shallowthought C10 running")
    print("current settings:")
    print(f"file size: 0 to {consts.size.file_max}, step {consts.size.file_step}")

    i_test = int(input("test which exercise(01 ~ 03): "))
    if not (1 <= i_test <= 3):
        print("invalid exercise number")
        exit()
    print("0: random binary")
    print("1: random ascii (only printable)")
    print("2: random ascii (including non-printables)")
    i_file_type = int(input("Choose test file type: "))
    file_type = ""
    if i_file_type == 0:
        file_type = "binary"
    elif i_file_type == 1:
        file_type = "printable"
    elif i_file_type == 2:
        file_type = "nonprintable"
    else:
        exit()

    if i_test == 1:
        tester01.test_01_single_file(file_type)
        tester01.test_01_multiple_files(file_type)
        tester01.test_01_error_files(file_type)
    if i_test == 2:
        tester02.test_02_single_file(file_type)
        tester02.test_02_multiple_files(file_type)
        tester02.test_02_multiple_files_with_args(file_type)
        tester02.test_02_error_files(file_type)
        tester02.test_02_multiple_files_with_error_files_with_args(file_type)
    if i_test == 3:
        tester03.test_03_single_file(file_type)
        tester03.test_03_multiple_files(file_type)
        tester03.test_03_multiple_files_with_args(file_type)
        tester03.test_03_error_files(file_type)
        tester03.test_03_multiple_files_with_error_files_with_args(file_type)
