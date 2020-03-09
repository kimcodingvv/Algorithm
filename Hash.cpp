struct HASH {
	vector <pii> hash;
	HASH() {
		hash.resize(mod, { mod, 0 });
	}
	int next(int key) {
		return (key + MAX + (key % 307)) % mod;
	}
	void insert(int key) {
		int val = key;
		do {
			key = next(key);
		} while (hash[key].fs != val && hash[key].fs != mod);
		hash[key].fs = val;
		hash[key].sd++;
	}
	int find(int key) {
		int val = key;
		do {
			key = next(key);
		} while (hash[key].fs != val && hash[key].fs != mod);
		return hash[key].fs == mod ? 0 : hash[key].sd;
	}
	~HASH() {
		hash.clear();
	}
};
