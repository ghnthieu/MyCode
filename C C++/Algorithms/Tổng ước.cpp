ll sum = 0;
for (int i=1; i<=sqrt(n); ++i) {     
    if (n % i == 0)
	sum += ((i == (n / i)) ? i : (i + (n / i)));
}
cout << sum;