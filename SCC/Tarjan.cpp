function <int(int)> dfs = [&](int now) {
		int ret = dfsn[now] = ++cnt;
		st.push(now);
		for (int next : adj[now]) {
			if (!dfsn[next]) ret = min(ret, dfs(next));
			else if (!finish[next]) ret = min(ret, dfsn[next]);
		}
		if (ret == dfsn[now]) {
			while (1) {
				int tp = st.top(); st.pop();
				cpn[tp] = scc_cnt;
				finish[tp] = 1;
				if (tp == now) break;
			}
			scc_cnt++;
		}
		return ret;
	};
