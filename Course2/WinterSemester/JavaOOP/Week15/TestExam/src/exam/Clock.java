package exam;

import javafx.application.Platform;

import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadPoolExecutor;

public class Clock extends javafx.scene.layout.Pane implements Runnable {
    private Time time;

    public Clock() {
        this.time = new Time();
        Thread thread = new Thread(this);
        thread.setDaemon(true);
    }

    void setClock(Time newTime) {
        time.setTime(newTime);
    }

    @Override
    public void run() {
        while (true) {
            time.tickSecond();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ignored) {

            }
        }
    }

    public void stopClock() {
        Thread.currentThread().interrupt();
    }

    public void startClock() {
        time.setCurrentTime();
        Thread.currentThread().start();
    }
}
