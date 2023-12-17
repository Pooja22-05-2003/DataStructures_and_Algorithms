// TC=O(N)
// SC=O(3n)=O(n)
class FoodRatings {
    unordered_map<string,set<pair<int,string>>> cousine_rating_food;
    unordered_map<string,int> food_rating;
    unordered_map<string,string> food_cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            string curr_cuisines=cuisines[i];
            int curr_rating=ratings[i];
            string curr_food=foods[i];

            cousine_rating_food[curr_cuisines].insert({-curr_rating ,curr_food });
            food_rating[curr_food]=curr_rating;
            food_cuisine[curr_food]=curr_cuisines;
        }
    }
    
    void changeRating(string food, int newRating) {
        int prev_rating=food_rating[food];
        food_rating[food]=newRating;

        cousine_rating_food[food_cuisine[food]].erase({-prev_rating,food});
        cousine_rating_food[food_cuisine[food]].insert({-newRating,food});

    }
    
    string highestRated(string cuisine) {
        return cousine_rating_food[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */