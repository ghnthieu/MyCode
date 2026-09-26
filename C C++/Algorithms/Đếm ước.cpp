int cnt = 0;
for (int i=1; i<=sqrt(n); ++i) {     
    if (n % i == 0)
	cnt += ((i == (n / i)) ? 1 : 2);
}
cout << cnt;