ll getmaxdiem(int n, int m, int l, int r) {
    ll res = 0;
    if (l > 0 && r > 0)
        maximize(res, 1ll * (tdo[r].fi - tdo[l].fi) * (tdo[r].fi - tdo[l].fi));
    if (n > 0 && m > 0)
        maximize(res, 1ll * (tdo[n].se - tdo[m].se) * (tdo[n].se - tdo[m].se));
    for (int i=0; i<2; ++i) {
        for (int j=0; j<2; ++j)
            maximize(res, 1ll * (tdo[((i) ? l : r)].fi + tdo[((j) ? n : m)].se) * (tdo[((i) ? l : r)].fi + tdo[((j) ? n : m)].se));
    }
    return res;
}