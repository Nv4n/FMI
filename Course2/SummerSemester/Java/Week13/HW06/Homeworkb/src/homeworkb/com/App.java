package homeworkb.com;

import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.dataformat.xml.XmlMapper;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

public class App {
    private static class Food {
        private String name;
        private String price;
        private String description;
        private String calories;

        public Food(String name, String price, String description, String calories) {
            this.name = name;
            this.price = price;
            this.description = description;
            this.calories = calories;
        }

        public Food() {
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getPrice() {
            return price;
        }

        public void setPrice(String price) {
            this.price = price;
        }

        public String getDescription() {
            return description;
        }

        public void setDescription(String description) {
            this.description = description;
        }

        public String getCalories() {
            return calories;
        }

        public void setCalories(String calories) {
            this.calories = calories;
        }

    }

    public static class FoodAnnotated {
        @JsonProperty("name")
        private String name;
        @JsonProperty("price")

        private String price;
        @JsonProperty("description")

        private String description;
        @JsonProperty("calories")

        private String calories;

        public FoodAnnotated(String name, String price, String description, String calories) {
            this.name = name;
            this.price = price;
            this.description = description;
            this.calories = calories;
        }

        public FoodAnnotated() {
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getPrice() {
            return price;
        }

        public void setPrice(String price) {
            this.price = price;
        }

        public String getDescription() {
            return description;
        }

        public void setDescription(String description) {
            this.description = description;
        }

        public String getCalories() {
            return calories;
        }

        public void setCalories(String calories) {
            this.calories = calories;
        }
    }

    private static class BreakfastMenu {
        private Food[] foods;

        public BreakfastMenu(Food[] foods) {
            this.foods = foods;
        }

        public BreakfastMenu() {
        }

        public Food[] getFoods() {
            return foods;
        }

        public void setFoods(Food[] foods) {
            this.foods = foods;
        }
    }

    private static class BreakfastMenuAnnotated {
        private Food[] foods;

        public BreakfastMenuAnnotated(Food[] foods) {
            this.foods = foods;
        }

        public BreakfastMenuAnnotated() {
        }

        public Food[] getFoods() {
            return foods;
        }

        public void setFoods(Food[] foods) {
            this.foods = foods;
        }
    }

    public static void main(String[] args) {
        try {
            XmlMapper xmlMapper = new XmlMapper();
            String readContent = new String(Files.readAllBytes(Paths.get("breakfast_menu.xml")));
            Food deserializedData = xmlMapper.readValue(readContent, Food.class);
            System.out.println(deserializedData.toString());

        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

}

