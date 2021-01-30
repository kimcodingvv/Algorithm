vector <vector <int>> adj(n + 1);
vector <int> dfsn(n + 1), finish(n + 1), cpn(n + 1);
stack <int> st;
int cnt = 1, scc_cnt = 1;

function <int(int)> tarjan = [&](int now) {
	int ret = dfsn[now] = ++cnt;
	st.push(now);
	for (int next : adj[now]) {
		if (!dfsn[next]) ret = min(ret, tarjan(next));
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
