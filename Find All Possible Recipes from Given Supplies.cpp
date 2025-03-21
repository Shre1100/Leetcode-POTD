// You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.
// You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
// Return a list of all the recipes that you can create. You may return the answer in any order.
// Note that two recipes may contain each other in their ingredients.

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> available_supplies(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> ingredient_to_recipes;
        unordered_map<string, int> in_degree;
        unordered_map<string, vector<string>> recipe_to_ingredients;

        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            recipe_to_ingredients[recipe] = ingredients[i];
            in_degree[recipe] = ingredients[i].size();

            for (const string& ingredient : ingredients[i]) {
                ingredient_to_recipes[ingredient].push_back(recipe);
            }
        }

        queue<string> q;
        for (const string& supply : supplies) {
            q.push(supply);
        }

        vector<string> result;

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (recipe_to_ingredients.find(current) != recipe_to_ingredients.end()) {
                result.push_back(current);
            }

            if (ingredient_to_recipes.find(current) != ingredient_to_recipes.end()) {
                for (const string& dependent_recipe : ingredient_to_recipes[current]) {
                    in_degree[dependent_recipe]--;
                    if (in_degree[dependent_recipe] == 0) {
                        q.push(dependent_recipe);
                    }
                }
            }
        }

        return result;
    }
};
