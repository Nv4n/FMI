package exam;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Objects;
import java.util.UUID;

public class TimeClient extends Application {
    @FXML
    public GridPane mainPane;
    private Clock clock;

    private TimeServerInterface remoteTime;
    private UUID uuid;

    private ServerSocket server;
    private Socket connection;
    private ObjectOutputStream output;
    private ObjectInputStream input;

    @Override
    public void start(Stage stage) throws Exception {
        //Design
        Parent root
                = FXMLLoader.load(Objects.requireNonNull(getClass().getResource("JfxScene.fxml")));
        clock = new Clock();
        uuid = UUID.randomUUID();
        //Add to pane
        mainPane.getChildren().add(clock);
        Scene scene = new Scene(root);

        // Set the Window title
//        stage.setOnCloseRequest(e -> stop());
        stage.setTitle(uuid.toString());
        stage.sizeToScene();
        stage.resizableProperty().setValue(Boolean.FALSE);
        stage.setScene(scene);
        stage.show();
//        Thread thread = new Thread(this::runServer);
//        thread.start();

    }

    public static void main(String[] args) {
        launch(args);
    }

    public void stop() {
        Platform.exit();
        System.exit(0);
    }

    public void runServer() {
        try {
            server = new ServerSocket(1099, 100);

            while (true) {
                try {
                    waitForConnection();
                    getStream();
                } catch (EOFException eofException) {
                    displayMessage("\nServer terminated connection");
                } finally {
                    closeConnection();
                }
            }

        } catch (IOException ioException) {
            ioException.printStackTrace();
        }
    }

    public void waitForConnection() throws IOException {
        displayMessage("Waiting for connection\n");
        connection = server.accept();
        displayMessage("Connection received from: " + connection.getInetAddress().getHostName());
    }

    private void closeConnection() {
        try {
            if (output != null) output.close();
            if (input != null) input.close();
            if (connection != null) connection.close();
        } catch (IOException ignored) {

        }
    }

    private void displayMessage(String s) {
        Platform.runLater(() -> System.out.println(s));
    }

    private void getStream() throws IOException {
        output = new ObjectOutputStream(connection.getOutputStream());
        output.flush();
        input = new ObjectInputStream(connection.getInputStream());
        displayMessage("\nGot I/O streams\n");
    }
}