package Lab13.Zad3.withThread;

import javafx.application.Platform;
import Lab13.Zad3.ClockPane;


public class ClockAnimationsWithThread extends ClockPane
        implements Runnable {

    public ClockAnimationsWithThread() {
        Thread t = new Thread(this);
        t.setDaemon(true);// stop the thread when JavaFX exits
        t.start();
    }

    public void run() {
        while (true) {
            Platform.runLater(this::setCurrentTime);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ignored) {
            }
        }
    }

}
