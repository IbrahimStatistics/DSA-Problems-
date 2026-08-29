class StockSpanner {
public:
    stack<int> s;
    vector<int> price;

    StockSpanner() {
        
    }
    
    int next(int p) {
        price.push_back(p);

        int i = price.size() - 1;

        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }

        int ans;

        if (s.empty()) {
            ans = i + 1;
        } else {
            ans = i - s.top();
        }

        s.push(i);

        return ans;
    }
};

    /**
    * Your StockSpanner object will be instantiated and called as such:
    * StockSpanner* obj = new StockSpanner();
    * int param_1 = obj->next(price);
    */