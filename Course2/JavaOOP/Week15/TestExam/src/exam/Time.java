package exam;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Time implements Runnable {
    private int timezone;
    private int hours;
    private int minutes;
    private int seconds;

    public Time() {
        this(0, 0, 0, 0);
    }

    public Time(int timezone, int hours, int minutes, int seconds) {
        setTimezone(timezone);
        setHours(hours);
        setMinutes(minutes);
        setSeconds(seconds);
    }

    public Time(Time other) {
        this(other.getTimezone(), other.getHours(), other.getMinutes(), other.getSeconds());
    }

    final public int getTimezone() {
        return timezone;
    }

    final public void setTimezone(int timezone) {
        if (timezone >= -12 && timezone <= 13) this.timezone = timezone;
        else this.timezone = 0;
    }

    final public int getHours() {
        return hours;
    }

    final public void setHours(int hours) {
        this.hours = hours >= 0 && hours <= 23 ? hours : 0;
    }

    final public int getMinutes() {
        return minutes;
    }

    final public void setMinutes(int minutes) {
        this.minutes = minutes >= 0 && minutes <= 59 ? minutes : 0;
    }

    final public int getSeconds() {
        return seconds;
    }

    final public void setSeconds(int seconds) {
        this.seconds = seconds >= 0 && seconds <= 59 ? seconds : 0;
    }

    final public void setTime(Time t) {
        if (t == null) return;

        setTimezone(t.getTimezone());
        setHours(t.getHours());
        setMinutes(t.getMinutes());
        setSeconds(t.getSeconds());
    }

    final public Time getTime() {
        return new Time(this);
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d:%02d TZ:%02d",
                hours, minutes, seconds, timezone);
    }

    public void setCurrentTime() {
        GregorianCalendar currentTime = new GregorianCalendar();
        hours = currentTime.get(Calendar.HOUR_OF_DAY);
        minutes = currentTime.get(Calendar.MINUTE);
        seconds = currentTime.get(Calendar.SECOND);
    }

    public void tickSecond() {
        seconds++;
        if (seconds < 60) return;

        seconds = 0;
        minutes++;
        if (minutes < 60) return;

        minutes = 0;
        hours++;
        if (hours >= 24) hours = 0;
    }

    @Override
    public void run() {

    }
}
