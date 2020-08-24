#!/bin/bash

#echo "--------" for testing purposes

echo A >> multiple_commands_test && echo B >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test && echo B >> multiple_commands_test && echo C >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test || echo B >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test || echo B >> multiple_commands_test || echo C >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test ; echo B >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test ; echo B >> multiple_commands_test ; echo C >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test && ls >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test || echo B >> multiple_commands_test && echo C >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test || echo B >> multiple_commands_test ; echo C >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test ; echo B >> multiple_commands_test && echo C >> multiple_commands_test
echo "----------------" >> multiple_commands_test
echo A >> multiple_commands_test && ls -a >> multiple_commands_test && echo B >> multiple_commands_test
echo "----------------" >> multiple_commands_test
