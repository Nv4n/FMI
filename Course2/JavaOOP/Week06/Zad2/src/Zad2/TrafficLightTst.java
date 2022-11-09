package Zad2;

public class TrafficLightTst {
    public enum TrafficLight {
        RED(3000),
        YELLOW(2000),
        GREEN(4000);

        private final int duration;

        TrafficLight(int duration) {
            this.duration = duration > 0 ? duration : 1000;
        }

        public int getDuration() {
            return duration;
        }
    }

    public static void main(String[] args) {
        TrafficLight[] trafficLights = TrafficLight.values();
        long startMilliseconds = System.currentTimeMillis();
        long prevMilliseconds = startMilliseconds;

        for (int i = 0; i < trafficLights.length; ) {
            System.out.println(trafficLights[i].name());
            long currMilliseconds = System.currentTimeMillis();

            while (currMilliseconds - prevMilliseconds <= trafficLights[i].getDuration()) {
                currMilliseconds = System.currentTimeMillis();
                if (currMilliseconds - startMilliseconds >= 90000)
                    System.exit(0);
            }

            prevMilliseconds = currMilliseconds;
            i++;

        }
    }
}
