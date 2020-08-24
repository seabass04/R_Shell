#!/bin/sh
./../rshell < multiple_commands_tests >> multiple_commands_tests_output
./../rshell < single_command_tests >> single_command_tests_output
./../rshell < exit_command_test >> exit_command_test_output