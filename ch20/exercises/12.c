// + has higher precedence than <<
// the statement needs parentheses 

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
    return (high_byte << 8) + low_byte;
}