void dijkstra(int s, int t) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : inp[u.se]) {
            if (minimize(duong[v.fi], duong[u.se] + v.se)) {
                pq.push({duong[v.fi], v.fi});
                trace[v.fi] = u.se;
            }
        }
    }
    vec(int) luu;
    do {
        luu.pub(t);
        t = trace[t];
    } while (t != s);
    luu.pub(s);
    reverse(all(luu));
}
