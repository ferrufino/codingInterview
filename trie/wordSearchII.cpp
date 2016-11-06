struct TrieNode {
    TrieNode *next[26]{};
    int word_idx = -1;
};

TrieNode *build_trie(vector<string> &words) {
    auto root = new TrieNode;
    for (int i = 0; i < words.size(); ++i) {
        auto p = root;
        for (auto ch : words[i]) {
            auto i = ch - 'a';
            if (!p->next[i]) p->next[i] = new TrieNode;
            p = p->next[i];
        }
        p->word_idx = i;
    }
    return root;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    auto trie = build_trie(words);
    vector<int> words_found;
    for (int i = 0; i < board.size(); ++i)
        for (int j = 0; j < board[0].size(); ++j)
            dfs(board, i, j, trie, words_found);
    vector<string> result;
    for (auto i : words_found) result.push_back(words[i]);
    return result;
}

void dfs(vector<vector<char>> &board, int r, int c, TrieNode *p, vector<int> &words_found) {
    auto curr = board[r][c];
    if (!curr || !p->next[curr - 'a']) return;
    p = p->next[curr - 'a'];
    if (p->word_idx != -1) {
        words_found.push_back(p->word_idx);
        p->word_idx = -1;
    }
    board[r][c] = 0;
    if (r > 0)                   dfs(board, r - 1, c, p, words_found);
    if (r < board.size() - 1)    dfs(board, r + 1, c, p, words_found);
    if (c > 0)                   dfs(board, r, c - 1, p, words_found);
    if (c < board[0].size() - 1) dfs(board, r, c + 1, p, words_found);
    board[r][c] = curr;
}
