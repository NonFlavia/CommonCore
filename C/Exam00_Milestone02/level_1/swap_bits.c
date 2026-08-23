// hi, this code was made by flavides during the 42 Common Core!

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
