xor[l .. r] = xor[1 .. r] ^ xor[1 .. l - 1] = xor từ l đến r
xorpb[l .. r] = xorpb[1 .. r] ^ xorpb[1 .. l - 1] = xor từ l đến r phân biệt
xor[l .. r] ^ xorpb[l .. r] = xor các số xuất hiện chẵn trong đoạn từ l đến r