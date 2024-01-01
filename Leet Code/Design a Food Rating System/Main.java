import java.util.HashMap;
import java.util.Objects;
import java.util.TreeSet;

class FoodRatings {
    HashMap<String, TreeSet<Food>> highestCuisineRatings = new HashMap<>();
    HashMap<String, Food> foodMap = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; i++) {
            Food food = new Food(foods[i], cuisines[i], ratings[i]);
            foodMap.put(food.name, food);

            if (!highestCuisineRatings.containsKey(food.cuisine)) {
                highestCuisineRatings.put(food.cuisine, new TreeSet<>());
            }
            highestCuisineRatings.get(food.cuisine).add(food);
        }
    }

    public void changeRating(String food, int newRating) {
        Food foodObj = foodMap.get(food);
        TreeSet<Food> foodTreeSet = highestCuisineRatings.get(foodObj.cuisine);
        foodTreeSet.remove(foodObj);

        foodObj.rating = newRating;

        foodTreeSet.add(foodObj);
    }

    public String highestRated(String cuisine) {
        return highestCuisineRatings.get(cuisine).first().name;
    }

    static class Food implements Comparable<Food> {
        String name;
        String cuisine;
        int rating;

        public Food(String name, String cuisine, int rating) {
            this.name = name;
            this.cuisine = cuisine;
            this.rating = rating;
        }

        @Override
        public int hashCode() {
            return (name).hashCode();
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Food food)) return false;
            return Objects.equals(name, food.name);
        }

        @Override
        public int compareTo(Food other) {
            if (other.equals(this))
                return 0;

            if (rating == other.rating) {
                return name.compareTo(other.name);
            }
            return Integer.compare(other.rating, rating);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        String[] foods = {"czopaaeyl", "lxoozsbh", "kbaxapl"};
        String[] cuisines = {"dmnuqeatj", "dmnuqeatj", "dmnuqeatj"};
        int[] ratings = {11, 2, 15};
        FoodRatings foodRatings = new FoodRatings(foods, cuisines, ratings);

        foodRatings.changeRating("czopaaeyl", 12);

        System.out.println(foodRatings.highestRated("dmnuqeatj"));

        foodRatings.changeRating("kbaxapl", 8);

        foodRatings.changeRating("lxoozsbh", 5);

        System.out.println(foodRatings.highestRated("dmnuqeatj"));
    }
}