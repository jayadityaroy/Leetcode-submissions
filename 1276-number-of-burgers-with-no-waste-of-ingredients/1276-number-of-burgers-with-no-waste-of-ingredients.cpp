class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        //vector<int> ans;
        if(tomatoSlices % 2 != 0 || tomatoSlices < cheeseSlices) return {};
        int jumboBurgers = 0, smallBurgers = 0;
        // jumbo burger count + small burger count == cheeseSlices
        // 4(jumbo burger count) + 2(small burger count) == tomatoSlices
        jumboBurgers = (tomatoSlices - 2*cheeseSlices) / 2;
        smallBurgers = cheeseSlices - jumboBurgers;
        if(jumboBurgers < 0 || smallBurgers < 0) return {};
        return {jumboBurgers, smallBurgers};
    }
};