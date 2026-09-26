ll findindex(int v, int treel, int treer, int index) {
    while (treel <= treer) {
        fix(v, treel, treer);
        if (treel == treer)
            break;
        int treem = treel + treer >> 1;
        if (index <= treem) {
            v <<= 1;
            treer = treem;
        }
        else {
            v = v << 1 | 1;
            treel = treem + 1;
        }
    }
    return tree[v];
}
