function <void(int)> dfs = [&](int now) {
			visit[now] = 1;
			for (int next : adj[now]) {
				if (visit[next]) continue;
				dfs(next);
			}
			st.push(now);
		};
		function <void(int)> dfs2 = [&](int now) {
			visit[now] = 1;
			newscc.push_back(now);
			cpn[now] = (int)scc.size();
			for (int next : r_adj[now]) {
				if (visit[next]) continue;
				dfs2(next);
			}
		};
		for (int i = 1; i <= n; i++)
			if (!visit[i]) dfs(i);
		visit = cpn = vi(n + 1);
		while (st.size()) {
			int now = st.top(); st.pop();
			if (visit[now]) continue;
			newscc.clear();
			dfs2(now);
			scc.push_back(newscc);
		}
