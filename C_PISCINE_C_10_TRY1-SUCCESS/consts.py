timeout = 1
stop_on_ko = 1
verbose = 0

class args:
    make_re = ["make", "re"]
    make_fclean = ["make", "fclean"]

class size:
    file_max = 200
    file_step = 1

class file_name:
    ref = "res_ref"
    usr = "res_usr"
    diff = "diff_res"