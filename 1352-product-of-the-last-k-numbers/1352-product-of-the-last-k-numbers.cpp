class ProductOfNumbers {
private:
    vector<int> prefix;
public:
    ProductOfNumbers() {
        prefix.clear();
    }
    
    void add(int num) {
        if(num == 0){
            prefix.clear(); // reset the prefix
        }
        else if(prefix.empty()){
            prefix.push_back(num);
        }
        else{
            prefix.push_back(prefix.back()*num);
        }
    }
    
    int getProduct(int k) {
        if(k > prefix.size()) return 0; 
        else if(k == prefix.size()) return prefix.back();
        else return (prefix.back() / prefix[prefix.size() - 1 - k ]);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */