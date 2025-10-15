package server;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Hashtable;
import java.util.Set;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Server extends Application {

    private TextField txtInputLink;
    private TextArea txaChatText;

    private ExecutorService threadExecutor;
    private ServerSocket server;
    private int counter = 1;
    private Hashtable<Thread, ObjectOutputStream> writers;

    /*  Mode to RunClient ****************
    private ObjectOutputStream output; // output stream to client
    private ObjectInputStream input; // input stream from client
    private Socket connection; // connection to client
    Hashtable is threadsafe because the get, put, contains methods,
    etc. are synchronized. Furthermore, Several threads will not
    be able to access the hashtable at the same time, regardless
    of which entries they are modifying */
    // set up GUI
    @Override
    public void start(Stage primaryStage) {

        writers = new Hashtable<>();
        threadExecutor = Executors.newCachedThreadPool();
        VBox root = new VBox();
        root.setAlignment(Pos.TOP_CENTER);
        root.setPadding(new Insets(14));
        root.setSpacing(8);
        txtInputLink = new TextField();
        txtInputLink.setPromptText("Type text");
        txaChatText = new TextArea();
        txtInputLink.setOnAction(event -> {
                    sendData(txtInputLink.getText());
                    txtInputLink.setText("");
                }
        );
        txtInputLink.setEditable(false);

        txaChatText.setMaxSize(1.7976931348623157E308, 1.7976931348623157E308);
        root.getChildren().addAll(txtInputLink, txaChatText);
        Scene scene = new Scene(root, 350, 250, Color.web("#666970"));

        primaryStage.setOnCloseRequest(evt -> stop());
        primaryStage.setTitle("Server");
        primaryStage.setScene(scene);
        primaryStage.show();
        // start the server in a separate Thread
        new Thread(this::runServer).start();
    }

    public class RunClient implements Runnable {

        private ObjectOutputStream output;
        private ObjectInputStream input;
        private final Socket connection;
        private final int counter;

        public RunClient(Socket connection, int counter) {

            this.connection = connection;
            this.counter = counter;

        }

        private void getStreams() throws IOException {
            output = new ObjectOutputStream(connection.getOutputStream());
            output.flush();

            input = new ObjectInputStream(connection.getInputStream());
            writers.put(Thread.currentThread(), output);

            if (writers.size() == 1) setTextFieldEditable(true);

            displayMessage("\nGot I/O streams\n");

        }

        @Override
        public void run() {

            displayMessage("Connection " + counter + " received from: "
                    + connection.getInetAddress().getHostName());

            try {
                getStreams();
                processConnection();
            } catch (EOFException eofException) {
                displayMessage("\nServer terminated connection");
            } catch (IOException ex) {
                displayMessage("\nClient terminated connection");
            } finally {
                closeConnection();

            }

        }


        private void processConnection() throws IOException {
            String message = "\nSERVER>>> Connection successful";
            output.writeObject(message);
            displayMessage(message);
            displayMessage("\nSERVER>>> Waiting for new connection\n");
            do try {
                message = (String) input.readObject();
                displayMessage("\n" + message);
            } catch (ClassNotFoundException classNotFoundException) {
                displayMessage("\nUnknown object type received");
            }
            while (!message.equals("CLIENT>>> TERMINATE"));
        }

        private void closeConnection() {
            displayMessage("\nTerminating connection No." + this.counter + "\n");
            try {
                if (output != null) output.close();
                if (output != null) writers.remove(Thread.currentThread());
                if (input != null) input.close();
                if (connection != null) connection.close();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }

            if (writers.size() == 0) setTextFieldEditable(false);
        }
    }

    public void runServer() {

        try {
            server = new ServerSocket(12345, 100);
            displayMessage("Waiting for connection\n");

            while (true) waitForConnection();
        } catch (IOException ioException) {
            ioException.printStackTrace();
        }
    }

    private void waitForConnection() throws IOException {

        Socket s = server.accept();

        RunClient client = new RunClient(s, counter);
        threadExecutor.execute(client);

        counter++;
    }

    private void sendData(String message) {
        try {
            displayMessage("\nSERVER>>> " + message);
            Set<Thread> threads = writers.keySet();
            for (Thread thread : threads) {
                writers.get(thread).writeObject("SERVER>>> " + message);
                writers.get(thread).flush(); // flush output to client

            }
        } catch (IOException ioException) {
            txaChatText.appendText("\nError writing object");
        }
    }

    private void displayMessage(final String messageToDisplay) {
        Platform.runLater(() -> txaChatText.appendText(messageToDisplay));
    }

    private void setTextFieldEditable(final boolean editable) {
        Platform.runLater(() -> txtInputLink.setEditable(editable));
    }

    @Override
    public void stop() {
        Platform.exit();
        threadExecutor.shutdown();
        System.exit(0);
    }

    public static void main(String[] args) {
        Application.launch(args);
    }

}
