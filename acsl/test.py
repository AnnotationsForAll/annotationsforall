import sys, os, subprocess, shlex, re

def print_help():
    print('USAGE: python test.py <input_dir> [<input_file>...] [<flags>...]')
    print('FLAGS:')
    print('\t--help (-h)    : print this help information.')
    print('\t--fc-args (-a) : Give arguments to Frama-C.')
    print('\t--fc-exe (-e)  : Specify the Frama-C executable to use.')

input_dir = ''
input_files = []

fc_args = ''
fc_exe = 'frama-c'

set_fc_args = False
set_fc_exe = False

for arg in sys.argv[1:]:
    if set_fc_args:
        set_fc_args = False
        fc_args = arg
    elif set_fc_exe:
        set_fc_exe = False
        fc_exe = arg
    elif arg == '-h' or arg == '--help':
        print_help()
        sys.exit(0)
    elif arg == '-a' or arg == '--fc-args':
        set_fc_args = True
    elif arg == '-e' or arg == '--fc-exe':
        set_fc_exe = True
    elif input_dir:
        input_files.append(arg)
    else:
        input_dir = arg

if not input_dir:
    print_help()
    sys.exit(1)

fc_arg_list = [fc_exe, "-pp-annot", "-no-frama-c-stdlib", "-cpp-extra-args=-nostdinc", "-cpp-extra-args=-D__FC_MACHDEP_X86_64", ("-cpp-extra-args=-I"+os.path.join(input_dir, 'include')), "-wp", "-wp-timeout", "60"]

test_files = []
for dirname, dirnames, filenames in os.walk(os.path.join(input_dir, 'test')):
    for filename in filenames:
        if filename.endswith('.c') and ((not input_files) or (filename in input_files)):
            test_files.append(os.path.join(dirname, filename))

if fc_args:
    fc_arg_list.extend(shlex.split(fc_args))

re_goal = re.compile('\\[wp\\] \\[[^\\]]*\\] Goal (\\S+) : (\\S+)')
re_succ_id = re.compile('runSuccess(\\d*)')
re_fail_id = re.compile('runFailure(\\d*)')
re_vals_id = re.compile('testValues(\\d*)')

for test_file in test_files:
    fc_arg_list.append(test_file)
    process = subprocess.Popen(fc_arg_list, bufsize=0, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
    fc_arg_list.pop()
    
    out = ''
    while process.poll() == None:
        out_part, _ = process.communicate()
        out += out_part
    
    if (out.find("user error") is not -1) or (out.find("internal error") is not -1):
        print("[ERROR] " + test_file)
        print("\t"+out.replace("\n","\n\t"))
        continue
    
    success_goals_failed = {}
    failure_goals_passed = {}
    values_goals_failed = {}
    
    for line in out.split("\n"):
        goal_data = re_goal.match(line)
        if goal_data:
            valid = (goal_data.group(2) == "Valid")
            if goal_data.group(1).find("runSuccess") is not -1:
                func_id = re_succ_id.search(goal_data.group(1)).group(1)
                if not success_goals_failed.get(func_id, None):
                    success_goals_failed[func_id] = []
                if not valid:
                    success_goals_failed[func_id].append(goal_data.group(1))
            elif goal_data.group(1).find("runFailure") is not -1:
                func_id = re_fail_id.search(goal_data.group(1)).group(1)
                if not failure_goals_passed.get(func_id, None):
                    failure_goals_passed[func_id] = []
                if not valid:
                    failure_goals_passed[func_id].append(goal_data.group(1))
            elif goal_data.group(1).find("testValues") is not -1:
                func_id = re_vals_id.search(goal_data.group(1)).group(1)
                if not values_goals_failed.get(func_id, None):
                    values_goals_failed[func_id] = []
                if goal_data.group(1).find("vacuous") is -1:
                    if not valid:
                        values_goals_failed[func_id].append(goal_data.group(1))
                else:
                    if valid:
                        values_goals_failed[func_id].append(goal_data.group(1))
    
    failed = []
    for goal_id, failures in success_goals_failed.items():
        if failures:
            failed.extend(failures)
    for goal_id, failures in failure_goals_passed.items():
        if failures:
            failed.extend(failures)
    for goal_id, failures in values_goals_failed.items():
        if failures:
            failed.extend(failures)
    if failed:
        print("[FAIL] " + test_file)
        for failure in failed:
            print("\t"+failure)
    else:
        print("[PASS] " + test_file)
