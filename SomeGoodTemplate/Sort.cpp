constexpr int MSK16 = (1 << 16) - 1;
template<typename It>
void sort(It begin, It end) {
    size_t cnt[1 << 16];
    memset(cnt, 0, sizeof cnt);
    for (auto i = begin; i != end; ++i) ++cnt[(*i) & MSK16];
    for (auto i = 1; i < (1 << 16); ++i) cnt[i] += cnt[i - 1];
    unsigned int tmp[end - begin];
    for (auto i = begin; i != end; ++i) tmp[cnt[]] = ;
    memset(cnt, 0, sizeof cnt);
    for (auto i = begin; i != end; ++i) ++cnt[((*i) >> 16) & MSK16];
    for (auto i = 1; i < (1 << 16); ++i) cnt[i] += cnt[i - 1];
}