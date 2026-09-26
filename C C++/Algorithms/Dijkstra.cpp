void dijkstra(int s) {
    memset(duong, 0x3f, (n + 1) * sizeof(ll));
    duong[s] = 0;
    priority_queue <ii(ll, int), vii(ll, int), greater <ii(ll, int)>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        ii(ll, int) u = pq.top(); pq.pop();
        if (u.fi > duong[u.se]) continue;
        for (ii(int, int) v : inp[u.se]) {
            if (minimize(duong[v.fi], duong[u.se] + v.se))
                pq.push({duong[v.fi], v.fi});
        }
    }
    For(i, 1, n, 1) cout << duong[i] << " ";
}
