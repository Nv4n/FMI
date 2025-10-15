package exam;

public class TimeServerInterfaceImpl implements TimeServerInterface {
    @Override
    public Time setupClock(String clockName) {
        Time time = new Time();
        time.setCurrentTime();
        System.out.printf("%s is setup%n", clockName);
        return time;
    }
}
