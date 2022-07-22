from random_file_creator import RandomFileCreator, TEST_CASE_DIR
import random
import os
import subprocess
from consts import timeout, stop_on_ko, verbose, args, size, file_name


def tester(file_type, pwd, bin_ref, bin_usr, file_sizes_list, flags):
    print("tester args ", file_type, pwd, bin_ref, bin_usr, flags)

    bin_diff = "diff"
    subprocess.run(args.make_re, cwd=pwd, stdout=subprocess.DEVNULL)
    print("make re done")

    counter_all = 0
    counter_ok = 0
    print("")
    for i, file_sizes in enumerate(file_sizes_list):
        print(f"\rcombination {i} input file size {file_sizes}... ", end='')

        counter_all += 1

        file_creators = [RandomFileCreator(
            file_size, TEST_CASE_DIR) for file_size in file_sizes]
        for creator in file_creators:
            if file_type == "binary":
                creator.create_binary()
            if file_type == "printable":
                creator.create_printable()
            if file_type == "nonprintable":
                creator.create_nonprintable()

        file_names = [f"../{creator.path}" for creator in file_creators]
        random.shuffle(file_names)
        
        splice_pos = random.randint(0, len(file_names) - 1)
        all_args = file_names[:splice_pos] + flags + file_names[splice_pos:]
        
        ref_command = ''
        usr_command = ''
        with open(file_name.ref, "w") as o_cat_ref:
            ref_args = [bin_ref] + all_args
            ref_command = ' '.join(ref_args)
            if verbose == 1:
                print(f"ref args: {ref_args}")
            subprocess.run(ref_args, cwd=pwd,
                           stdout=o_cat_ref, timeout=timeout, stderr=subprocess.DEVNULL)
        with open(file_name.usr, "w") as o_cat_usr:
            usr_args = [bin_usr] + all_args
            usr_command = ' '.join(usr_args)
            if verbose == 1:
                print(f"usr args: {usr_args}")
            subprocess.run(usr_args, cwd=pwd,
                           stdout=o_cat_usr, timeout=timeout, stderr=subprocess.DEVNULL)
        with open(file_name.diff, "w") as diff:
            subprocess.run(
                [bin_diff, file_name.ref, file_name.usr], stdout=diff)

        diff_size = os.path.getsize(file_name.diff)
        if verbose == 1:
            print(f"\tref vs usr diff size: {diff_size}")

        if (diff_size == 0):
            print("Diff OK :D ", end='')
            counter_ok += 1
        else:
            print("Diff KO :( ")
            print("while executing:")
            print(ref_command)
            print(usr_command)
            print("You can find diff result in ./diff_res")
            if file_type == "binary" or file_type == "nonprintable":
                with open("dump_ref", "w") as dump_ref:
                    subprocess.run(["hexdump", "-C", file_name.ref], stdout=dump_ref)
                with open("dump_usr", "w") as dump_usr:
                    subprocess.run(["hexdump", "-C", file_name.usr], stdout=dump_usr)
                with open(file_name.diff, "w") as diff:
                    subprocess.run([bin_diff, "dump_ref", "dump_usr"], stdout=diff)
            with open(file_name.diff, 'r') as diff_file:
                print("\n=================== diff start ===================")
                print(diff_file.read())
                print("=================== diff end =====================")
            if stop_on_ko == 1:
                return

        os.remove(file_name.ref)
        os.remove(file_name.usr)
        os.remove(file_name.diff)

        for creator in file_creators:
            creator.delete()
    
    subprocess.run(args.make_fclean, cwd=pwd, stdout=subprocess.DEVNULL)
    print("\nmake fclean done")

    print(
        f"\n==> Test Result: Total {counter_all}, OK {counter_ok}, KO {counter_all - counter_ok}\n")