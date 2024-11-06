unsigned int reverse_bits(unsigned int n)
{
    static const int len = sizeof(int) * 8;
    unsigned int result = 0x0u;
    for (int i = 0; i < len/2; ++i) {
        result |= (n>>(len-1-2*i)) & (0x1u<<i);
        result |= (n<<(len-1-2*i)) & (0x1u<<(len-1-i));
    }
    return result;
}