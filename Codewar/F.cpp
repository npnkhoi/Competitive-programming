std::vector<int> queriesOnRectange(int n, int m, std::vector<std::vector<int>> queries1, std::vector<std::vector<int>> queries2) {
	vector<int> a(m * n + 2, 0);
	// int b[n + 1][n + 1];  // fix this
	vector<vector<int> > b;
	b.resize(n + 1);
	for (int i = 0; i < n + 1; ++ i) {
		b.assign(m + 1, 0);
	}
	for (auto q : queries1) {
		int l = m * q[0] + q[1], r = m * q[2] + q[3];
		a[l] ++;
		a[r + 1] --;
	}
	for (int i = 1; i <= m * n; ++ i) {
		a[i] += a[i - 1];
		int r = i / m, c = i % m;
		b[r][c] = a[i];
		if (r > 0) b[r][c] += b[r - 1][c];
		if (c > 0) b[r][c] += b[r][c - 1];
		if (r > 0 && c > 0) b[r][c] -= b[r - 1][c - 1];
	}
	vector<int> ans;
	for (auto q : queries) {
		int x = q[0], y = q[1], u = q[2], v = q[3];
		int res = b[u][v];
		if (x > 0) res -= b[x - 1][v];
		if (y > 0) res -= b[u][y - 1];
		if (x > 0 && y > 0) res += b[x - 1][y - 1];
		ans.push_back(res);
	}	
	return ans;
}
