// == has a high precedence than &
// the statement needs parentheses 

if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
    printf("No modifier keys pressed\n");