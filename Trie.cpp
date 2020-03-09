struct Trie {
	Trie* next[10];
	bool finish;
	Trie() : finish(false){
		memset(next, 0, sizeof(next));
	}
	void insert(char* key) {
		if (!(*key)) finish = true;
		else {
			int node = *key - '0';
			if (next[node] == NULL)
				next[node] = new Trie();
			next[node]->insert(key + 1);
		}
	}
	bool find(char* key) {
		if (!(*key)) return 0;
		if (finish) return 1;
		int node = *key - '0';
		return next[node]->find(key + 1);
	}
	~Trie() {
		for(int i=0;i<10;i++)
			if(next[i])
				delete next[i];
	}
};
