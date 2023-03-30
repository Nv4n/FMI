package Task07;

import javafx.application.Platform;
import javafx.beans.value.ObservableValue;
import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;

import java.net.URL;
import java.util.Random;
import java.util.ResourceBundle;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Controller {

    private static Task<Boolean> copyWorker;
    private final int numFiles = 30;
    private ExecutorService threadPool;

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private ProgressBar barPgr;

    @FXML
    private Button cancelBtn;

    @FXML
    private ProgressIndicator indicatorPgr;

    @FXML
    private Button startBtn;

    @FXML
    private TextArea txtArea;

    @FXML
    public void initialize() {
        assert barPgr != null : "fx:id=\"barPgr\" was not injected: check your FXML file 'BGProcessScene.fxml'.";
        assert cancelBtn != null : "fx:id=\"cancelBtn\" was not injected: check your FXML file 'BGProcessScene.fxml'.";
        assert indicatorPgr != null : "fx:id=\"indicatorPgr\" was not injected: check your FXML file 'BGProcessScene.fxml'.";
        assert startBtn != null : "fx:id=\"startBtn\" was not injected: check your FXML file 'BGProcessScene.fxml'.";
        assert txtArea != null : "fx:id=\"txtArea\" was not injected: check your FXML file 'BGProcessScene.fxml'.";

        threadPool = Executors.newFixedThreadPool(10);
    }

    public void shutdown() {
        threadPool.shutdown();
    }

    private Task<Boolean> createWorker(final int numFiles) {
        return new Task<Boolean>() {
            @Override
            protected Boolean call() throws Exception {
                for (int i = 0; i < numFiles; i++) {
                    long elapsedTime = System.currentTimeMillis();
                    copyFile("some file", "some dest file");
                    elapsedTime = System.currentTimeMillis() - elapsedTime;
                    String status = elapsedTime + " milliseconds";
                    // queue up status
                    updateMessage(status);
                    updateProgress(i + 1, numFiles); // (progress, max)
                }
                return true;
            }
        };
    }

    private void copyFile(String src, String dest) throws InterruptedException {
        // simulate a long time
        Random rnd = new Random(System.currentTimeMillis());
        long millis = rnd.nextInt(1000);
        Thread.sleep(millis);
    }


    public void startProcess(ActionEvent actionEvent) {
        startBtn.setDisable(true);
        barPgr.setProgress(0);
        indicatorPgr.setProgress(0);
        txtArea.setText("");
        cancelBtn.setDisable(false);
        copyWorker = createWorker(numFiles);
        // wire up progress bar
        barPgr.progressProperty().unbind();
        barPgr.progressProperty().bind(copyWorker.progressProperty());
        indicatorPgr.progressProperty().unbind();
        indicatorPgr.progressProperty().bind(copyWorker.progressProperty());
        // append to text area box
        copyWorker.messageProperty().addListener((ObservableValue<? extends String>
                                                          observable, String oldValue, String newValue) -> {
            txtArea.appendText(newValue + "\n");
        });
        threadPool.submit(copyWorker);

    }

    public void cancelProcess(ActionEvent actionEvent) {
        startBtn.setDisable(false);
        cancelBtn.setDisable(true);
        copyWorker.cancel(true);
        // reset
        barPgr.progressProperty().unbind();
        barPgr.setProgress(0);
        indicatorPgr.progressProperty().unbind();
        indicatorPgr.setProgress(0);
        txtArea.appendText("File transfer was cancelled.");
    }
}
