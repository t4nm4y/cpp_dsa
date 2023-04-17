{
    unordered_map<int,int>m;
    for(int i: locations) m[i]++;
    int n=movedFrom.size();
    for(int i=0; i<n; i++)
    {
        m[movedFrom[i]]--;
        m[movedTo[i]]++;
    }
    vector<int> ans;
    for(auto i: m) if(i.second>0) ans.push_back(i.first);
    sort(ans.begin(), ans.end());
    return ans;
}