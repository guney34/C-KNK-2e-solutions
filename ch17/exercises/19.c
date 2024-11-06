void execute_command(char *str)
{
    for (size_t i = 0; i < sizeof(file_cmd)/sizeof(file_cmd[0]); ++i)
        if (strcmp(str, file_cmd[i].cmd_name) == 0)
            file_cmd[i].cmd_pointer();
}