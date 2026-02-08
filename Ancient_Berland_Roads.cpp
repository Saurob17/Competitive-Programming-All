#include <bits/stdc++.h>
using namespace std;

// গ্লোবাল ভ্যারিয়েবল
vector<long long> parent, sz;
vector<long long> population; 
multiset<long long> regions_population; // সব অঞ্চলের পপুলেশন ট্র্যাক করার জন্য

// DSU এর makeSet
void makeSet(int n) {
    parent.resize(n + 1);
    sz.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = population[i]; // শুরুতে প্রতিটি শহর একটি আলাদা অঞ্চল
        regions_population.insert(sz[i]);
    }
}

// DSU এর findParent (Path Compression সহ)
int findParent(int v) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v]);
}


// DSU এর union (পপুলেশন মার্জ করার জন্য)
void unionSets(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (u != v) {
        // আগের ছোট অঞ্চল দুটির পপুলেশন multiset থেকে মুছে ফেলা
        regions_population.erase(regions_population.find(sz[u]));
        regions_population.erase(regions_population.find(sz[v]));
        
        // বড়টার সাথে ছোটটা যোগ করা
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        
        // নতুন বড় অঞ্চলের পপুলেশন ইনসার্ট করা
        regions_population.insert(sz[u]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q;
    cin >> N >> M >> Q;

    population.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> population[i];

    vector<pair<int, int>> roads(M + 1);
    for (int i = 1; i <= M; i++) cin >> roads[i].first >> roads[i].second;

    vector<pair<char, pair<int, long long>>> queries(Q + 1);
    vector<bool> road_removed(M + 1, false);
    vector<long long> current_pop = population; // বর্তমান পপুলেশন ট্র্যাক করতে

    for (int i = 1; i <= Q; i++) {
        cin >> queries[i].first;
        if (queries[i].first == 'D') {
            cin >> queries[i].second.first;
            road_removed[queries[i].second.first] = true;
        } else {
            int town; long long new_p;
            cin >> town >> new_p;
            queries[i].second = {town, current_pop[town]}; // আগের পপুলেশন সেভ করে রাখা
            current_pop[town] = new_p;
        }
    }

    // কোয়েরি শেষে শহরের পপুলেশন যা দাঁড়ালো তা দিয়ে DSU শুরু করা
    population = current_pop;
    makeSet(N);

    // যে রাস্তাগুলো কখনো ডিলিট হয়নি বা শেষে অবশিষ্ট আছে সেগুলো কানেক্ট করা
    for (int i = 1; i <= M; i++) {
        if (!road_removed[i]) {
            unionSets(roads[i].first, roads[i].second);
        }
    }

    // পেছন দিক থেকে কোয়েরি প্রসেস করা (Reverse Processing)
    vector<long long> results;
    for (int i = Q; i >= 1; i--) {
        results.push_back(*regions_population.rbegin()); // বর্তমান সর্বোচ্চ পপুলেশন

        if (queries[i].first == 'D') {
            int road_idx = queries[i].second.first;
            unionSets(roads[road_idx].first, roads[road_idx].second);
        } else {
            int town = queries[i].second.first;
            long long old_p = queries[i].second.second;
            
            int root = findParent(town);
            // multiset থেকে এই অঞ্চলের পুরনো পপুলেশন রিমুভ করা
            regions_population.erase(regions_population.find(sz[root]));
            
            // পপুলেশন আপডেট
            sz[root] -= population[town]; // বর্তমানটা বাদ
            population[town] = old_p;      // আগেরটায় ফেরত যাওয়া
            sz[root] += population[town]; // আগেরটা যোগ
            
            regions_population.insert(sz[root]);
        }
    }

    // উল্টো করে রেজাল্ট প্রিন্ট করা
    for (int i = Q - 1; i >= 0; i--) {
        cout << results[i] << "\n";
    }

    return 0;
}