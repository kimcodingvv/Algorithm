struct Matrix {
	vector <vector <int>> m;
	int r, c;

	Matrix(int rr = 0, int cc = 0) : r(rr), c(cc) {
		m.resize(r, vector <int>(c));
	}

	Matrix operator * (const Matrix& a) {
		Matrix ret(r, c);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				int& ref = ret.m[i][j];
				for (int k = 0; k < c; k++)
					ref = (1ll * ref + 1ll * m[i][k] * a.m[k][j]) % mod;
			}
		}
		return ret;
	}

	Matrix power(long long b) {
		Matrix ret(r, c);
		for (int i = 0; i < r; i++) ret.m[i][i] = 1;
		Matrix a = *this;
		while (b) {
			if (b & 1) ret = ret * a;
			b >>= 1; a = a * a;
		}
		return ret;
	}
};
