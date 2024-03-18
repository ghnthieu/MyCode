void tdijkstra() {
    memset(duong, 0x3f, sizeof(duong));
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j)
            duong[i][j] = a[i][j];
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            int ti1 = 1, ti2 = n;
            while (ti1 <= ti2) {
                if (ti1 == ti2) {
                    if (duong[i][j] > duong[i][ti1] + duong[ti1][j])
                        duong[i][j] = duong[i][ti1] + duong[ti1][j];
                }
                else {
                    if (duong[i][j] > duong[i][ti1] + duong[ti1][j])
                        duong[i][j] = duong[i][ti1] + duong[ti1][j];
                    if (duong[i][j] > duong[i][ti2] + duong[ti2][j])
                        duong[i][j] = duong[i][ti2] + duong[ti2][j];
                }
                ++ti1;
                --ti2;
            }
        }
    }
}